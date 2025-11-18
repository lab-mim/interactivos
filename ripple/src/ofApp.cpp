#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void testApp::setup(){

    oneshot = true;
    texto_fade = 6000;
    texto = 0;
    
    // Font Mirador
    //********************************************************
    ofTrueTypeFont::setGlobalDpi(72);
    Mirador.load("MiradorVF.ttf", 30, true, true);
    Mirador.setLineHeight(34.0f);
    Mirador.setLetterSpacing(1.035);
    //********************************************************
    
    ofEnableArbTex();
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    
    rip.allocate(3360,1200);
    bounce.allocate(3360,1200);
    
    ofImage fondo;
    fondo.load("blanco.png");
    bounce.setTexture(fondo.getTexture(), 1);
    
    shader.load("shadersGL2/shader");
    
    fbo.allocate(3840,1200 );
    fbo.begin();
    ofClear(0,0,0,255);
    fbo.end();
    
    kinect.setRegistration(false);
    kinect2.setRegistration(false);
    
    kinect.init();
    kinect2.init();
    
    kinect.open();
    kinect2.open();

    colorImg.allocate(kinect.width, kinect.height);
    grayImage.allocate(kinect.width, kinect.height);
    grayThreshNear.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    grayImage2.allocate(kinect.width, kinect.height);
    grayThreshNear2.allocate(kinect.width, kinect.height);
    grayThreshFar2.allocate(kinect.width, kinect.height);
    
  
    
    kinect.setCameraTiltAngle(-23);
    kinect.setCameraTiltAngle(-23);
    
    gui.setup();
    gui.add(center.set("centro", 240., 0., 240.));
    gui.add(gamma.set("gamma", 0.62207, 0.0, 5.0));
    gui.add(fade.set("fade", 0.196941, 0.1, 0.2));
    gui.add(damping.set("damping", 0.992, 0.8, 1.));
    gui.add(near.set("Near", 255, 0, 255));
    gui.add(far.set("Far", 22, 0, 255));
    gui.add(near2.set("Near2", 255, 0, 255));
    gui.add(far2.set("Far2", 52, 0, 255));
    gui.add(tamano.set("Diametro",13,1,200));
    gui.add(filo.set("Fill", false));
    gui.add(randiam.set("random",2,0,200));
    gui.add(rot.set("rojo",0.01,0.0,1.0));
    gui.add(grun.set("verde",0.02,0.0,1.0));
    gui.add(blau.set("azul",0.03,0.0,1.0));
    gui.add(tropfen.set("gota",1.0,0.1,10.0));
    gui.add(skip_frame.set("skip",3,0,60));
    gui.add(minArea.set("Min area", 10, 1, 100));
    gui.add(maxArea.set("Max area", 200, 1, 500));
    gui.add(threshold.set("Threshold", 128, 0, 255));
    gui.add(texto.set("Texto",0,0,255));
    gui.add(pos_K1_X.set("K1_X",0,0,3840));
    gui.add(pos_K1_Y.set("K1_Y",-348,-1200,1200));
    gui.add(K1_scale.set("K1_scale",2.54,1.0,5.0));
    gui.add(pos_K2_X.set("K2_X",1670,0,3840));
    gui.add(pos_K2_Y.set("K2_Y",-179,-1200,1200));
    gui.add(K2_scale.set("K2_scale",2.52,1.0,5.0));
   
}

