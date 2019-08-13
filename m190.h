char* m190(char* parametros){
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
    temperatura_base = media_das_temperaturas;
    ativar_base();
    while(ultima_media_base>Snnn||
    ultima_media_base<Rnnn){
      loop_aquecedores();
      delay(10);
      count++;
      if(count>3000)break;
    }
  }else if(Rnnn != nao_iniciado){
    temperatura_base = Rnnn;
    ativar_base();
    while(ultima_media_base<Rnnn){
      loop_aquecedores();
      delay(10);
      count++;
      if(count>3000)break;
    }
  }else if(Snnn != nao_iniciado){
    temperatura_base = Snnn;
    ativar_base();
    while(ultima_media_extrusora>Snnn){
      loop_aquecedores();
      delay(10);
      count++;
      if(count>3000)break;
    }
  }else{
    float cinco_por_cento_range = temperatura_base/20;
    ativar_base();
    while(ultima_media_base+cinco_por_cento_range<temperatura_base||
    ultima_media_base-cinco_por_cento_range>temperatura_base){
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
