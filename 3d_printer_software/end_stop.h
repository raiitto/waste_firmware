#define end_stop_x_pin 8
#define end_stop_y_pin 9
#define end_stop_z_pin 10


void setup_end_stop(){
  pinMode(end_stop_x_pin, INPUT_PULLUP);
  pinMode(end_stop_y_pin, INPUT_PULLUP);
  pinMode(end_stop_z_pin, INPUT_PULLUP);
}
boolean endX(){
  int leitura = digitalRead(end_stop_x_pin);
  if(leitura == 1){
    return false;
  }else{
    return true;
  }
}
boolean endY(){
  int leitura = digitalRead(end_stop_y_pin);
  if(leitura == 1){
    return false;
  }else{
    return true;
  }
}
boolean endZ(){
  int leitura = digitalRead(end_stop_z_pin);
  if(leitura == 1){
    return false;
  }else{
    return true;
  }
}
