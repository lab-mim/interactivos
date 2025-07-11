#include <Wire.h>
#include <TFT.h>  // Arduino LCD library
#include <SPI.h>
#include "LedControl.h"
#include <SoftwareSerial.h>


#define DELAY 100
#define DELAY_COM 200
//#define SCREEN

// pines MEGA
#define cs 22
#define dc 26
#define rst 24

//pines display 7 segmentos
#define DIN_1 7
#define CLK_1 6
#define LOAD_1 5

//pines display 7 segmentos
#define DIN_2 4
#define CLK_2 3
#define LOAD_2 2


#define color 0xFFFFFF
#define tam 3
uint8_t ficha[100];     // Array to store received data
int16_t bytesRead = 0;  // Number of bytes read

unsigned long delaytime = 999;

SoftwareSerial RS485(9, 8);  // RX, TX

// create an instance of the library

#ifdef SCREEN
TFT TFTscreen = TFT(cs, dc, rst);
#endif


LedControl lc = LedControl(DIN_1, CLK_1, LOAD_1, 1);
LedControl lc2 = LedControl(DIN_2, CLK_2, LOAD_2, 1);
byte decena(int suma) {

  return (floor(suma / 10) + 48);
}

int unidad(int suma) {

  return ((suma % 10) + 48);
}


void setup() {

  Wire.begin();

#ifdef SCREEN
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(3);
  TFTscreen.line(24, 42, 135, 42);
  TFTscreen.line(24, 84, 135, 84);
  TFTscreen.line(58, 8, 58, 120);
  TFTscreen.line(100, 8, 100, 120);
#endif

  lc.shutdown(0, false);
  lc.setIntensity(0, 15);
  lc.clearDisplay(0);
  lc2.shutdown(0, false);
  lc2.setIntensity(0, 15);
  lc2.clearDisplay(0);

  RS485.begin(9600);
}

void loop() {

  byte receivedData_1[] = { 0, 0, 0 };
  byte receivedData_2[] = { 0, 0, 0 };
  byte receivedData_3[] = { 0, 0, 0 };

  Wire.requestFrom(8, 3);
  int index_1 = 0;
  while (Wire.available() && index_1 < 3) {
    receivedData_1[index_1++] = Wire.read();
  }

  Wire.requestFrom(9, 3);
  int index_2 = 0;
  while (Wire.available() && index_2 < 3) {
    receivedData_2[index_2++] = Wire.read();
  }

  Wire.requestFrom(10, 3);
  int index_3 = 0;
  while (Wire.available() && index_3 < 3) {
    receivedData_3[index_3++] = Wire.read();
  }

  ficha[0] = receivedData_1[0];
  ficha[1] = receivedData_1[1];
  ficha[2] = receivedData_1[2];
  ficha[3] = receivedData_2[0];
  ficha[4] = receivedData_2[1];
  ficha[5] = receivedData_2[2];
  ficha[6] = receivedData_3[0];
  ficha[7] = receivedData_3[1];
  ficha[8] = receivedData_3[2];
  ficha[9] = 0;

  RS485.write(ficha, 10);
  delay(DELAY_COM);
  RS485.flush();


  //uint16_t ficha[] = {1,2,3,4,5,6,7,8,9} ;

  int8_t suma_1H[9];
  int8_t suma_2H[9];
  int8_t suma_3H[9];
  int8_t suma_1V[9];
  int8_t suma_2V[9];
  int8_t suma_3V[9];

  int sum_1H = ficha[0] + ficha[1] + ficha[2];
  int sum_2H = ficha[3] + ficha[4] + ficha[5];
  int sum_3H = ficha[6] + ficha[7] + ficha[8];
  int sum_1V = ficha[0] + ficha[3] + ficha[6];
  int sum_2V = ficha[1] + ficha[4] + ficha[7];
  int sum_3V = ficha[2] + ficha[5] + ficha[8];

  itoa(sum_1H, suma_1H, 10);
  itoa(sum_2H, suma_2H, 10);
  itoa(sum_3H, suma_3H, 10);
  itoa(sum_1V, suma_1V, 10);
  itoa(sum_2V, suma_2V, 10);
  itoa(sum_3V, suma_3V, 10);

#ifdef SCREEN
  TFTscreen.drawChar(32, 14, ficha[0] + 48, color, 0, tam);
  TFTscreen.drawChar(72, 14, ficha[1] + 48, color, 0, tam);
  TFTscreen.drawChar(112, 14, ficha[2] + 48, color, 0, tam);
  TFTscreen.drawChar(32, 53, ficha[3] + 48, color, 0, tam);
  TFTscreen.drawChar(72, 53, ficha[4] + 48, color, 0, tam);
  TFTscreen.drawChar(112, 53, ficha[5] + 48, color, 0, tam);
  TFTscreen.drawChar(32, 92, ficha[6] + 48, color, 0, tam);
  TFTscreen.drawChar(72, 92, ficha[7] + 48, color, 0, tam);
  TFTscreen.drawChar(112, 92, ficha[8] + 48, color, 0, tam);

  TFTscreen.stroke(0, 0, 255);
  TFTscreen.setTextSize(1);
  TFTscreen.text(suma_1H, 135, 19);
  TFTscreen.text(suma_2H, 135, 61);
  TFTscreen.text(suma_3H, 135, 103);
  TFTscreen.text(suma_1V, 33, 121);
  TFTscreen.text(suma_2V, 73, 121);
  TFTscreen.text(suma_3V, 113, 121);
  TFTscreen.setTextSize(3);
#endif

  lc.setChar(0, 0, decena(sum_1H), false);
  lc.setChar(0, 1, unidad(sum_1H), false);

  lc.setChar(0, 3, decena(sum_2H), false);
  lc.setChar(0, 4, unidad(sum_2H), false);

  lc.setChar(0, 5, decena(sum_3H), false);
  lc.setChar(0, 6, unidad(sum_3H), false);

  lc.setChar(0, 2, '8', false);

  lc2.setChar(0, 0, decena(sum_1V), false);
  lc2.setChar(0, 1, unidad(sum_1V), false);

  lc2.setChar(0, 3, decena(sum_2V), false);
  lc2.setChar(0, 4, unidad(sum_2V), false);

  lc2.setChar(0, 5, decena(sum_3V), false);
  lc2.setChar(0, 6, unidad(sum_3V), false);

  lc2.setChar(0, 2, '8', false);

  delay(DELAY);
}