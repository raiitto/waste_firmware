//#define eixoXdir 7
//#define eixoXstep 8
//#define eixoYdir 9
//#define eixoYstep 10
//#define eixoZdir 11
//#define eixoZstep 12


#define tamanhoEixoX 34.0 //Quantidade maxima de mm no eixo X
#define tamanhoEixoY 34.0 //Quantidade maxima de mm no eixo Y
#define tamanhoEixoZ 29.6578//39.0 //Quantidade maxima de mm no eixo Z

#define maxX 229.28//263 //Quantidade maxima de passos no eixo X
#define maxY 229.28//263 //Quantidade maxima de passos no eixo Y
#define maxZ 200//263 //Quantidade maxima de passos no eixo Z

double tamanho_passo_eixo_x = tamanhoEixoX/maxX;
double tamanho_passo_eixo_y = tamanhoEixoY/maxY;
double tamanho_passo_eixo_z = tamanhoEixoZ/maxZ;

int x_passos_coordenada = 0;
int y_passos_coordenada = 0;
int z_passos_coordenada = 0;


void setup_eixos(){
  //pinMode(eixoXdir, OUTPUT);
  //pinMode(eixoXstep, OUTPUT);
  //pinMode(eixoYdir, OUTPUT);
  //pinMode(eixoYstep, OUTPUT);
  //pinMode(eixoZdir, OUTPUT);
  //pinMode(eixoZstep, OUTPUT);
}

