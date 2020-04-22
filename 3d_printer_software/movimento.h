
int maximoDe(float x, int y, int z);
void moverComMaximoX(int x_passos, int y_passos, int z_passos, boolean direcao_x, boolean direcao_y, boolean direcao_z,int tempo, float extrudar);
void moverComMaximoY(int x_passos, int y_passos, int z_passos, boolean direcao_x, boolean direcao_y, boolean direcao_z,int tempo, float extrudar);
void moverComMaximoZ(int x_passos, int y_passos, int z_passos, boolean direcao_x, boolean direcao_y, boolean direcao_z,int tempo, float extrudar);


String moveTo(float x, float y, float z, int tempo, float extrudar){
  boolean direcao_x = true;
  boolean direcao_y = true;
  boolean direcao_z = true;
  int passos_x = round((x-g_x)/tamanho_passo_eixo_x);//Conversao mm to step
  int passos_y = round((y-g_y)/tamanho_passo_eixo_y);//Conversao mm to step
  int passos_z = round((z-g_z)/tamanho_passo_eixo_z);//Conversao mm to step
    extrudar = extrudar-g_cordenada_extruder;
  if(g_polegadas){
    int passos_x = round(((x-g_x)*25.4)/tamanho_passo_eixo_x);//Conversao polegadas to step
    int passos_y = round(((y-g_y)*25.4)/tamanho_passo_eixo_y);//Conversao polegadas to step
    int passos_z = round(((z-g_z)*25.4)/tamanho_passo_eixo_z);//Conversao polegadas to step
    extrudar*=25.4;
  }
  if(passos_x<0){//Direcionamento X
    direcao_x = false;
  }
  if(passos_y<0){//Direcionamento Y
    direcao_y = false;
  }
  if(passos_z<0){//Direcionamento Z
    direcao_z = false;
  }
  passos_x = abs(passos_x);
  passos_y = abs(passos_y);
  passos_z = abs(passos_z);

  int resposta_maximo = maximoDe(passos_x,passos_y,passos_z);
  String retorno = "ok";
  switch(resposta_maximo){
    case 1:
      moverComMaximoX(passos_x,passos_y,passos_z,direcao_x,direcao_y,direcao_z,tempo,extrudar);
      break;
    case 2:
      moverComMaximoY(passos_x,passos_y,passos_z,direcao_x,direcao_y,direcao_z,tempo,extrudar);
      break;
    case 3:
      moverComMaximoZ(passos_x,passos_y,passos_z,direcao_x,direcao_y,direcao_z,tempo,extrudar);
      break;
    default:
      retorno = "rs";
      break;
  }
  return retorno;
}

int maximoDe(float x, int y, int z){
  if(max(x,y)==x){
    if(max(x,z)==x){
      return 1;
    }else{
      return 3;
    }
  }else{
    if(max(y,z)==y){
      return 2;
    }else{
      return 3;
    }
  }
}

