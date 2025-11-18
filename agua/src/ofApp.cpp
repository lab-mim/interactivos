#include "ofApp.h"

void ofApp::setup() {
    ofBackground(0);
    ofDisableArbTex();
    
    shadertoy.load("shaders/tdm_Seascape.frag");
    ofSetFrameRate(60);
    shadertoy.setUseMouse(true);
    
    shader.load("shadersGL3/shader");
    waterMovie.load("movies/agua.mp4");
    waterMovie.play();
    
    fbo.allocate(3840,1200,GL_RGB);
    fbo.begin();
    ofClear(0,0,0,0);
    fbo.end();

    
    gui.setup();
    gui.add(center.set("centro", 0.142, 0, 0.2));
    gui.add(gamma.set("gamma", 0.38, 0.0, 1.0));
    gui.add(fade.set("fade", 0.063, 0.0, 0.1));
    
    test = 1;
}

void ofApp::update() {
    waterMovie.update();
}

void ofApp::draw() {
    fbo.begin();
    if (test) shadertoy.draw(0,0,3840,1200);
    else waterMovie.draw(0,1200,3840,-1200);
    //shadertoy.draw(0,0, 3840, 1200);
    fbo.end();
    shader.begin();
    shader.setUniformTexture("tex0", fbo.getTexture(), 1);
    shader.setUniform1f("center", center);
    shader.setUniform1f("gamma", gamma);
    shader.setUniform1f("fade", fade);
    shader.setUniform2f("resolution", 3840, 1200);
    //shadertoy.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    waterMovie.draw(0,1200,3840,-1200);
    shader.end();
   
    if (show_gui) {
        gui.draw();
        ofShowCursor();
    }
    else ofHideCursor();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'f') ofToggleFullscreen();
    if (key == 't') test=!test;
    if (key == 'g') show_gui=!show_gui;

	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
