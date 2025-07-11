#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

// ARDUINO MEGA  QUE VA A LA MURALLA   VERSION ACTUAL MAS IMPORTANTE 11-03-2025

#define PIN 8 // para ESP32 cambiar a pin 0
#define DELAYVAL 200
//#define FONDO_BLANCO

#define NUMPIXELS 243
#define FILA 9
#define OFFSET_H 0
#define OFFSET_V 0
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
SoftwareSerial RS485(10,9); // RX, TX

//uint8_t dato[10]; // dato RS485
unsigned char ficha[10]; // Array to store received data
unsigned char ficha_status[] = {0,0,0,0,0,0,0,0,0};
int bytesRead = 0;

unsigned char masaje[] = {0,0,0,0,0,0,0,0,0}; // estado de los cuadrados 3x3
unsigned char orden[] = {0,1,2,3,4,5,6,7,8}; // orden de encendido de los cuadrados 3x3

int suma = 0;
int color = 0;

// estado de todas las casillas
unsigned char casillas[] = {
0, 1, 2, 3, 4, 5, 6, 7, 8,
0, 1, 2, 3, 4, 5, 6, 7, 8,
0, 1, 2, 3, 4, 5, 6, 7, 8,
0, 1, 2, 3, 4, 5, 6, 7, 8,
0, 1, 2, 3, 4, 5, 6, 7, 8,
0, 1, 2, 3, 4, 5, 6, 7, 8,
0, 1, 2, 3, 4, 5, 6, 7, 8,
0, 1, 2, 3, 4, 5, 6, 7, 8,
0, 1, 2, 3, 4, 5, 6, 7, 8
};

// mapa de leds calugas 9x9

const uint16_t XYTable[] = {
24, 23, 18, 17, 12, 11, 6, 5, 0,
25, 22, 19, 16, 13, 10, 7, 4, 1,
26, 21, 20, 15, 14, 9, 8, 3, 2,
27, 32, 33, 38, 39, 44, 45, 50, 51,
28, 31, 34, 37, 40, 43, 46, 49, 52,
29, 30, 35, 36, 41, 42, 47, 48, 53,
78, 77, 72, 71, 66, 65, 60, 59, 54,
79, 76, 73, 70, 67, 64, 61, 58, 55,
80, 75, 74, 69, 68, 63, 62, 57, 56
};



// index color casilla
const uint8_t icolor[] = {
0, 0, 255, // 0 - azul
0, 255, 0, // 1 - verde
255, 0, 0, // 2 - rojo
255, 255, 0, // 3 - amarillo
255, 0, 255, // 4 - magenta
0, 255, 255 // 5 - cyan
};

// index color fondo
const uint8_t ifondo[] = {
0, 0, 0, // 0 - negro
200, 200, 200, // 1 - blanco
100, 100, 100 // 2 - blanco 50%
};


bool nuevo = false;


void setup() {
pixels.begin();
pixels.clear();
RS485.begin(9600);

}

void loop() {

  pixels.clear();

  if (RS485.available()) {
    RS485.readBytes(ficha,10);
    nuevo = true;
  }

  if (nuevo) {
    for (int i=0;i<9;i++) {
     if (ficha[9]==i+1) {
       ficha_status[i]=0;
       ficha[9] = 0;
     }

    suma = ficha[0]+ficha[1]+ficha[2]+ficha[3]+ficha[4]+ficha[5]+ficha[6]+ficha[7]+ficha[8];
    if (!suma) color++;
    if (color>5) color = 1;

   }

   for (int i=0;i<9;i++) {
     if (ficha[i]<10) {
       if (ficha[i] != ficha_status[i]) {
         casilla_shuffle(i);
         ficha_status[i] = ficha[i];
       }
     casilla(ficha[i],i,color-1,2);
     }
   }

    pixels.show();
    nuevo=false;
    }

  delay(DELAYVAL);
} // FIN DEL LOOP

// FUNCIÓN PARA MAPEAR LEDS
uint16_t XY(uint16_t x, uint16_t y) {
uint16_t i = (y * FILA) + x;
uint16_t j = XYTable[i];
return j;
}
// casilla (numero, cuadrado, color, fondo);
void casilla (uint8_t n, uint8_t q, uint8_t c, uint8_t f) {

uint8_t casilleros[9];
for (int i=0;i<9;i++) casilleros[i]=casillas[i+(q*9)];
uint8_t of_h = (q%3)*3;
uint8_t of_v = floor(q/3)*3;
uint8_t r = icolor[3*c];
uint8_t g = icolor[3*c+1];
uint8_t b = icolor[3*c+2];
uint8_t r_ = ifondo[3*f];
uint8_t g_ = ifondo[3*f+1];
uint8_t b_ = ifondo[3*f+2];

for (int i=0;i<9;i++) {
uint8_t h=i%3;
uint8_t v=floor(i/3);


if (casilleros[i]<n) {
pixels.setPixelColor(XY(h+of_h,v+of_v)*3, pixels.Color(r,g,b));
pixels.setPixelColor(XY(h+of_h,v+of_v)*3+1, pixels.Color(r,g,b));
pixels.setPixelColor(XY(h+of_h,v+of_v)*3+2, pixels.Color(r,g,b));
}
else {
pixels.setPixelColor(XY(h+of_h,v+of_v)*3, pixels.Color(r_,g_,b_)) ;
pixels.setPixelColor(XY(h+of_h,v+of_v)*3+1, pixels.Color(r_,g_,b_)) ;
pixels.setPixelColor(XY(h+of_h,v+of_v)*3+2, pixels.Color(r_,g_,b_)) ;
}

}
}

// Fisher-Yates shuffle
void urnShuffle(uint8_t arr[]) {
// Seed the random number generator
randomSeed(analogRead(0)); // Use an unconnected analog pin to generate entropy for seeding

for (int i = 8; i > 0; i--) {
// Get a random index from 0 to i
int j = random(0, i + 1);
// Swap the elements at index i and j
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}

void casilla_shuffle(uint8_t q) {
uint8_t casilleros[9];
for (int i=0;i<9;i++) casilleros[i]=casillas[i+(q*9)];
urnShuffle(casilleros);
for (int i=0;i<9;i++) casillas[i+(q*9)]=casilleros[i];
}
