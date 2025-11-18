//
//  hifa.h
//  vectorGraphicsExample
//
//  Created by Mirko Petrovich on 11/5/23.
//

#ifndef hifa_h
#define hifa_h

#include "ofMain.h"

class hifa {
    
public:
    
    void setup();
    void update();
    
    ofVec2f posicion;
    ofVec2f velocidad;
    float diametro;
    float bum;
    float x1, x2, y1, y2;
    
    vector <glm::vec3> puntos;
    
    hifa();
};


#endif /* hifa_h */
