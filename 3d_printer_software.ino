#include "eixos.h"
#include "aquecedores.h"
#include "extrusora.h"

#include "constantes.h"
#include "variaveis.h"
#include "movimento.h"
#include "g1.h"
#include "g4.h"
#include "g92.h"
#include "m17.h"
#include "m18.h"
#include "m300.h"




void setup() {
  setup_aquecedores();
  setup_eixos();
  setup_extrusora();
  digitalWrite(eixoZstep,1);
  Serial.begin(9600);
  
  delay(10);
}

  int tamanho = 0;
void loop() {
  boolean pronto=false;
  char* buff= new char[101];
  tamanho=0;
  
  while(tamanho<100){
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
      if(comando_g0.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g1(parametro);
      }else if(comando_g1.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g1(parametro);
      }else if(comando_g4.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        retorno = g4(parametro);
      }else if(comando_g92.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        //retorno = g92(parametro);
        retorno = "ok";
      }else if(comando_g92_1.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        //retorno = g92(parametro);
        retorno = "ok";
      }else if(comando_g92_2.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        //retorno = g92(parametro);
        retorno = "ok";
      }else if(comando_m0.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        //retorno = m0(parametro);
        retorno = "ok";
      }else if(comando_m104.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        //retorno = m104(parametro);
        retorno = "ok";
      }else if(comando_m109.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        //retorno = m109(parametro);
        retorno = "ok";
      }else if(comando_m140.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        //retorno = m140(parametro);
        retorno = "ok";
      }else if(comando_m190.indexOf(comando)>0){
        parametro = strtok(0, " ");//Encontrar o proximo parametro
        //retorno = m190(parametro);
        retorno = "ok";
      }else{
        retorno = "ok";
      }
        /* Split the command in two values
        char* separator = strchr(comando, ':');
        if (separator != 0)
        {
            // Actually split the string in 2: replace ':' with 0
            *separator = 0;
            int servoId = atoi(comando);
            ++separator;
            int position = atoi(separator);
    
            // Do something with servoId and position
        }
        */
    }
    Serial.println(retorno);// can be ok, rs or !!.   ok, resend, hardware error
  }
}
