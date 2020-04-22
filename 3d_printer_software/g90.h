String g90(char* parametros){
  while (parametros != 0)
  {
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  g_relative = false; //false = absolute position from origin
  String retorno = "ok";
  return retorno;
}