void moverComMaximoX(int x_passos, int y_passos, int z_passos, boolean direcao_x, boolean direcao_y, boolean direcao_z,int tempo, float qtd_extrudar){
  int tempo_por_passo = tempo/(x_passos+y_passos+z_passos);
  float extrusao_por_passo = qtd_extrudar/(x_passos+y_passos+z_passos);
  float x_por_y = x_passos/y_passos;
  float x_por_z = x_passos/z_passos;
  int cont_y = 0;
  int cont_z = 0;
  int cont_extrusao = 0;
  boolean passo_y = false;
  boolean passo_z = false;
  for(int x=1;x<=x_passos;x++){
    loop_aquecedores();//MANTER AQUECEDORES EQUILIBRADOS
    if(x>cont_y*x_por_y&&cont_y<y_passos){
      passo_y=true;
      cont_y++;
    }
    if(x>cont_z*x_por_z&&cont_z<z_passos){
      passo_z=true;
      cont_z++;
    }
    if(passo_y&&passo_z){
      extrudar(extrusao_por_passo*3,0);cont_extrusao+=extrusao_por_passo*3;
      eixoXYZ(direcao_x,direcao_y,direcao_z,tempo_por_passo*3);
    }else if(passo_y){
      extrudar(extrusao_por_passo*2,0);cont_extrusao+=extrusao_por_passo*2;
      eixoXY(direcao_x,direcao_y,tempo_por_passo*2);
    }else if(passo_z){
      extrudar(extrusao_por_passo*2,0);cont_extrusao+=extrusao_por_passo*2;
      eixoXZ(direcao_x,direcao_z,tempo_por_passo*2);
    }else{
      extrudar(extrusao_por_passo,0);cont_extrusao+=extrusao_por_passo;
      eixoX(direcao_x,tempo_por_passo);
    }
    passo_y=false;
    passo_z=false;
  }
  //Descarregar resto de passos
  for(;cont_extrusao<qtd_extrudar;cont_extrusao+=extrusao_por_passo){
      extrudar(extrusao_por_passo,0);
  }
  for(;cont_y<y_passos;cont_y++){
    eixoY(direcao_y,tempo_por_passo);
  }
  for(;cont_z<z_passos;cont_z++){
    eixoZ(direcao_z,tempo_por_passo);
  }
}
void moverComMaximoY(int x_passos, int y_passos, int z_passos, boolean direcao_x, boolean direcao_y, boolean direcao_z,int tempo, float qtd_extrudar){
  int tempo_por_passo = tempo/(x_passos+y_passos+z_passos);
  float extrusao_por_passo = qtd_extrudar/(x_passos+y_passos+z_passos);
  float y_por_x = y_passos/x_passos;
  float y_por_z = y_passos/z_passos;
  int cont_x = 0;
  int cont_z = 0;
  int cont_extrusao = 0;
  boolean passo_x = false;
  boolean passo_z = false;
  for(int y=1;y<=y_passos;y++){
    if(y>cont_x*y_por_x&&cont_x<x_passos){
      passo_x=true;
      cont_x++;
    }
    if(y>cont_z*y_por_z&&cont_z<z_passos){
      passo_z=true;
      cont_z++;
    }
    if(passo_x&&passo_z){
      extrudar(extrusao_por_passo*3,0);cont_extrusao+=extrusao_por_passo*3;
      eixoXYZ(direcao_x,direcao_y,direcao_z,tempo_por_passo*3);
    }else if(passo_x){
      extrudar(extrusao_por_passo*2,0);cont_extrusao+=extrusao_por_passo*2;
      eixoXY(direcao_x,direcao_y,tempo_por_passo*2);
    }else if(passo_z){
      extrudar(extrusao_por_passo*2,0);cont_extrusao+=extrusao_por_passo*2;
      eixoYZ(direcao_y,direcao_z,tempo_por_passo*2);
    }else{
      extrudar(extrusao_por_passo,0);cont_extrusao+=extrusao_por_passo;
      eixoY(direcao_y,tempo_por_passo);
    }
    passo_x=false;
    passo_z=false;
  }
  //Descarregar resto de passos
  for(;cont_extrusao<qtd_extrudar;cont_extrusao+=extrusao_por_passo){
      extrudar(extrusao_por_passo,0);
  }
  for(;cont_x<x_passos;cont_x++){
    eixoX(direcao_x,tempo_por_passo);
  }
  for(;cont_z<z_passos;cont_z++){
    eixoZ(direcao_z,tempo_por_passo);
  }
}
void moverComMaximoZ(int x_passos, int y_passos, int z_passos, boolean direcao_x, boolean direcao_y, boolean direcao_z,int tempo, float qtd_extrudar){
  int tempo_por_passo = tempo/(x_passos+y_passos+z_passos);
  float extrusao_por_passo = qtd_extrudar/(x_passos+y_passos+z_passos);
  float z_por_x = z_passos/x_passos;
  float z_por_y = z_passos/y_passos;
  int cont_x = 0;
  int cont_y = 0;
  int cont_extrusao = 0;
  boolean passo_x = false;
  boolean passo_y = false;
  for(int z=1;z<=z_passos;z++){
    if(z>cont_x*z_por_x&&cont_x<x_passos){
      passo_x=true;
      cont_x++;
    }
    if(z>cont_y*z_por_y&&cont_y<y_passos){
      passo_y=true;
      cont_y++;
    }
    if(passo_x&&passo_y){
      extrudar(extrusao_por_passo*3,0);cont_extrusao+=extrusao_por_passo*3;
      eixoXYZ(direcao_x,direcao_y,direcao_z,tempo_por_passo*3);
    }else if(passo_x){
      extrudar(extrusao_por_passo*2,0);cont_extrusao+=extrusao_por_passo*2;
      eixoXZ(direcao_x,direcao_z,tempo_por_passo*2);
    }else if(passo_y){
      extrudar(extrusao_por_passo*2,0);cont_extrusao+=extrusao_por_passo*2;
      eixoYZ(direcao_y,direcao_z,tempo_por_passo*2);
    }else{
      extrudar(extrusao_por_passo,0);cont_extrusao+=extrusao_por_passo;
      eixoZ(direcao_z,tempo_por_passo);
    }
    passo_x=false;
    passo_y=false;
  }
  //Descarregar resto de passos
  for(;cont_extrusao<qtd_extrudar;cont_extrusao+=extrusao_por_passo){
      extrudar(extrusao_por_passo,0);
  }
  for(;cont_x<x_passos;cont_x++){
    eixoX(direcao_x,tempo_por_passo);
  }
  for(;cont_y<y_passos;cont_y++){
    eixoY(direcao_y,tempo_por_passo);
  }
}
