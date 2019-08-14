String g20(char* parametros){
  while (parametros != 0)
  {
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  g_polegadas=true;
  String retorno = "ok";
  return retorno;
}
