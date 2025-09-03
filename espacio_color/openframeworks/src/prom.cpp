//
//  prom.cpp
//  smoothie
//
//  Created by Mirko Petrovich on 28-01-24.
//

//#include "stdio.h"
#include "prom.h"

prom::prom() {
    
}

void prom::setup(int tam) {
    tamano = tam;
    glm::vec2 a(0,0);
    for (int i=0;i<tamano;i++) buffer.push_back(a);
    
}

void prom::update() {
   
    }
    

glm::vec2 prom::calcula(glm::vec2 valores) {
    buffer.pop_front();
    buffer.push_back(valores);
    glm::vec2 resultado;
    for (int i=0; i<tamano;i++) resultado +=buffer[i];
    return(resultado/tamano);
    
    
    
}
