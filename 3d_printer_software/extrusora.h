#define extrusora_motor_pin_dir 7
#define extrusora_motor_pin_step 6

float tamanho_passo_extrusora = 0.25;

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
  digitalWrite(extrusora_motor_pin_step,0);
  delay(tempo/2);
  digitalWrite(extrusora_motor_pin_step,1);
  delay(tempo/2);
}

void extrudar(float milimetros, int tempo){
  if(milimetros==0||x_passos_coordenada>maxX||y_passos_coordenada>maxY||y_passos_coordenada>maxZ||
  x_passos_coordenada<0||y_passos_coordenada<0||y_passos_coordenada<0){
    delay(tempo);
    return;
  }
  boolean direcao = true;
  int passos = milimetros/tamanho_passo_extrusora;
  if(milimetros<0){
    passos = abs(passos);
    direcao = false;
  }
  int tempo_por_passo = (tempo/passos);
  for(int x = 0;x<passos;x++){
    step_extrusora(direcao,tempo_por_passo);
  }
}
