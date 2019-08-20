#define eixoXdir 7
#define eixoXstep 8
#define eixoYdir 9
#define eixoYstep 10
#define eixoZdir 11
#define eixoZstep 12

float tamanho_passo_eixo_x = 0.25;
float tamanho_passo_eixo_y = 0.25;
float tamanho_passo_eixo_z = 0.25;

#define maxX 78 //Quantidade maxima de passos no eixo X
#define maxY 78 //Quantidade maxima de passos no eixo Y
#define maxZ 78 //Quantidade maxima de passos no eixo Z

int x_passos_coordenada = 0;
int y_passos_coordenada = 0;
int z_passos_coordenada = 0;


void setup_eixos(){
  pinMode(eixoXdir, OUTPUT);
  pinMode(eixoXstep, OUTPUT);
  pinMode(eixoYdir, OUTPUT);
  pinMode(eixoYstep, OUTPUT);
  pinMode(eixoZdir, OUTPUT);
  pinMode(eixoZstep, OUTPUT);
}

void eixoX(boolean a,int tempo){
  if(tempo<2)tempo=2;
  boolean passo_x_permissao = true;
  if(a){
    digitalWrite(eixoXdir,0);
    x_passos_coordenada++;
    if(x_passos_coordenada>maxX||x_passos_coordenada<=0){
      passo_x_permissao=false;
    }
    g_x+=tamanho_passo_eixo_x;
  }
  else{
    digitalWrite(eixoXdir,1);
    x_passos_coordenada--;
    if(x_passos_coordenada<0||x_passos_coordenada>=maxX){
      passo_x_permissao=false;
    }
    g_x-=tamanho_passo_eixo_x;
  }
  if(passo_x_permissao)digitalWrite(eixoXstep,0);
  delay(tempo/2);
  digitalWrite(eixoXstep,1);
  delay(tempo/2);
}
void eixoY(boolean a,int tempo){
  if(tempo<2)tempo=2;
  boolean passo_y_permissao = true;
  if(a){
    digitalWrite(eixoYdir,0);
    y_passos_coordenada++;
    if(y_passos_coordenada>maxY||y_passos_coordenada<=0){
      passo_y_permissao=false;
    }
    g_y+=tamanho_passo_eixo_y;
  }
  else{
    digitalWrite(eixoYdir,1);
    y_passos_coordenada--;
    if(y_passos_coordenada<0||y_passos_coordenada>=maxY){
      passo_y_permissao=false;
    }
    g_y-=tamanho_passo_eixo_y;
  }
  if(passo_y_permissao)digitalWrite(eixoYstep,0);
  delay(tempo/2);
  digitalWrite(eixoYstep,1);
  delay(tempo/2);
}
void eixoZ(boolean a,int tempo){
  if(tempo<2)tempo=2;
  boolean passo_z_permissao = true;
  if(a){
    digitalWrite(eixoZdir,1);
    z_passos_coordenada++;
    if(z_passos_coordenada>maxZ||z_passos_coordenada<=0){
      passo_z_permissao=false;
    }
    g_z+=tamanho_passo_eixo_z;
  }
  else{
    digitalWrite(eixoZdir,0);
    z_passos_coordenada--;
    if(z_passos_coordenada<0||z_passos_coordenada>=maxZ){
      passo_z_permissao=false;
    }
    g_z-=tamanho_passo_eixo_z;
  }
  if(passo_z_permissao)digitalWrite(eixoZstep,0);
  delay(tempo/2);
  digitalWrite(eixoZstep,1);
  delay(tempo/2);
}
void eixoXY(boolean a, boolean b, int tempo){
  if(tempo<2)tempo=2;
  boolean passo_x_permissao = true;
  boolean passo_y_permissao = true;
  if(a){
    digitalWrite(eixoXdir,1);
    x_passos_coordenada++;
    if(x_passos_coordenada>maxX||x_passos_coordenada<=0){
      passo_x_permissao=false;
    }
    g_x+=tamanho_passo_eixo_x;
  }
  else{
    digitalWrite(eixoXdir,0);
    x_passos_coordenada--;
    if(x_passos_coordenada<0||x_passos_coordenada>=maxX){
      passo_x_permissao=false;
    }
    g_x-=tamanho_passo_eixo_x;
  }
  if(b){
    digitalWrite(eixoYdir,1);
    y_passos_coordenada++;
    if(y_passos_coordenada>maxY||y_passos_coordenada<=0){
      passo_y_permissao=false;
    }
    g_y+=tamanho_passo_eixo_y;
  }
  else{
    digitalWrite(eixoYdir,0);
    y_passos_coordenada--;
    if(y_passos_coordenada<0||y_passos_coordenada>=maxY){
      passo_y_permissao=false;
    }
    g_y-=tamanho_passo_eixo_y;
  }
  if(passo_x_permissao)digitalWrite(eixoXstep,0);
  if(passo_y_permissao)digitalWrite(eixoYstep,0);
  delay(tempo/2);
  digitalWrite(eixoXstep,1);
  digitalWrite(eixoYstep,1);
  delay(tempo/2);
}
void eixoXZ(boolean a, boolean b, int tempo){
  if(tempo<2)tempo=2;
  boolean passo_x_permissao = true;
  boolean passo_z_permissao = true;
  if(a){
    digitalWrite(eixoXdir,1);
    x_passos_coordenada++;
    if(x_passos_coordenada>maxX||x_passos_coordenada<=0){
      passo_x_permissao=false;
    }
    g_x+=tamanho_passo_eixo_x;
  }
  else{
    digitalWrite(eixoXdir,0);
    x_passos_coordenada--;
    if(x_passos_coordenada<0||x_passos_coordenada>=maxX){
      passo_x_permissao=false;
    }
    g_x-=tamanho_passo_eixo_x;
  }
  if(b){
    digitalWrite(eixoZdir,1);
    z_passos_coordenada++;
    if(z_passos_coordenada>maxZ||z_passos_coordenada<=0){
      passo_z_permissao=false;
    }
    g_z+=tamanho_passo_eixo_z;
  }
  else{
    digitalWrite(eixoZdir,0);
    z_passos_coordenada--;
    if(z_passos_coordenada<0||z_passos_coordenada>=maxZ){
      passo_z_permissao=false;
    }
    g_z-=tamanho_passo_eixo_z;
  }
  if(passo_x_permissao)digitalWrite(eixoXstep,0);
  if(passo_z_permissao)digitalWrite(eixoZstep,0);
  delay(tempo/2);
  digitalWrite(eixoXstep,1);
  digitalWrite(eixoZstep,1);
  delay(tempo/2);
}
void eixoYZ(boolean a, boolean b, int tempo){
  if(tempo<2)tempo=2;
  boolean passo_y_permissao = true;
  boolean passo_z_permissao = true;
  if(a){
    digitalWrite(eixoYdir,1);
    y_passos_coordenada++;
    if(y_passos_coordenada>maxY||y_passos_coordenada<=0){
      passo_y_permissao=false;
    }
    g_y+=tamanho_passo_eixo_y;
  }
  else{
    digitalWrite(eixoYdir,0);
    y_passos_coordenada--;
    if(y_passos_coordenada<0||y_passos_coordenada>=maxY){
      passo_y_permissao=false;
    }
    g_y-=tamanho_passo_eixo_y;
  }
  if(b){
    digitalWrite(eixoZdir,1);
    z_passos_coordenada++;
    if(z_passos_coordenada>maxZ||z_passos_coordenada<=0){
      passo_z_permissao=false;
    }
    g_z+=tamanho_passo_eixo_z;
  }
  else{
    digitalWrite(eixoZdir,0);
    z_passos_coordenada--;
    if(z_passos_coordenada<0||z_passos_coordenada>=maxZ){
      passo_z_permissao=false;
    }
    g_z-=tamanho_passo_eixo_z;
  }
  if(passo_y_permissao)digitalWrite(eixoYstep,0);
  if(passo_z_permissao)digitalWrite(eixoZstep,0);
  delay(tempo/2);
  digitalWrite(eixoYstep,1);
  digitalWrite(eixoZstep,1);
  delay(tempo/2);
}
void eixoXYZ(boolean a, boolean b, boolean c, int tempo){
  if(tempo<2)tempo=2;
  boolean passo_x_permissao = true;
  boolean passo_y_permissao = true;
  boolean passo_z_permissao = true;
  if(a){
    digitalWrite(eixoXdir,1);
    x_passos_coordenada++;
    if(x_passos_coordenada>maxX||x_passos_coordenada<=0){
      passo_x_permissao=false;
    }
    g_x+=tamanho_passo_eixo_x;
  }
  else{
    digitalWrite(eixoXdir,0);
    x_passos_coordenada--;
    if(x_passos_coordenada<0||x_passos_coordenada>=maxX){
      passo_x_permissao=false;
    }
    g_x-=tamanho_passo_eixo_x;
  }
  if(b){
    digitalWrite(eixoYdir,1);
    y_passos_coordenada++;
    if(y_passos_coordenada>maxY||y_passos_coordenada<=0){
      passo_y_permissao=false;
    }
    g_y+=tamanho_passo_eixo_y;
  }
  else{
    digitalWrite(eixoYdir,0);
    y_passos_coordenada--;
    if(y_passos_coordenada<0||y_passos_coordenada>=maxY){
      passo_y_permissao=false;
    }
    g_y-=tamanho_passo_eixo_y;
  }
  if(c){
    digitalWrite(eixoZdir,1);
    z_passos_coordenada++;
    if(z_passos_coordenada>maxZ||z_passos_coordenada<=0){
      passo_z_permissao=false;
    }
    g_z+=tamanho_passo_eixo_z;
  }
  else{
    digitalWrite(eixoZdir,0);
    z_passos_coordenada--;
    if(z_passos_coordenada<0||z_passos_coordenada>=maxZ){
      passo_z_permissao=false;
    }
    g_z-=tamanho_passo_eixo_z;
  }
  if(passo_x_permissao)digitalWrite(eixoXstep,0);
  if(passo_y_permissao)digitalWrite(eixoYstep,0);
  if(passo_z_permissao)digitalWrite(eixoZstep,0);
  delay(tempo/2);
  digitalWrite(eixoXstep,1);
  digitalWrite(eixoYstep,1);
  digitalWrite(eixoZstep,1);
  delay(tempo/2);
}
