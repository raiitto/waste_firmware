#define eixoXmotorApin1 22
#define eixoXmotorApin2 23
#define eixoXmotorBpin1 24
#define eixoXmotorBpin2 25

#define eixoZmotorApin1 26
#define eixoZmotorApin2 27
#define eixoZmotorBpin1 28
#define eixoZmotorBpin2 29

#define eixoYmotorApin1 30
#define eixoYmotorApin2 31
#define eixoYmotorBpin1 32
#define eixoYmotorBpin2 33

//    AB'               A'B'
//
//
//
//    AB                A'B
boolean XA = true;
boolean XB = true;
boolean YA = true;
boolean YB = true;
boolean ZA = true;
boolean ZB = true;

boolean sentidoX = true;
boolean sentidoY = true;
boolean sentidoZ = true;
boolean stepXbool = true;
boolean stepYbool = true;
boolean stepZbool = true;

void motorXA(boolean a);
void motorXB(boolean a);
void motorYA(boolean a);
void motorYB(boolean a);
void motorZA(boolean a);
void motorZB(boolean a);
void setup_driver(){
  pinMode(eixoXmotorApin1, OUTPUT);
  pinMode(eixoXmotorApin2, OUTPUT);
  pinMode(eixoXmotorBpin1, OUTPUT);
  pinMode(eixoXmotorBpin2, OUTPUT);
  pinMode(eixoYmotorApin1, OUTPUT);
  pinMode(eixoYmotorApin2, OUTPUT);
  pinMode(eixoYmotorBpin1, OUTPUT);
  pinMode(eixoYmotorBpin2, OUTPUT);
  pinMode(eixoZmotorApin1, OUTPUT);
  pinMode(eixoZmotorApin2, OUTPUT);
  pinMode(eixoZmotorBpin1, OUTPUT);
  pinMode(eixoZmotorBpin2, OUTPUT);
  motorXA(true);
  motorXB(true);
  motorYA(true);
  motorYB(true);
  motorZA(true);
  motorYB(true);
  
}

void eixoXdir(int direcao){
  if(direcao==0){
    sentidoX=false;
  }else{
    sentidoX=true;
  }
}
void eixoXstep(int a){
  if(a==0){
    if(stepXbool==true){
      stepXbool=false;
    }else{
      return;
    }
  }else{
    stepXbool=true;
    return;
  }
  if(sentidoX){
    if(XA&&XB){
        motorXA(true);motorXB(false);
    }else if(XA&&(!XB)){
        motorXA(false);motorXB(false);
    }else if((!XA)&&XB){
        motorXA(true);motorXB(true);
    }else if((!XA)&&(!XB)){
        motorXA(false);motorXB(true);
    }
  }else{
    if(XA&&XB){
        motorXA(false);motorXB(true);
    }else if(XA&&(!XB)){
        motorXA(true);motorXB(true);
    }else if((!XA)&&XB){
        motorXA(false);motorXB(false);
    }else if((!XA)&&(!XB)){
        motorXA(true);motorXB(false);
    }
  }
}

void eixoYdir(int direcao){
  if(direcao==0){
    sentidoY=false;
  }else{
    sentidoY=true;
  }
}
void eixoYstep(int a){
  if(a==0){
    if(stepYbool==true){
      stepYbool=false;
    }else{
      return;
    }
  }else{
    stepYbool=true;
    return;
  }
  if(sentidoY){
    if(YA&&YB){
        motorYA(true);motorYB(false);
    }else if(YA&&(!YB)){
        motorYA(false);motorYB(false);
    }else if((!YA)&&YB){
        motorYA(true);motorYB(true);
    }else if((!YA)&&(!YB)){
        motorYA(false);motorYB(true);
    }
  }else{
    if(YA&&YB){
        motorYA(false);motorYB(true);
    }else if(YA&&(!YB)){
        motorYA(true);motorYB(true);
    }else if((!YA)&&YB){
        motorYA(false);motorYB(false);
    }else if((!YA)&&(!YB)){
        motorYA(true);motorYB(false);
    }
  }
}

void eixoZdir(int direcao){
  if(direcao==0){
    sentidoZ=false;
  }else{
    sentidoZ=true;
  }
}
void eixoZstep(int a){
  if(a==0){
    if(stepZbool==true){
      stepZbool=false;
    }else{
      return;
    }
  }else{
    stepZbool=true;
    return;
  }
  if(sentidoZ){
    if(ZA&&ZB){
        motorZA(true);motorZB(false);
    }else if(ZA&&(!ZB)){
        motorZA(false);motorZB(false);
    }else if((!ZA)&&ZB){
        motorZA(true);motorZB(true);
    }else if((!ZA)&&(!ZB)){
        motorZA(false);motorZB(true);
    }
  }else{
    if(ZA&&ZB){
        motorZA(false);motorZB(true);
    }else if(ZA&&(!ZB)){
        motorZA(true);motorZB(true);
    }else if((!ZA)&&ZB){
        motorZA(false);motorZB(false);
    }else if((!ZA)&&(!ZB)){
        motorZA(true);motorZB(false);
    }
  }
}





void motorXA(boolean a){
  XA=a;
  if(a){
    digitalWrite(eixoXmotorApin1, 1);
    digitalWrite(eixoXmotorApin2, 0);
  }else{
    digitalWrite(eixoXmotorApin1, 0);
    digitalWrite(eixoXmotorApin2, 1);
  }
}
void motorXB(boolean a){
  XB=a;
  if(a){
    digitalWrite(eixoXmotorBpin1, 1);
    digitalWrite(eixoXmotorBpin2, 0);
  }else{
    digitalWrite(eixoXmotorBpin1, 0);
    digitalWrite(eixoXmotorBpin2, 1);
  }
}

void motorYA(boolean a){
  YA=a;
  if(a){
    digitalWrite(eixoYmotorApin1, 1);
    digitalWrite(eixoYmotorApin2, 0);
  }else{
    digitalWrite(eixoYmotorApin1, 0);
    digitalWrite(eixoYmotorApin2, 1);
  }

}
void motorYB(boolean a){
  YB=a;
  if(a){
    digitalWrite(eixoYmotorBpin1, 1);
    digitalWrite(eixoYmotorBpin2, 0);
  }else{
    digitalWrite(eixoYmotorBpin1, 0);
    digitalWrite(eixoYmotorBpin2, 1);
  }
}

void motorZA(boolean a){
  ZA=a;
  if(a){
    digitalWrite(eixoZmotorApin1, 1);
    digitalWrite(eixoZmotorApin2, 0);
  }else{
    digitalWrite(eixoZmotorApin1, 0);
    digitalWrite(eixoZmotorApin2, 1);
  }
}
void motorZB(boolean a){
  ZB=a;
  if(a){
    digitalWrite(eixoZmotorBpin1, 1);
    digitalWrite(eixoZmotorBpin2, 0);
  }else{
    digitalWrite(eixoZmotorBpin1, 0);
    digitalWrite(eixoZmotorBpin2, 1);
  }
}
