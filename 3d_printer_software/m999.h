void(* resetFunc) (void) = 0;
String m999(char* parametros){
  while (parametros != 0)
  {
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  String retorno = "ok";
  Serial.println(retorno);
  delay(10);
  rstc_start_software_reset(RSTC);//Arduino Due
  //resetFunc();//Arduino UNO
  return "";
}
