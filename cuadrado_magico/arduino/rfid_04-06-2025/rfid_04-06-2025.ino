#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>


unsigned char lectores[] = { 0, 0, 0 };
MFRC522 sensor_1, sensor_2, sensor_3;  

int contador ;
int status = 0;
int status_2 = 0;
int status_3 = 0;
int lifetime = 0;
int lifetime_2 = 0;
int lifetime_3 = 0;
int ficha_1 = 0;
int ficha_2 = 0;
int ficha_3 = 0;

byte bs_1;
byte bs_2;
byte bs_3;

void setup() {

  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin();        // Init SPI bus
    sensor_1.PCD_Init(7, MFRC522::UNUSED_PIN);
    sensor_1.PCD_DumpVersionToSerial();
    sensor_2.PCD_Init(8, MFRC522::UNUSED_PIN);
    sensor_2.PCD_DumpVersionToSerial();
    sensor_3.PCD_Init(10, MFRC522::UNUSED_PIN);
    sensor_3.PCD_DumpVersionToSerial();

  Wire.begin(10);
  Wire.onRequest(sendEvent);
}

void loop() {


// SENSOR 1
if (sensor_1.PICC_IsNewCardPresent()) {
  if (sensor_1.PICC_ReadCardSerial()) {
    lee_1(sensor_1.uid.uidByte, sensor_1.uid.size);
    status = 1;
  }
}
else {
  sensor_1.PICC_HaltA();
  sensor_1.PCD_StopCrypto1(); 
  status = 0;
}

if (status) {
  lifetime = 0;
}
else {
  lifetime++;
    if (lifetime>2) {
    bs_1 = 0;
    lifetime = 0;
  }
}
// FIN SENSOR 1

// SENSOR 2
if (sensor_2.PICC_IsNewCardPresent()) {
  if (sensor_2.PICC_ReadCardSerial()) {
    lee_2(sensor_2.uid.uidByte, sensor_2.uid.size);
    status_2 = 1;
  }
}
else {
  sensor_2.PICC_HaltA();
  sensor_2.PCD_StopCrypto1(); 
  status_2 = 0;
}

if (status_2) {
  lifetime_2 = 0;
}
else {
  lifetime_2++;
    if (lifetime_2>2) {
    bs_2 = 0;
    lifetime_2 = 0;
  }
}
// FIN SENSOR 2

// SENSOR 3
if (sensor_3.PICC_IsNewCardPresent()) {
  if (sensor_3.PICC_ReadCardSerial()) {
    lee_3(sensor_3.uid.uidByte, sensor_3.uid.size);
    status_3 = 1;
  }
}
else {
  sensor_3.PICC_HaltA();
  sensor_3.PCD_StopCrypto1(); 
  status_3 = 0;
}

if (status_3) {
  lifetime_3 = 0;
}
else {
  lifetime_3++;
    if (lifetime_3>2) {
    bs_3 = 0;
    lifetime_3 = 0;
  }
}
// FIN SENSOR 3

  if (bs_1 == 0) ficha_1 = 0;
  if (bs_1 == 0x74) ficha_1 = 1;
  if (bs_1 == 0xC6) ficha_1 = 2;
  if (bs_1 == 0x5C) ficha_1 = 3;
  if (bs_1 == 0x97) ficha_1 = 4;
  if (bs_1 == 0x9E) ficha_1 = 5;
  if (bs_1 == 0xF7) ficha_1 = 6;
  if (bs_1 == 0xE0) ficha_1 = 7;
  if (bs_1 == 0xB8) ficha_1 = 8;
  if (bs_1 == 0xAF) ficha_1 = 9;

  if (bs_2 == 0) ficha_2 = 0;
  if (bs_2 == 0x74) ficha_2 = 1;
  if (bs_2 == 0xC6) ficha_2 = 2;
  if (bs_2 == 0x5C) ficha_2 = 3;
  if (bs_2 == 0x97) ficha_2 = 4;
  if (bs_2 == 0x9E) ficha_2 = 5;
  if (bs_2 == 0xF7) ficha_2 = 6;
  if (bs_2 == 0xE0) ficha_2 = 7;
  if (bs_2 == 0xB8) ficha_2 = 8;
  if (bs_2 == 0xAF) ficha_2 = 9;

  if (bs_3 == 0) ficha_3 = 0;
  if (bs_3 == 0x74) ficha_3 = 1;
  if (bs_3 == 0xC6) ficha_3 = 2;
  if (bs_3 == 0x5C) ficha_3 = 3;
  if (bs_3 == 0x97) ficha_3 = 4;
  if (bs_3 == 0x9E) ficha_3 = 5;
  if (bs_3 == 0xF7) ficha_3 = 6;
  if (bs_3 == 0xE0) ficha_3 = 7;
  if (bs_3 == 0xB8) ficha_3 = 8;
  if (bs_3 == 0xAF) ficha_3 = 9;


delay(50);
lectores[0] = ficha_1;
lectores[1] = ficha_2;
lectores[2] = ficha_3;

Serial.print(ficha_1);
Serial.print(" - ");
Serial.print(ficha_2);
Serial.print(" - ");
Serial.println(ficha_3);


}

/**
 * Helper routine to dump a byte array as hex values to Serial.
 */
void lee_1(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    bs_1 = buffer[2];
  }
}

void lee_2(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    bs_2 = buffer[2];
  }
}

void lee_3(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    bs_3 = buffer[2];
  }
}

void sendEvent() {
  byte dataToSend[3] = { 1, 2, 8 };  // Example data
  Wire.write(lectores, 3);           // Send 3 bytes to master
}
