#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

// ------------------------------------------------- a simple extended box2d circle
class CustomParticle : public ofxBox2dCircle {
public:
    ofColor color;
    int alpha;
    
    CustomParticle(b2World * world, float x, float y) {
        setPhysics(1, 0, 10);
        setup(world, x, y, 1);
    }
        
    
    void draw() {
        float radius = getRadius();
        
        ofPushMatrix();
        ofTranslate(getPosition());
        ofSetColor(color);
        ofNoFill();
        ofDrawCircle(0, 0, radius);
        ofPopMatrix();
    }
};

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void keyPressed(int key) override;
    void mouseReleased(int x, int y, int button) override;
    
    void borra();
    void gaussian_blur();
    void allocate_fb();
    int morphogenesis(vector <shared_ptr<CustomParticle>> &micelio_player, int lifetime) ;
    void draw_fb_player(vector <shared_ptr<CustomParticle>> &micelio_player) ;
    void reporte();
    void gui_settings();
    ofShader shaderX, shaderY;
    ofxBox2d box2d;
    vector    <shared_ptr<CustomParticle>> micelio_player_1;
    ofFbo fb_player_1, fb_blur_X1, fb_blur_Y1;
    ofxPanel gui1;
    ofParameter<float> random, blur, gravedadX, gravedadY;
    ofParameter<int> fade1, init, lifetime;
    ofParameter<float> tamano1,mitosis;
    ofxColorSlider color;
    ofxButton boton;
    int fb_x,fb_y,offset_fb_y;
    float gY;
    bool vsync,info,gui;
    int tet;
   
    
    
    
};
