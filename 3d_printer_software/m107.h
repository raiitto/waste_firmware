String m107(char* parametros){
  while (parametros != 0)
  {
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  desativar_ventoinha_extrusora();
  String retorno = "ok";
  return retorno;
}
