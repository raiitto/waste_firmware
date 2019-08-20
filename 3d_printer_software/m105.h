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
    retorno = "ok T:";
    retorno.concat(ultima_media_extrusora);
    retorno.concat(" /");
    retorno.concat(temperatura_extrusora);
    retorno.concat(" B:");
    retorno.concat(ultima_media_base);
    retorno.concat(" /");
    retorno.concat(temperatura_base);
  }else{
    retorno = "ok T:";
    retorno.concat(ultima_media_extrusora);
    retorno.concat(" B:");
    retorno.concat(ultima_media_base);
  }
  return retorno;
}
