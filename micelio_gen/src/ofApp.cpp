#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetLogLevel(OF_LOG_SILENT);
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    ofShowCursor();
    gui = true;
    ofSetBackgroundAuto(true);
    ofSetVerticalSync(true);
    ofDisableArbTex();
    shaderX.load("shaderBlurX");
    shaderY.load("shaderBlurY");

    // --------------  box2d settings  ----------------------
    gY = 0;
    box2d.init();
    box2d.setGravity(0.0,gY);
    box2d.registerGrabbing();

    // ----------------------------------------------------------------
    fb_x = 1920;
    fb_y = 1080;
    offset_fb_y = 0;
    allocate_fb();
    gui_settings();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (gravedadY!=gY) {
        box2d.setGravity(gravedadX,gravedadY);
        gY=gravedadY;
    }
   
    tet = morphogenesis(micelio_player_1,lifetime);
    
    box2d.update();
    
    ofRemove(micelio_player_1, ofxBox2dBaseShape::shouldRemoveOffScreen);
    
    fb_player_1.begin();
    draw_fb_player(micelio_player_1);
    fb_player_1.end();
}




//--------------------------------------------------------------
void ofApp::draw(){
  
    ofBackground(0,0,0);
    gaussian_blur();
    ofSetColor(255,255,255,fade1);               // dibuja framebuffers de micelios
    fb_blur_Y1.draw(0,offset_fb_y);
    ofSetColor(255,255,255,255);
    if (gui) {
        gui1.draw();
    }
    reporte();
    
    if(boton) {
        micelio_player_1.clear();
        fb_player_1.begin();
        ofClear(0,0,0,0);
        fb_player_1.end();
        fb_blur_X1.begin();
        ofClear(0,0,0,0);
        fb_blur_X1.end();
        fb_blur_Y1.begin();
        ofClear(0,0,0,0);
        fb_blur_Y1.end();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'g') gui=!gui ;
    if (key == 'i') info=!info ;
    if (key == 'f') ofHideCursor();
    if (key == 'm') ofShowCursor();
    if (key == 's') {
        micelio_player_1.clear();
        fb_player_1.begin();
        ofClear(0,0,0,0);
        fb_player_1.end();
        fb_blur_X1.begin();
        ofClear(0,0,0,0);
        fb_blur_X1.end();
        fb_blur_Y1.begin();
        ofClear(0,0,0,0);
        fb_blur_Y1.end();
    }
    if (key == 'a') {
        vsync=!vsync;
        ofSetVerticalSync(vsync);
    }
    if (key == 'z') {
      
        for (int i=0;i<init;i++) {
            auto particle = make_shared<CustomParticle>(box2d.getWorld(), mouseX ,mouseY-offset_fb_y); //
            particle->setRadius(tamano1);
            //particle->color.set(255,255,255,transparencia);
            micelio_player_1.push_back(particle);
        }
    }
}

void ofApp::mouseReleased(int x, int y, int button){
    
    
      
        for (int i=0;i<init;i++) {
            auto particle = make_shared<CustomParticle>(box2d.getWorld(), x ,y-offset_fb_y); //
            particle->setRadius(tamano1);
            //particle->color.set(255,255,255,transparencia);
            micelio_player_1.push_back(particle);
        }
    

}



