
String comando_g0 = "G0";//Movimento rapido @IMPLEMENTADO
String comando_g1 = "G1";//Movimento linear @IMPLEMENTADO
String comando_g2 = "G2";//rotacao horario @PARA_IMPLEMENTAR
String comando_g3 = "G3";//rotacao anti-horario @PARA_IMPLEMENTAR
String comando_g4 = "G4";//Pause @IMPLEMENTADO
String comando_g17 = "G17";//Plano XY
String comando_g18 = "G18";//Plano ZX
String comando_g19 = "G19";//Plano YZ
String comando_g20 = "G20";//polegadas @IMPLEMENTADO
String comando_g21 = "G21";//milimetros @IMPLEMENTADO
String comando_g28 = "G28";//mover para origem (home all axis) @IMPLEMENTADO
String comando_g92 = "G92";//Set Position @IMPLEMENTADO
String comando_g92_1 = "G92.1";//Reset Position e definir algumas coisas
String comando_g92_2 = "G92.2";//Reset position
String comando_m0 = "M0";//Stop
String comando_m17 = "M17";//Enalbe all motors
String comando_m18 = "M18";//desativar todos motores
String comando_m82 = "M82";//absolute mode extruder @IMPLEMENTADO
String comando_m83 = "M83";//relative mode extruder @IMPLEMENTADO
String comando_m104 = "M104";//Set extruder temperature @IMPLEMENTADO
String comando_m105 = "M105";//Get Extruder Temperature @IMPLEMENTADO
String comando_m106 = "M106";//Ligar ventoinha @IMPLEMENTADO
String comando_m107 = "M107";//Desligar ventoinha @IMPLEMENTADO
String comando_m109 = "M109";//M104 e esperar @IMPLEMENTADO
String comando_m140 = "M140";//definir temperatura da mesa @IMPLEMENTADO
String comando_m190 = "M190";//M140 e esperar @IMPLLEMENTADO
String comando_m300 = "M300";//Play a bip sound
String comando_m999 = "M999";//software reset @IMPLEMENTADO

#define zPlan 66

#define nao_iniciado -999
