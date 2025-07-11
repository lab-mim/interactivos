#include <TFT.h>  
#include <SPI.h>
#include <Wire.h>

#define dc   8
#define rst  9
#define cs   10

TFT TFTscreen = TFT(cs, dc, rst);

char s1[4];
char s2[4];
char s3[4];
char s4[4];
char s5[4];
char s6[4];
char s7[4];
char s8[4];
char s9[4];

void setup() {

  Wire.begin();                          // Inicia i2c
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);
  TFTscreen.stroke(255, 255, 255);
  TFTscreen.setTextSize(4);

}

void loop() {

  byte receivedData_1[] = { 1, 2, 3 };
  byte receivedData_2[] = { 4, 5, 6 };
  byte receivedData_3[] = { 7, 8, 9 };

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

String valor_1 = String(receivedData_1[0]);
String valor_2 = String(receivedData_1[1]);
String valor_3 = String(receivedData_1[2]);
String valor_4 = String(receivedData_2[0]);
String valor_5 = String(receivedData_2[1]);
String valor_6 = String(receivedData_2[2]);
String valor_7 = String(receivedData_3[0]);
String valor_8 = String(receivedData_3[1]);
String valor_9 = String(receivedData_3[2]);

  TFTscreen.stroke(0,0,0);  

  TFTscreen.text(s1, 20, 10);
  TFTscreen.text(s2, 70, 10);
  TFTscreen.text(s3, 120, 10);
  TFTscreen.text(s4, 20, 50);
  TFTscreen.text(s5, 70, 50);
  TFTscreen.text(s6, 120, 50);
  TFTscreen.text(s7, 20, 90);
  TFTscreen.text(s8, 70, 90);
  TFTscreen.text(s9, 120, 90);
  

valor_1.toCharArray(s1, 4);
valor_2.toCharArray(s2, 4);
valor_3.toCharArray(s3, 4);
valor_4.toCharArray(s4, 4);
valor_5.toCharArray(s5, 4);
valor_6.toCharArray(s6, 4);
valor_7.toCharArray(s7, 4);
valor_8.toCharArray(s8, 4);
valor_9.toCharArray(s9, 4);


TFTscreen.stroke(255, 255, 255);
  
  TFTscreen.text(s1, 20, 10);
  TFTscreen.text(s2, 70, 10);
  TFTscreen.text(s3, 120, 10);
  TFTscreen.text(s4, 20, 50);
  TFTscreen.text(s5, 70, 50);
  TFTscreen.text(s6, 120, 50);
  TFTscreen.text(s7, 20, 90);
  TFTscreen.text(s8, 70, 90);
  TFTscreen.text(s9, 120, 90);
  delay(200);

}

