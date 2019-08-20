String m104(char* parametros){
  int Snnn = nao_iniciado;//Target temperature
  while (parametros != 0)
  {
    String parametro = parametros;
    if(parametro.indexOf("S")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Snnn=atoi(parametros);
    }
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  if(Snnn == nao_iniciado){
    desativar_extrusora();
  }else{
    temperatura_extrusora = Snnn;
    ativar_extrusora();
  }
  String retorno = "ok";
  return retorno;
}
