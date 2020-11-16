#include "constantes.h"
#include "variaveis.h"

#include "end_stop.h"
#include "driver_motores.h"
#include "eixos.h"
#include "aquecedores.h"
#include "extrusora.h"

#include "movimento.h"
#include "gz.h"
#include "g1.h"
#include "g4.h"
#include "g20.h"
#include "g21.h"
#include "g28.h"
#include "g90.h"
#include "g91.h"
#include "g92.h"
#include "m82.h"
#include "m83.h"
#include "m104.h"
#include "m105.h"
#include "m106.h"
#include "m107.h"
#include "m109.h"
#include "m140.h"
#include "m190.h"
#include "m999.h"




void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println("Iniciando...");
  setup_aquecedores();
  setup_driver();
  setup_eixos();
  setup_end_stop();
  Serial.println("tamanhos dos passos");
  Serial.print("X:");
  Serial.print(tamanho_passo_eixo_x*1000);
  Serial.println("µm");
  Serial.print("Y:");
  Serial.print(tamanho_passo_eixo_y*1000);
  Serial.println("µm");
  Serial.print("Z:");
  Serial.print(tamanho_passo_eixo_z*1000);
  Serial.println("µm");
  Serial.print("Estrusora:");
  Serial.print(tamanho_passo_extrusora*1000);
  Serial.println("µm");
  setup_extrusora();
  Serial.println("Pronto!");
}

  int tamanho = 0;
  unsigned long time_aquecedores = 0;
void loop() {
  if(millis()-time_aquecedores>10){
    loop_aquecedores();
    time_aquecedores = millis();
  }
  boolean pronto=false;
  char* buff= new char[101];
  tamanho=0;
  
  while(tamanho<100){
    if(millis()-time_aquecedores>10){
      loop_aquecedores();
      time_aquecedores = millis();
    }
    if(Serial.available()){
      byte leitura = Serial.read();
      if(leitura =='^'){
        break;
      }else if(leitura == '\n'){
        break;
      }
      buff[tamanho]=leitura;
      tamanho++;
    //Serial.print(".");
    }
  }
  buff[tamanho]=0;
  pronto=true;
  if(pronto){
    // Read each command pair 
    char* comando = strtok(buff, " *");
    String retorno = "ok";
    char* parametro;
    while (comando != 0)
    {
      if(millis()-time_aquecedores>10){
        loop_aquecedores();
        time_aquecedores = millis();
      }
      //Serial.println("@");
      if(comando_g0.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g1(parametro);
      }else if(comando_g1.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g1(parametro);
      }else if(comando_g4.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g4(parametro);
      }else if(comando_g20.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g20(parametro);
      }else if(comando_g21.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g21(parametro);
      }else if(comando_g28.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g28(parametro);
      }else if(comando_g90.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g90(parametro);
      }else if(comando_g91.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g91(parametro);
      }else if(comando_g92.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g92(parametro);
      }else if(comando_g92_1.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g92(parametro);
      }else if(comando_g92_2.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g92(parametro);
      }else if(comando_m82.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = m82(parametro);
      }else if(comando_m83.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = m83(parametro);
      }else if(comando_m104.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = m104(parametro);
      }else if(comando_m105.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = m105(parametro);
      }else if(comando_m106.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = m106(parametro);
      }else if(comando_m107.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = m107(parametro);
      }else if(comando_m109.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = m109(parametro);
      }else if(comando_m140.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = m140(parametro);
      }else if(comando_m190.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = m190(parametro);
      }else if(comando_m999.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = m999(parametro);
      }else if(comando_gz.equalsIgnoreCase(comando)){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = gz(parametro);
      }else{
        retorno = "ok";
      }
      comando = strtok(0, " *");//Encontrar o proximo parametro
    }
    Serial.println(retorno);// can be ok, rs or !!.   ok, resend, hardware error
  }else{
    String retorno = "ok";
    Serial.println(retorno);// can be ok, rs or !!.   ok, resend, hardware error
  }
  delay(10);
  free(buff);
}