//--------------------------------------------------------------
void testApp::update(){
 /*   // VIDEO **************************************************************************
    bool bNewFrame = false;

        vidPlayer.update();
        bNewFrame = vidPlayer.isFrameNew();
   
    if (bNewFrame){
        colorImgV.setFromPixels(vidPlayer.getPixels());
        grayImageV = colorImgV;
        if (bLearnBakground == true){
            grayBg = grayImageV;        // the = sign copys the pixels from grayImage into grayBg (operator overloading)
            bLearnBakground = false;
        }
        // take the abs value of the difference between background and incoming and then threshold:
        grayDiff.absDiff(grayBg, grayImageV);
        grayDiff.threshold(threshold);
        contourFinder.setMinAreaRadius(minArea);
        contourFinder.setMaxAreaRadius(maxArea);
        contourFinder.setThreshold(threshold);
        contourFinder.findContours(grayDiff);
        contourFinder2.findContours(grayDiff);
    }*/
    
    // ***********************************************************************************

    kinect.update();
    kinect2.update();
    
   if(kinect.isFrameNew()) {
        grayImage.setFromPixels(kinect.getDepthPixels());
        grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(near, true);
        grayThreshFar.threshold(far);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
        grayImage.flagImageChanged();
        contourFinder.setMinAreaRadius(minArea);
        contourFinder.setMaxAreaRadius(maxArea);
        contourFinder.setThreshold(threshold);
        grayImage.mirror(0,1);
        contourFinder.findContours(grayImage);
    }
    
    if(kinect2.isFrameNew()) {
        grayImage2.setFromPixels(kinect2.getDepthPixels());
        grayThreshNear2 = grayImage2;
        grayThreshFar2 = grayImage2;
        grayThreshNear2.threshold(near2, true);
        grayThreshFar2.threshold(far2);
        cvAnd(grayThreshNear2.getCvImage(), grayThreshFar2.getCvImage(), grayImage2.getCvImage(), NULL);
        grayImage2.flagImageChanged();
        contourFinder2.setMinAreaRadius(minArea);
        contourFinder2.setMaxAreaRadius(maxArea);
        contourFinder2.setThreshold(threshold);
        grayImage2.mirror(0,1);
        contourFinder2.findContours(grayImage2);
    }
    
    rip.damping = damping;
    rip.begin();
    
    if (filo) ofFill();
    else ofNoFill();
    
    /*bounce.rouge = rot;
    bounce.vert = grun;
    bounce.bleu = blau;*/
    //bounce.goutte = tropfen;
    
    int diametro_random = tamano+ofRandom(randiam)-(randiam/2);
   if (skip==0)
   {
        ofSetColor(255);
        //ofDrawEllipse(mouseX-(240-center+ofRandom(80)-40),mouseY+ofRandom(80)-40,diametro_random,diametro_random);
       
        //dibuja vértices quad_1
       ofPushMatrix();
        ofTranslate(pos_K1_X,pos_K1_Y);
        ofScale(K1_scale);
         int n = contourFinder.size();
         for(int i = 0; i < n; i++) {
         ofPolyline convexHull = toOf(contourFinder.getFitQuad(i));
         for (int i=0;i<int(convexHull.size());i++) {
         ofDrawCircle(convexHull.getVertices()[i].x,convexHull.getVertices()[i].y,diametro_random);
            }
        }
        ofPopMatrix();
            
        ofPushMatrix();
            ofTranslate(pos_K2_X,pos_K2_Y);
            ofScale(K2_scale);
             int m = contourFinder2.size();
             for(int i = 0; i < m; i++) {
             ofPolyline convexHull2 = toOf(contourFinder2.getFitQuad(i));
             ofNoFill();
             for (int i=0;i<int(convexHull2.size());i++) {
             ofDrawCircle(convexHull2.getVertices()[i].x,convexHull2.getVertices()[i].y,diametro_random);
                }
        }
        ofPopMatrix();
           
            
    }
    skip++;
    if (skip>=skip_frame) skip = 0;
  
    rip.end();
    rip.update();
    
    bounce << rip;
   
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    ofEnableArbTex();
    fbo.begin();;
    bounce.draw(0,0);
    fbo.end();
    ofDisableArbTex();
    fbo.getTexture().bind();
    shader.begin();
    shader.setUniform1f("center", center);
    shader.setUniform1f("gamma", gamma);
    shader.setUniform1f("fade", fade);
    shader.setUniform2f("resolution", 3360, 1200);
    fbo.draw(0,0,3840,1200);
    ofPushMatrix();
    ofTranslate(0,0);
    ofScale(1.);
    //grayImage.draw(0,0,320,240);
    //grayImage2.draw(3520,0,320,240);
    //grayDiff.draw(0,0,320,240);
    ofPopMatrix();
    shader.end();
    
    //gui.draw();
    // gui.setPosition(330,0);
    ofSetColor(255);
    int minutos = ofGetElapsedTimeMillis()/6000.; // x10
    //ofDrawBitmapString(ofToString(minutos),500,200);
    //ofDrawBitmapString(ofToString(mouseX),500,400);
    //ofDrawBitmapString(ofToString(mouseY),600,400);
    //Mirador.drawString("Cerca del 73% del cerebro de una persona adulta es agua", mouseX, mouseY);
    //ofDrawBitmapString(ofToString(texto),500,500);

    
    
    if ((minutos%4) == 1) {
        if (oneshot) {
            texto++;
            oneshot = false;
            tkg = ofGetElapsedTimeMillis();
        }
        if  (ofGetElapsedTimeMillis()-tkg < texto_fade) {
            //ofSetColor(255);
            //ofDrawBitmapString(ofToString(ofGetElapsedTimeMillis()-tkg),800,200);
            float tf = texto_fade/2.;
            float norma = (tf-(abs((ofGetElapsedTimeMillis()-tkg)-tf)))/tf;
            //ofDrawBitmapString(ofToString(norma),800,400);
            ofSetColor(255,norma*255);
            if ((texto%4) == 1) Mirador.drawString("Cerca del 73% del cerebro de una persona adulta es agua", 300, 600);
            if ((texto%4) == 2) Mirador.drawString("El cuerpo de los niños y bebés tiene más agua que el de una persona adulta", 2300, 600);
            if ((texto%4) == 3) Mirador.drawString("2/3 del agua de tu cuerpo se encuentra dentro de tus células", 300, 600);
            if ((texto%4) == 0) Mirador.drawString("Podríamos vivir un mes sin comida, pero no más de una semana sin agua", 2300, 600);
            ofSetColor(255);
        }
    }
    else oneshot = true;
    ofSetColor(255);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == OF_KEY_UP){
        rip.damping += 0.01;
    } else if ( key == OF_KEY_DOWN){
        rip.damping -= 0.01;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    //rip.damping = ofMap(y, 0, ofGetHeight(), 0.9, 1.0, true);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //gota = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    //gota = false;
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
    kinect.setCameraTiltAngle(0); // zero the tilt on exit
    kinect.close();
}
