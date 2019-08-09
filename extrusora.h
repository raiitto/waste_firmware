#define extrusora_motor_pin 13

float tamanho_passo_extrusora = 0.25;

void setup_extrusora(){
  pinMode(extrusora_motor_pin, OUTPUT);
}

void step_extrusora(int tempo){
  if(tempo<2)tempo=2;
  digitalWrite(eixoXstep,0);
  delay(tempo/2);
  digitalWrite(eixoXstep,1);
  delay(tempo/2);
}

void extrudar(float milimetros, int tempo){
  if(milimetros<=0){
    delay(tempo);
    return;
  }
  int passos = milimetros/tamanho_passo_extrusora;
  int tempo_por_passo = (tempo/passos);
  for(int x = 0;x<passos;x++){
    step_extrusora(tempo_por_passo);
  }
}
