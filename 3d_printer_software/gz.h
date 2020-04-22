void passoZsemContabilizar(boolean a,int tempo);
String gz(char* parametros){
  while (parametros != 0)
  {
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  int quantidade_passos = 200;
  boolean sentido = true;
  int tempo_ms = 3000;

  for(int x = 0 ; x < quantidade_passos ; x++ ){
    passoZsemContabilizar(sentido, tempo_ms/quantidade_passos);
  }
  delay(2000);
  eixoZ(true,10);
  eixoZ(true,10);
  String retorno = "ok";
  return retorno;
}



void passoZsemContabilizar(boolean a,int tempo){
  if(tempo<2)tempo=2;
  if(a){
    eixoZdir(1);
  }
  else{
    eixoZdir(0);
  }
  eixoZstep(0);
  delay(tempo/2);
  eixoZstep(1);
  delay(tempo/2);
}
