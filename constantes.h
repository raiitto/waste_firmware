
String comando_g0 = "G0";//Movimento rapido
String comando_g1 = "G1";//Movimento linear
String comando_g2 = "G2";//rotacao horario
String comando_g3 = "G3";//rotacao anti-horario
String comando_g4 = "G4";//Pause
String comando_g17 = "G17";//Plano XY
String comando_g18 = "G18";//Plano ZX
String comando_g19 = "G19";//Plano YZ
String comando_g20 = "G20";//polegadas
String comando_g21 = "G21";//milimetros
String comando_g92 = "G92";//Set Position
String comando_g92_1 = "G92.1";//Reset Position e definir algumas coisas
String comando_g92_2 = "G92.2";//Reset position
String comando_m0 = "M0";//Stop
String comando_m17 = "M17";//Enalbe all motors
String comando_m18 = "M18";//desativar todos motores
String comando_m104 = "M104";//Set extruder temperature
String comando_m109 = "M109";//M104 e esperar
String comando_m140 = "M140";//definir temperatura da mesa
String comando_m190 = "M190";//M149 e esperar
String comando_m300 = "M300";//Play a bip sound

#define maxX 78
#define maxY 78 // 80
#define maxZ 78 // 80
#define zPlan 66

#define nao_iniciado -999
