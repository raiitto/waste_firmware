#include "termistores.h"
#define pino_aquecedor_extrusora 2
#define pino_ventoinha_extrusora 3 
#define pino_aquecedor_base 4
#define pino_ventoinha_base -1
#define temperatura_maxima 300
#define tolerancia 2
#define maxima_exedencia_temperatura 1
#define tolerancia_refrigeracao 5

int temperatura_extrusora = 0;//Temperatura inicial
int temperatura_base = 0;

#define rele_on HIGH
#define rele_off LOW

boolean aquecedor_extrusora_ativado = false;
boolean aquecedor_base_ativado = false;

void ativar_extrusora(){
  aquecedor_extrusora_ativado = true;
}
void desativar_extrusora(){
  aquecedor_extrusora_ativado = false;
}

void ativar_base(){
  aquecedor_base_ativado = true;
}
void desativar_base(){
  aquecedor_base_ativado = false;
}

void setup_aquecedores(){
  pinMode(pino_aquecedor_extrusora, OUTPUT);
  pinMode(pino_ventoinha_extrusora, OUTPUT);
  pinMode(pino_aquecedor_base, OUTPUT);
  pinMode(pino_ventoinha_base, OUTPUT);
}

long ultima_leitura = 0;
int contador_leituras = 0;
float media_extrusora = 0;
float media_base = 0;
void loop_aquecedores(){
  if(contador_leituras==0){
    media_extrusora = 0;
    media_base = 0;
  }
  if(millis()-ultima_leitura>=10){
    float temp_extrusora = temperaturaExtrusora();
    float temp_base = temperaturaBase();
    ultima_leitura=millis();
    contador_leituras++;
    media_extrusora+=temp_extrusora/10;
    media_base+=temp_base/10;
  }
  if(contador_leituras<10){
    return;
  }else{
    contador_leituras=0;
  }

  if(aquecedor_extrusora_ativado==false){
    digitalWrite(pino_aquecedor_extrusora, rele_off);//Desligar tudo
    digitalWrite(pino_ventoinha_extrusora, rele_off);
  }else if(media_extrusora>=temperatura_maxima){
    digitalWrite(pino_aquecedor_extrusora, rele_off);
    digitalWrite(pino_ventoinha_extrusora, rele_on);
  }else if(media_extrusora>temperatura_extrusora+tolerancia_refrigeracao){
    digitalWrite(pino_aquecedor_extrusora, rele_off);
    digitalWrite(pino_ventoinha_extrusora, rele_on);
  }else if(media_extrusora>temperatura_extrusora+maxima_exedencia_temperatura){
    digitalWrite(pino_aquecedor_extrusora, rele_off);
    digitalWrite(pino_ventoinha_extrusora, rele_off);
  }else if(media_extrusora<temperatura_extrusora-tolerancia){
    digitalWrite(pino_aquecedor_extrusora, rele_on);
    digitalWrite(pino_ventoinha_extrusora, rele_off);
  }
  
  if(aquecedor_base_ativado==false){
    digitalWrite(pino_aquecedor_base, rele_off);//Desligar tudo
    digitalWrite(pino_aquecedor_base, rele_off);
  }else if(media_base>=temperatura_maxima){
    digitalWrite(pino_aquecedor_base, rele_off);
    digitalWrite(pino_ventoinha_base, rele_on);//Ligar ventoinha
  }else if(media_base>temperatura_base+tolerancia_refrigeracao){
    digitalWrite(pino_aquecedor_base, rele_off);
    digitalWrite(pino_ventoinha_base, rele_on);//Ligar ventoinha
  }else if(media_base>temperatura_base+maxima_exedencia_temperatura){
    digitalWrite(pino_aquecedor_base, rele_off);//Desligar aquecedor
    digitalWrite(pino_ventoinha_base, rele_off);
  }else if(media_base<temperatura_base-tolerancia){
    digitalWrite(pino_aquecedor_base, rele_on);//Ligar aquecedor
    digitalWrite(pino_ventoinha_base, rele_off);
  }
}

 
