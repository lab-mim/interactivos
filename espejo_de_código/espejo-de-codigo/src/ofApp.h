#pragma once

#include "ofMain.h"
#include "ofxGui.h"


// This example is  based on the Processing "ASCII Video" example by Ben Fry
// and it is designed to demonstrate how to re-interpret live video as text
// to make it look like some good old ASCII art!
//
// For more information regarding this example take a look at the README.md.

class ofApp : public ofBaseApp{
    
    public:
        
        void setup();
        void update();
        void draw();
        
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
        
        ofVideoGrabber vidGrabber;
        int camWidth;
        int camHeight;
    
        string asciiCharacters, set_1, set_2, set_3, set_4, set_5, set_6, set_7;
        ofTrueTypeFont font;
    
    
    int acolor;
        ofColor color;
    
    bool show_gui, bn, blanco, show_cam;
    
    ofxPanel gui;
    ofParameter<int> paso_x, paso_y, ancho, alto, ancho_, alto_, size, gap, gapp , sep_banda_x, sep_banda_y;
    ofParameter<float> zoom,curva,curva2;
    ofParameter<int> ss1, ss2, ss3, ss4, ss5, ss6, ss7, ss8;
    ofParameter<int> frame_ancho, frame_alto;
    
    ofImage mapa;
    float banda_ancho, banda_alto, frames;
    int n_banda;
    int modo, figura;
    
    ofParameter<float> linea;
    ofParameter<int> circulo;
};