int ofApp::morphogenesis(vector<shared_ptr<CustomParticle>> &micelio_player, int lifetime) {
    
    int ret= 0;
    bool borra_micelio = false;                                 // flag para limpiar micelio al fin del loop
    int size = micelio_player.size();                           // asignamos tamaño antes del loop ya que lo modificaremos
    
    if (size) {                                                 // si el micelio tiene hifas ejecuta el loop
        
        for (int i=0;i<size;i++) {
            ofVec2f bump;                                       // creamos vector 2f temporal para bump
            bump.set(ofRandom(-1,1),ofRandom(-1,1));            // le asignamos valores random
            bump *= random;                                     // multiplicamos for factor random
            bump += micelio_player[i]->getVelocity();           // sumamos velocidad de hifa[i]
            bump.normalize();                                   // normaliza
            
            if (size<lifetime)   {             
                micelio_player[i]->setRadius(tamano1);// si es menor al máximo de hifas
                micelio_player[i]->setVelocity(bump.x,bump.y);  //
                
              //if (ofRandom(0,1)<0.5) micelio_player[i]->addAttractionPoint(mouseX,mouseY-(ofRandom(3)*100),0.0001);
                
                if (ofRandom(0,1)<mitosis) {                      // factor de mitosis
                    auto nueva = make_shared<CustomParticle>(box2d.getWorld(), micelio_player[i]->getPosition().x,micelio_player[i]->getPosition().y);
                        //nueva->color.set(255,255,255,transparencia);
                    //nueva->setRadius(tamano1);

                    micelio_player.push_back(nueva);
                }
            }
            else {
                borra_micelio = true;
                ret = 1;
            }
        }
        if (borra_micelio) micelio_player.clear();
    }
    return(ret);
}

void ofApp::draw_fb_player(vector <shared_ptr<CustomParticle>> &micelio_player) {
    for (auto &particle : micelio_player) {
        
        particle->color.set(color);
        particle->draw();
    }
}

void ofApp::gaussian_blur() {
    
    fb_blur_X1.begin();
    ofSetColor(255);
    shaderX.begin();
    shaderX.setUniformTexture("tex0", fb_player_1.getTexture(),1);
    shaderX.setUniform1f("blurAmnt", blur);
    shaderX.setUniform1f("texwidth", fb_x);
    fb_player_1.draw(0,0);
    shaderX.end();
    fb_blur_X1.end();
    
    fb_blur_Y1.begin();
    ofSetColor(255);
    shaderY.begin();
    shaderY.setUniformTexture("tex0", fb_blur_X1.getTexture(),1);
    shaderY.setUniform1f("blurAmnt", blur);
    shaderY.setUniform1f("texheight", fb_y);
    fb_blur_Y1.draw(0,0);
    shaderY.end();
    fb_blur_Y1.end();
    
}

void ofApp::allocate_fb(){
    
    //  -------------- framebuffer settings -----------------------
    
    fb_player_1.allocate(fb_x,fb_y,GL_RGBA);
    fb_player_1.begin();
    ofClear(0,0,0,0);
    fb_player_1.end();
    
    fb_blur_X1.allocate(fb_x,fb_y,GL_RGBA);
    fb_blur_X1.begin();
    ofClear(0,0,0,0);
    fb_blur_X1.end();
    
    fb_blur_Y1.allocate(fb_x,fb_y,GL_RGBA);
    fb_blur_Y1.begin();
    ofClear(0,0,0,0);
    fb_blur_Y1.end();
    
    // ---------------------------------------------------------------
}

void ofApp::gui_settings() {
    // ------------------ gui settings -------------------------------
    gui1.setup();
    gui1.add(gravedadX.set("gravedad X",0.f,-2.0,2.0));
    gui1.add(gravedadY.set("gravedad Y",gY,-2.0,2.0));
    gui1.add(blur.set("blur",0.6,0.0,2.0));
    gui1.add(random.set("random",0.1, 0.0, 1.0));
    gui1.add(fade1.set("fade",255, 0, 255));
    gui1.add(tamano1.set("radio",0.3, 0.0, 3.0));
    gui1.add(init.set("init",150, 1, 150));
    gui1.add(mitosis.set("mitosis",0.001, 0.0, 0.01));
    gui1.add(lifetime.set("lifetime",300, 100, 5000));
    gui1.add(boton.setup("borra"));
    gui1.add(color.setup("color", ofColor(255, 255, 255), ofColor(0, 0), ofColor(255, 255)));

}

void ofApp::reporte() {
    if (info) {
        ofPushMatrix();
        ofTranslate(1200,10);
        ofDrawBitmapString("x: "+ ofToString(mouseX),0,10);
        ofDrawBitmapString("y: "+ ofToString(mouseY),0,20);
        ofDrawBitmapString("hifas: "+ ofToString(micelio_player_1.size()),0,30);
        ofPopMatrix();
    }
}




