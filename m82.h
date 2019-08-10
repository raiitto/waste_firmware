char* m82(char* parametros){
  while (parametros != 0)
  {
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  g_relative_extruder=false;
  String retorno = "ok";
  return (char*)retorno.c_str();
}
