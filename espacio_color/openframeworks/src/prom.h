//
//  prom.h
//  smoothie
//
//  Created by Mirko Petrovich on 28-01-24.
//

#ifndef prom_h
#define prom_h

#include "ofMain.h"

class prom {
public:
    
    void setup(int tam);
    void update();
    
    glm::vec2 calcula(glm::vec2 valores);
    
    deque<glm::vec2> buffer;
    
    int tamano;
    
    
    prom();
    
};


#endif /* prom_h */

