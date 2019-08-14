String m105(char* parametros){
  int Rnnn = nao_iniciado;//Response sequence number1
  int Snnn = nao_iniciado;//Response type1
  while (parametros != 0)
  {
    String parametro = parametros;
    if(parametro.indexOf("R")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Rnnn=atoi(parametros);
    }else if(parametro.indexOf("S")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Snnn=atoi(parametros);
    }
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  String retorno = "ok";
  if(Snnn == 2){
    retorno = (String)"ok T:"+ultima_media_extrusora+(String)" /"+temperatura_extrusora+(String)" B:"+ultima_media_base+(String)" /"+temperatura_base;
  }else{
    retorno = (String)"ok T:"+ultima_media_extrusora+(String)" B:"+ultima_media_base;
  }
  return retorno;
}
