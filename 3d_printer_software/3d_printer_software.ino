#include "constantes.h"
#include "variaveis.h"

#include "eixos.h"
#include "aquecedores.h"
#include "extrusora.h"

#include "movimento.h"
#include "g1.h"
#include "g4.h"
#include "g20.h"
#include "g21.h"
#include "g28.h"
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
  setup_eixos();
  setup_extrusora();
  Serial.println("Pronto!");
}

  int tamanho = 0;
void loop() {
  loop_aquecedores();
  boolean pronto=false;
  char* buff= new char[101];
  tamanho=0;
  
  while(tamanho<100){
    loop_aquecedores();
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
    char* comando = strtok(buff, " ");
    String retorno = "";
    char* parametro;
    while (comando != 0)
    {
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
      }else{
        retorno = "ok";
      }
      comando = strtok(0, " ");//Encontrar o proximo parametro
    }
    Serial.println(retorno);// can be ok, rs or !!.   ok, resend, hardware error
  }
  delay(10);
  free(buff);
}
