//
//  hifa.cpp
//  vectorGraphicsExample
//
//  Created by Mirko Petrovich on 11/5/23.
//

#include "hifa.h"

hifa::hifa() {
    
}

void hifa::setup() {
    posicion.set(960,540);
    velocidad.set(0,0);
    bum = 0.2;
    diametro = 3;
    x1 = 0;
    x2 = 1;
    y1 = 0.;
    y2 = 1;
}

void hifa::update() {
    posicion += velocidad;
    ofVec2f bump;
    bump.set(x1+ofRandom(-x2,x2),ofRandom(-y2,y2)+y1);
    bump *= bum;
    velocidad += bump;
    velocidad.normalize();
}
