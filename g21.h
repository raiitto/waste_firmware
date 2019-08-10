char* g21(char* parametros){
  while (parametros != 0)
  {
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  g_polegadas=false;
  String retorno = "ok";
  return (char*)retorno.c_str();
}
