char* m109(char* parametros){
  int Rnnn = nao_iniciado;//minimum target temperature, waits until heating
  int Snnn = nao_iniciado;//maximum target temperature, waits until cooling (Sprinter)
  while (parametros != 0)
  {
    String parametro = parametros;
    if(parametro.indexOf("R")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Rnnn=atoi(parametros);
    }else if(parametro.indexOf("S")>=0){
      ++parametros;//Avancar uma posicao na memoria
      Snnn=atoi(parametros);
    }
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  int count = 0;
  if(Rnnn != nao_iniciado&&Snnn != nao_iniciado){
    int media_das_temperaturas = (Rnnn+Snnn)/2;
    temperatura_extrusora = media_das_temperaturas;
    ativar_extrusora();
    while(ultima_media_extrusora>Snnn||
    ultima_media_extrusora<Rnnn){
      loop_aquecedores();
      delay(10);
      count++;
      if(count>3000)break;
    }
  }else if(Rnnn != nao_iniciado){
    temperatura_extrusora = Rnnn;
    ativar_extrusora();
    while(ultima_media_extrusora<Rnnn){
      loop_aquecedores();
      delay(10);
      count++;
      if(count>3000)break;
    }
  }else if(Snnn != nao_iniciado){
    temperatura_extrusora = Snnn;
    ativar_extrusora();
    while(ultima_media_extrusora>Snnn){
      loop_aquecedores();
      delay(10);
      count++;
      if(count>3000)break;
    }
  }else{
    int cinco_range = 5;
    ativar_extrusora();
    while(ultima_media_extrusora+cinco_range<temperatura_extrusora||
    ultima_media_extrusora-cinco_range>temperatura_extrusora){
      loop_aquecedores();
      delay(10);
      count++;
      if(count>3000)break;
    }
  }
  String retorno = "ok";
  if(count>3000)retorno="!!";
  return (char*)retorno.c_str();
}