void eixoX(boolean a,int tempo){
  if(tempo<2)tempo=2;
  boolean passo_x_permissao = true;
  if(a){
    eixoXdir(1);
    x_passos_coordenada++;
    if(x_passos_coordenada>maxX||x_passos_coordenada<=0){
      passo_x_permissao=false;
    }
    g_x+=tamanho_passo_eixo_x;
  }
  else{
    eixoXdir(0);
    x_passos_coordenada--;
    if(x_passos_coordenada<0||x_passos_coordenada>=maxX){
      passo_x_permissao=false;
    }
    g_x-=tamanho_passo_eixo_x;
  }
  if(passo_x_permissao)eixoXstep(0);
  delay(tempo/2);
  eixoXstep(1);
  delay(tempo/2);
}
void eixoY(boolean a,int tempo){
  if(tempo<2)tempo=2;
  boolean passo_y_permissao = true;
  if(a){
    eixoYdir(0);
    y_passos_coordenada++;
    if(y_passos_coordenada>maxY||y_passos_coordenada<=0){
      passo_y_permissao=false;
    }
    g_y+=tamanho_passo_eixo_y;
  }
  else{
    eixoYdir(1);
    y_passos_coordenada--;
    if(y_passos_coordenada<0||y_passos_coordenada>=maxY){
      passo_y_permissao=false;
    }
    g_y-=tamanho_passo_eixo_y;
  }
  if(passo_y_permissao)eixoYstep(0);
  delay(tempo/2);
  eixoYstep(1);
  delay(tempo/2);
}
void eixoZ(boolean a,int tempo){
  if(tempo<2)tempo=2;
  boolean passo_z_permissao = true;
  if(a){
    eixoZdir(0);
    z_passos_coordenada++;
    if(z_passos_coordenada>maxZ||z_passos_coordenada<=0){
      passo_z_permissao=false;
    }
    g_z+=tamanho_passo_eixo_z;
  }
  else{
    eixoZdir(1);
    z_passos_coordenada--;
    if(z_passos_coordenada<0||z_passos_coordenada>=maxZ){
      passo_z_permissao=false;
    }
    g_z-=tamanho_passo_eixo_z;
  }
  if(passo_z_permissao)eixoZstep(0);
  delay(tempo/2);
  eixoZstep(1);
  delay(tempo/2);
}
void eixoXY(boolean a, boolean b, int tempo){
  if(tempo<2)tempo=2;
  boolean passo_x_permissao = true;
  boolean passo_y_permissao = true;
  if(a){
    eixoXdir(1);
    x_passos_coordenada++;
    if(x_passos_coordenada>maxX||x_passos_coordenada<=0){
      passo_x_permissao=false;
    }
    g_x+=tamanho_passo_eixo_x;
  }
  else{
    eixoXdir(0);
    x_passos_coordenada--;
    if(x_passos_coordenada<0||x_passos_coordenada>=maxX){
      passo_x_permissao=false;
    }
    g_x-=tamanho_passo_eixo_x;
  }
  if(b){
    eixoYdir(0);
    y_passos_coordenada++;
    if(y_passos_coordenada>maxY||y_passos_coordenada<=0){
      passo_y_permissao=false;
    }
    g_y+=tamanho_passo_eixo_y;
  }
  else{
    eixoYdir(1);
    y_passos_coordenada--;
    if(y_passos_coordenada<0||y_passos_coordenada>=maxY){
      passo_y_permissao=false;
    }
    g_y-=tamanho_passo_eixo_y;
  }
  if(passo_x_permissao)eixoXstep(0);
  if(passo_y_permissao)eixoYstep(0);
  delay(tempo/2);
  eixoXstep(1);
  eixoYstep(1);
  delay(tempo/2);
}
void eixoXZ(boolean a, boolean b, int tempo){
  if(tempo<2)tempo=2;
  boolean passo_x_permissao = true;
  boolean passo_z_permissao = true;
  if(a){
    eixoXdir(1);
    x_passos_coordenada++;
    if(x_passos_coordenada>maxX||x_passos_coordenada<=0){
      passo_x_permissao=false;
    }
    g_x+=tamanho_passo_eixo_x;
  }
  else{
    eixoXdir(0);
    x_passos_coordenada--;
    if(x_passos_coordenada<0||x_passos_coordenada>=maxX){
      passo_x_permissao=false;
    }
    g_x-=tamanho_passo_eixo_x;
  }
  if(b){
    eixoZdir(0);
    z_passos_coordenada++;
    if(z_passos_coordenada>maxZ||z_passos_coordenada<=0){
      passo_z_permissao=false;
    }
    g_z+=tamanho_passo_eixo_z;
  }
  else{
    eixoZdir(1);
    z_passos_coordenada--;
    if(z_passos_coordenada<0||z_passos_coordenada>=maxZ){
      passo_z_permissao=false;
    }
    g_z-=tamanho_passo_eixo_z;
  }
  if(passo_x_permissao)eixoXstep(0);
  if(passo_z_permissao)eixoZstep(0);
  delay(tempo/2);
  eixoXstep(1);
  eixoZstep(1);
  delay(tempo/2);
}
void eixoYZ(boolean a, boolean b, int tempo){
  if(tempo<2)tempo=2;
  boolean passo_y_permissao = true;
  boolean passo_z_permissao = true;
  if(a){
    eixoYdir(0);
    y_passos_coordenada++;
    if(y_passos_coordenada>maxY||y_passos_coordenada<=0){
      passo_y_permissao=false;
    }
    g_y+=tamanho_passo_eixo_y;
  }
  else{
    eixoYdir(1);
    y_passos_coordenada--;
    if(y_passos_coordenada<0||y_passos_coordenada>=maxY){
      passo_y_permissao=false;
    }
    g_y-=tamanho_passo_eixo_y;
  }
  if(b){
    eixoZdir(0);
    z_passos_coordenada++;
    if(z_passos_coordenada>maxZ||z_passos_coordenada<=0){
      passo_z_permissao=false;
    }
    g_z+=tamanho_passo_eixo_z;
  }
  else{
    eixoZdir(1);
    z_passos_coordenada--;
    if(z_passos_coordenada<0||z_passos_coordenada>=maxZ){
      passo_z_permissao=false;
    }
    g_z-=tamanho_passo_eixo_z;
  }
  if(passo_y_permissao)eixoYstep(0);
  if(passo_z_permissao)eixoZstep(0);
  delay(tempo/2);
  eixoYstep(1);
  eixoZstep(1);
  delay(tempo/2);
}
void eixoXYZ(boolean a, boolean b, boolean c, int tempo){
  if(tempo<2)tempo=2;
  boolean passo_x_permissao = true;
  boolean passo_y_permissao = true;
  boolean passo_z_permissao = true;
  if(a){
    eixoXdir(1);
    x_passos_coordenada++;
    if(x_passos_coordenada>maxX||x_passos_coordenada<=0){
      passo_x_permissao=false;
    }
    g_x+=tamanho_passo_eixo_x;
  }
  else{
    eixoXdir(0);
    x_passos_coordenada--;
    if(x_passos_coordenada<0||x_passos_coordenada>=maxX){
      passo_x_permissao=false;
    }
    g_x-=tamanho_passo_eixo_x;
  }
  if(b){
    eixoYdir(0);
    y_passos_coordenada++;
    if(y_passos_coordenada>maxY||y_passos_coordenada<=0){
      passo_y_permissao=false;
    }
    g_y+=tamanho_passo_eixo_y;
  }
  else{
    eixoYdir(1);
    y_passos_coordenada--;
    if(y_passos_coordenada<0||y_passos_coordenada>=maxY){
      passo_y_permissao=false;
    }
    g_y-=tamanho_passo_eixo_y;
  }
  if(c){
    eixoZdir(0);
    z_passos_coordenada++;
    if(z_passos_coordenada>maxZ||z_passos_coordenada<=0){
      passo_z_permissao=false;
    }
    g_z+=tamanho_passo_eixo_z;
  }
  else{
    eixoZdir(1);
    z_passos_coordenada--;
    if(z_passos_coordenada<0||z_passos_coordenada>=maxZ){
      passo_z_permissao=false;
    }
    g_z-=tamanho_passo_eixo_z;
  }
  if(passo_x_permissao)eixoXstep(0);
  if(passo_y_permissao)eixoYstep(0);
  if(passo_z_permissao)eixoZstep(0);
  delay(tempo/2);
  eixoXstep(1);
  eixoYstep(1);
  eixoZstep(1);
  delay(tempo/2);
}
