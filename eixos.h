#define eixoXdir 7
#define eixoXstep 8
#define eixoYdir 9
#define eixoYstep 10
#define eixoZdir 11
#define eixoZstep 12

float tamanho_passo_eixo_x = 0.25;
float tamanho_passo_eixo_y = 0.25;
float tamanho_passo_eixo_z = 0.25;

void setup_eixos(){
  pinMode(eixoXdir, OUTPUT);
  pinMode(eixoXstep, OUTPUT);
  pinMode(eixoYdir, OUTPUT);
  pinMode(eixoYstep, OUTPUT);
  pinMode(eixoZdir, OUTPUT);
  pinMode(eixoZstep, OUTPUT);
}

void eixoX(boolean a,int tempo){
  if(tempo<2)tempo=2;
  if(a)
    digitalWrite(eixoXdir,0);
  else
    digitalWrite(eixoXdir,1);
  digitalWrite(eixoXstep,0);
  delay(tempo/2);
  digitalWrite(eixoXstep,1);
  delay(tempo/2);
}
void eixoY(boolean a,int tempo){
  if(tempo<2)tempo=2;
  if(a)
    digitalWrite(eixoYdir,0);
  else
    digitalWrite(eixoYdir,1);
  digitalWrite(eixoYstep,0);
  delay(tempo/2);
  digitalWrite(eixoYstep,1);
  delay(tempo/2);
}
void eixoZ(boolean a,int tempo){
  if(tempo<2)tempo=2;
  if(a)
    digitalWrite(eixoZdir,1);
  else
    digitalWrite(eixoZdir,0);
  digitalWrite(eixoZstep,0);
  delay(tempo/2);
  digitalWrite(eixoZstep,1);
  delay(tempo/2);
}
void eixoXY(boolean a, boolean b, int tempo){
  if(tempo<2)tempo=2;
  if(a)
    digitalWrite(eixoXdir,1);
  else
    digitalWrite(eixoXdir,0);
  if(b)
    digitalWrite(eixoYdir,1);
  else
    digitalWrite(eixoYdir,0);
  digitalWrite(eixoXstep,0);
  digitalWrite(eixoYstep,0);
  delay(tempo/2);
  digitalWrite(eixoXstep,1);
  digitalWrite(eixoYstep,1);
  delay(tempo/2);
}
void eixoXZ(boolean a, boolean b, int tempo){
  if(tempo<2)tempo=2;
  if(a)
    digitalWrite(eixoXdir,1);
  else
    digitalWrite(eixoXdir,0);
  if(b)
    digitalWrite(eixoZdir,1);
  else
    digitalWrite(eixoZdir,0);
  digitalWrite(eixoXstep,0);
  digitalWrite(eixoZstep,0);
  delay(tempo/2);
  digitalWrite(eixoXstep,1);
  digitalWrite(eixoZstep,1);
  delay(tempo/2);
}
void eixoYZ(boolean a, boolean b, int tempo){
  if(tempo<2)tempo=2;
  if(a)
    digitalWrite(eixoYdir,1);
  else
    digitalWrite(eixoYdir,0);
  if(b)
    digitalWrite(eixoZdir,1);
  else
    digitalWrite(eixoZdir,0);
  digitalWrite(eixoYstep,0);
  digitalWrite(eixoZstep,0);
  delay(tempo/2);
  digitalWrite(eixoYstep,1);
  digitalWrite(eixoZstep,1);
  delay(tempo/2);
}
void eixoXYZ(boolean a, boolean b, boolean c, int tempo){
  if(tempo<2)tempo=2;
  if(a)
    digitalWrite(eixoXdir,1);
  else
    digitalWrite(eixoXdir,0);
  if(b)
    digitalWrite(eixoYdir,1);
  else
    digitalWrite(eixoYdir,0);
  if(c)
    digitalWrite(eixoZdir,1);
  else
    digitalWrite(eixoZdir,0);
  digitalWrite(eixoXstep,0);
  digitalWrite(eixoYstep,0);
  digitalWrite(eixoZstep,0);
  delay(tempo/2);
  digitalWrite(eixoXstep,1);
  digitalWrite(eixoYstep,1);
  digitalWrite(eixoZstep,1);
  delay(tempo/2);
}
