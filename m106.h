String m106(char* parametros){
  int Pnnn = nao_iniciado;//Fan number (optional, defaults to 0)2
  float Snnn = nao_iniciado;//Fan speed (0 to 255; RepRapFirmware also accepts 0.0 to 1.0))
  while (parametros != 0)
  {
    String parametro = parametros;
    if(parametro.indexOf("P")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Snnn=atoi(parametros);
    }else if(parametro.indexOf("S")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Snnn=atof(parametros);
    }
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  if(Snnn>0||Snnn==nao_iniciado){
    ativar_ventoinha_extrusora();
  }else{
    desativar_ventoinha_extrusora();
  }
  String retorno = "ok";
  return retorno;
}
