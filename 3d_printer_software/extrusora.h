#define extrusora_motor_pin_step 5
#define extrusora_motor_pin_dir 6


float circunferencia_mm = 31.42;
float tamanho_passo_extrusora = circunferencia_mm/400;

void setup_extrusora(){
  pinMode(extrusora_motor_pin_dir, OUTPUT);
  pinMode(extrusora_motor_pin_step, OUTPUT);
}

void step_extrusora(boolean a, int tempo){
  if(tempo<2)tempo=2;
  if(a){
    digitalWrite(extrusora_motor_pin_dir,HIGH);
    g_cordenada_extruder+=tamanho_passo_extrusora;
  }
  else{
    digitalWrite(extrusora_motor_pin_dir,LOW);
    g_cordenada_extruder-=tamanho_passo_extrusora;
  }
  
  if(!(x_passos_coordenada<0||x_passos_coordenada>maxX||
     y_passos_coordenada<0||y_passos_coordenada>maxY||
     z_passos_coordenada<0||z_passos_coordenada>maxZ)){
    //digitalWrite(extrusora_motor_pin_step,0);
  }
  digitalWrite(extrusora_motor_pin_step,0);
  delay(tempo/2);
  delay(10);
  digitalWrite(extrusora_motor_pin_step,1);
  delay(tempo/2);
}

float milimetros_adiantados_pra_frente = 0;
float milimetros_adiantados_pra_tras = 0;

float ao_zerar = 0;

void extrudar(float milimetros, int tempo){
//  if(milimetros<0){
//    //Ignorar Movimentos no sentido contrario
//    delay(tempo);
//    ao_zerar = -milimetros;
//    return;
//    //Ignorar Movimentos no sentido contrario
//  }
  ao_zerar=0;
  if(milimetros==0||x_passos_coordenada>maxX||y_passos_coordenada>maxY||z_passos_coordenada>maxZ||
  x_passos_coordenada<0||y_passos_coordenada<0||z_passos_coordenada<0){
    delay(tempo);
    return;
  }
  boolean direcao = true;
  int passos = milimetros/tamanho_passo_extrusora;
  if(abs(passos)>0&&fabs(milimetros)>0){
    milimetros_adiantados_pra_frente = 0;
    milimetros_adiantados_pra_tras = 0;
  }
  if(milimetros_adiantados_pra_frente>0){
    if(milimetros>0){
      milimetros_adiantados_pra_frente-=milimetros;
      if(milimetros_adiantados_pra_frente<=0&&passos==0){
        milimetros=0-milimetros_adiantados_pra_frente;
      }
    }else{
      milimetros_adiantados_pra_frente=0;
    }
  }
  if(milimetros_adiantados_pra_tras>0){
    if(milimetros<0){
      milimetros_adiantados_pra_tras-=fabs(milimetros);
      if(milimetros_adiantados_pra_frente<=0&&passos==0){
        milimetros=milimetros_adiantados_pra_frente;
      }
    }else{
      milimetros_adiantados_pra_tras=0;
    }
  }
  if(milimetros>0&&passos==0&&milimetros_adiantados_pra_frente<=0){
    milimetros_adiantados_pra_frente=tamanho_passo_extrusora-milimetros;
    passos=1;
  }
  if(milimetros<0&&passos==0&&milimetros_adiantados_pra_tras<=0){
    milimetros_adiantados_pra_tras=tamanho_passo_extrusora-fabs(milimetros);
    passos=1;
  }
  if(milimetros<0){
    passos = abs(passos);
    direcao = false;
  }
  int tempo_por_passo = (tempo/passos);
  for(int x = 0;x<passos;x++){
    step_extrusora(direcao,tempo_por_passo);
  }
}
