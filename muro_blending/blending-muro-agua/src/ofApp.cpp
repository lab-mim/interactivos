#include "ofApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    show_gui = false;
    test = false;
    
    ofSetFrameRate(24);
    dialelo.load("movies/Dialelo_3360x1200.mp4");
    dialelo.play();
    ofEnableArbTex();
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    shader.load("shadersGL2/shader");
    fbo.allocate(3840,1200 );
    fbo.begin();
    ofClear(0,0,0,255);
    fbo.end();
    gui.setup();
    gui.add(center.set("centro", 240., 0., 240.));
    gui.add(gamma.set("gamma", 0.62207, 0.0, 5.0));
    gui.add(fade.set("fade", 0.196941, 0.1, 0.2));

}
//--------------------------------------------------------------
void testApp::update(){
    
    dialelo.update();
}
//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    ofEnableArbTex();
    
    fbo.begin();;
    dialelo.draw(0,0,3360,1200);
    fbo.end();
    
    ofDisableArbTex();
    fbo.getTexture().bind();
    
    shader.begin();
    shader.setUniform1f("center", center);
    shader.setUniform1f("gamma", gamma);
    shader.setUniform1f("fade", fade);
    shader.setUniform2f("resolution", 3360, 1200);
    fbo.draw(0,0,3840,1200);
    shader.end();
    
    if (show_gui) {
        gui.draw();
        ofShowCursor();
    }
    else ofHideCursor();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'f') ofToggleFullscreen();
    if (key == 't') {
        test=!test;
        if (test) dialelo.load("movies/patron.mov");
        else {
            dialelo.load("movies/Dialelo_3360x1200.mp4");
            dialelo.play();
        }
    }
        
        ;
    if (key == 'g') show_gui=!show_gui;

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
  
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}

void testApp::exit() {
   
}


