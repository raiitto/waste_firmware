String g4(char* parametros){
  int Pnnn = nao_iniciado;//Time to wait, in milliseconds
  int Snnn = nao_iniciado;//Time to wait, in seconds
  
  while (parametros != 0)
  {
    String parametro = parametros;
    if(parametro.indexOf("P")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Pnnn=atoi(parametros);
    }else if(parametro.indexOf("S")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Snnn=atoi(parametros);
    }
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  int tempo_total = 0;
  if(Pnnn!=nao_iniciado){
    tempo_total+=Pnnn;
  }
  if(Snnn!=nao_iniciado){
    tempo_total+=Snnn*1000;
  }
  for(int x = 0;x<tempo_total/10;x++){
    delay(10);
    loop_aquecedores();//MANTER AQUECEDORES EQUILIBRADOS
  }
  String retorno = "ok";
  return retorno;
}
