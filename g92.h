char* g92(char* parametros){
  float Xnnn = nao_iniciado;//The position to move to on the X axis
  float Ynnn = nao_iniciado;//The position to move to on the Y axis
  float Znnn = nao_iniciado;//The position to move to on the Z axis
  float Ennn = nao_iniciado;//The amount to extrude between the starting point and ending point
  while (parametros != 0)
  {
    String parametro = parametros;
    if(parametro.indexOf("X")>0){
      ++parametros;//Avancar uma posicao na memoria
      Xnnn=atof(parametros);
    }else if(parametro.indexOf("Y")>0){
      ++parametros;//Avancar uma posicao na memoria
      Ynnn=atof(parametros);
    }else if(parametro.indexOf("Z")>0){
      ++parametros;//Avancar uma posicao na memoria
      Znnn=atof(parametros);
    }else if(parametro.indexOf("E")>0){
      ++parametros;//Avancar uma posicao na memoria
      Ennn=atof(parametros);
    }
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  String retorno = "ok";
  if(Xnnn==nao_iniciado&&Ynnn==nao_iniciado&&Znnn==nao_iniciado&&Ennn==nao_iniciado){
    g_cordenada_extruder=0;
    g_x=0;
    g_y=0;
    g_z=0;
    return (char*)retorno.c_str();
  }
  if(Xnnn!=nao_iniciado){
    g_x=Xnnn;
  }
  if(Ynnn!=nao_iniciado){
    g_y=Ynnn;
  }
  if(Znnn!=nao_iniciado){
    g_z=Znnn;
  }
  if(Ennn!=nao_iniciado){
    g_cordenada_extruder=Ennn;
  }
  return (char*)retorno.c_str();
}
