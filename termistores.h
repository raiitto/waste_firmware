#include <math.h>
#define pino_termistor_extrusora 0   // Analog Pin 0
#define pino_termistor_base 1   // Analog Pin 1

//Schematic:
// [Ground] ---- [620k-Resistor] -------|------- [Thermistor] ---- [+5v]
//                                                             |
//                                                     Analog Pin 0

double Thermistor(int RawADC, int resistor, int A, int B, int C) {
 float Tension_de_trabajo = 5.0; // VCC 
 float Voltaje_R2=(Tension_de_trabajo/1023.0)*RawADC;
 long resistencia_sensor=resistor*(Tension_de_trabajo-Voltaje_R2)/Voltaje_R2;
 double Temp;  // Dual-Purpose variable to save space.
 Temp = log(resistencia_sensor); // Saving the Log(resistance) so not to calculate it 4 times later. // "Temp" means "Temporary" on this line.
 Temp = 1 / (A + (B * Temp) + (C * Temp * Temp * Temp));   // Now it means both "Temporary" and "Temperature"

 //Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert to Fahrenheit
 return Temp;  // Return the Temperature
}

double temperaturaExtrusora(){
 int   resistencia = 620; // Cambiar por el valor de la resistencia conocida
 double A = 0.0008270600802921212;//0.001129148
 double B = 0.0002088079087593938;//0.000234125
 double C = 8.058078989620383e-8;//0.0000000876741
 double leitura =analogRead(pino_termistor_extrusora); 
 double temp = Thermistor(leitura, resistencia,A,B,C);
 //temp = (temp * 9.0)/ 5.0 + 32.0;                      // converts to Fahrenheit
 return temp;
}
double temperaturaBase(){
 int   resistencia = 620; // Cambiar por el valor de la resistencia conocida
 double A = 0.0008270600802921212;//0.001129148
 double B = 0.0002088079087593938;//0.000234125
 double C = 8.058078989620383e-8;//0.0000000876741
 double leitura =analogRead(pino_termistor_base); 
 double temp = Thermistor(leitura, resistencia,A,B,C);
 //temp = (temp * 9.0)/ 5.0 + 32.0;                      // converts to Fahrenheit
 return temp;
}
