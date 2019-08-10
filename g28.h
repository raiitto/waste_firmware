char* g28(char* parametros){
  boolean X = false;//Flag to go back to the X axis origin
  boolean Y = false;//Flag to go back to the Y axis origin
  boolean Z = false;//Flag to go back to the Z axis origin
  while (parametros != 0)
  {
    String parametro = parametros;
    if(parametro.indexOf("X")>0){
      X=true;
    }else if(parametro.indexOf("Y")>0){
      Y=true;
    }else if(parametro.indexOf("Z")>0){
      Z=true;
    }
    parametros = strtok(0, " ");//Encontrar o proximo parametro
  }
  if(!X&&!Y&&!Z){
    moveTo(0,0,0,  0,  0);
  }else{
    float x_cord_temp = g_x;
    float y_cord_temp = g_y;
    float z_cord_temp = g_z;
    if(X){
      x_cord_temp=0;
    }
    if(Y){
      y_cord_temp=0;
    }
    if(Z){
      z_cord_temp=0;
    }
    moveTo(x_cord_temp,y_cord_temp,z_cord_temp,  0,  0);
  }
  String retorno = "ok";
  return (char*)retorno.c_str();
}
