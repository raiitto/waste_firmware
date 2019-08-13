char* g1(char* parametros){//Movimento linear
  int x = 0;
  float cordX=0;
  float cordY=0;
  float cordZ=0;
//#define nao_iniciado -999 //no arquivo de constantes
  float Xnnn = nao_iniciado;//The position to move to on the X axis
  float Ynnn = nao_iniciado;//The position to move to on the Y axis
  float Znnn = nao_iniciado;//The position to move to on the Z axis
  float Ennn = nao_iniciado;//The amount to extrude between the starting point and ending point
  float Fnnn = nao_iniciado;//The feedrate per minute of the move between the starting point and ending point (if supplied)
  while (parametros != 0)
  {
    String parametro = parametros;
    if(parametro.indexOf("X")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Xnnn=atof(parametros);
    }else if(parametro.indexOf("Y")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Ynnn=atof(parametros);
    }else if(parametro.indexOf("Z")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Znnn=atof(parametros);
    }else if(parametro.indexOf("E")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Ennn=atof(parametros);
    }else if(parametro.indexOf("F")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Fnnn=atof(parametros);
    }
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  if(Xnnn==nao_iniciado&&Ynnn==nao_iniciado&&Znnn==nao_iniciado){
    if(Fnnn!=nao_iniciado){
      g_feedrate = Fnnn;
    }
    String retorno = "ok";
    return (char*)retorno.c_str();
  }
  if(g_relative){
    Xnnn = Xnnn!=nao_iniciado?g_x+Xnnn:g_x;
    Ynnn = Ynnn!=nao_iniciado?g_y+Ynnn:g_y;
    Znnn = Znnn!=nao_iniciado?g_z+Znnn:g_z;
  }else{
    Xnnn = Xnnn!=nao_iniciado?Xnnn:g_x;
    Ynnn = Ynnn!=nao_iniciado?Ynnn:g_y;
    Znnn = Znnn!=nao_iniciado?Znnn:g_z;
  }
  float total_mm = abs(g_x-Xnnn);
  total_mm += abs(g_y-Ynnn);
  total_mm += abs(g_z-Znnn);
  int tempo_min = total_mm/g_feedrate;
  if(Fnnn!=nao_iniciado){
    tempo_min = total_mm/Fnnn;
  }
  int tempo_ms = (tempo_min*60)*1000;//Total tempo em milisegundos
  return moveTo(Xnnn,Ynnn,Znnn,tempo_ms,Ennn);//X,Y,Z,tempo,mmToExtrude
}
