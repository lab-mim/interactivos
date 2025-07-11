#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>

//#define DEBUG

#define RST_PIN 9
#define SS_1_PIN 7  // 5
#define SS_2_PIN 8  // 6
#define SS_3_PIN 10  // 7
#define NR_OF_READERS 3
unsigned char lectores[] = { 0, 0, 0 };
byte ssPins[] = { SS_1_PIN, SS_2_PIN, SS_3_PIN };
MFRC522 mfrc522[NR_OF_READERS];
byte cola;

int nficha;

void setup() {

  SPI.begin();
  for (uint8_t reader = 0; reader < NR_OF_READERS; reader++) {
    mfrc522[reader].PCD_Init(ssPins[reader], RST_PIN);
  }
  Wire.begin(10);
  Wire.onRequest(sendEvent);

  #ifdef DEBUG
  Serial.begin(9600);
  #endif
}


void loop() {



  for (uint8_t reader = 0; reader < NR_OF_READERS; reader++) {
    if (mfrc522[reader].PICC_IsNewCardPresent() && mfrc522[reader].PICC_ReadCardSerial()) {
      ficha(mfrc522[reader].uid.uidByte, mfrc522[reader].uid.size, reader);
    } 
    else if (!mfrc522[reader].PICC_IsNewCardPresent()) {
      lectores[reader] = 0;
      mfrc522[reader].PICC_HaltA();
    }

  }

#ifdef DEBUG
  for (int i = 0; i < 3; i++) {
    Serial.print(lectores[i]);
    Serial.print(" - ");
  }
  Serial.println("");
#endif

  delay(200);
}

void ficha(byte *buffer, byte bufferSize, int lector) {

  cola = buffer[bufferSize - 2];

  if (cola == 0x74) nficha = 1;
  if (cola == 0xC6) nficha = 2;
  if (cola == 0x5C) nficha = 3;
  if (cola == 0x97) nficha = 4;
  if (cola == 0x9E) nficha = 5;
  if (cola == 0xF7) nficha = 6;
  if (cola == 0xE0) nficha = 7;
  if (cola == 0xB8) nficha = 8;
  if (cola == 0xAF) nficha = 9;


  lectores[lector] = nficha;
}

void sendEvent() {
  byte dataToSend[3] = { 1, 2, 8 };  // Example data
  Wire.write(lectores, 3);           // Send 3 bytes to master
}
