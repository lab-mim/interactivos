#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //ofSetFrameRate(18);
    n_banda = 8;
    modo = 2;
    blanco = 0;
    bn = 0;
    show_gui = 1;
    show_cam = 1;
    figura = 1;
    mapa.load("banda_8.png");
    //mapa.setAnchorPoint(0.5,0.5);
    ofBackground(0,0,0);
    camWidth = 1920;
    camHeight = 1080;
    //vidGrabber.setDeviceID(0);
    vidGrabber.setVerbose(true);
    vidGrabber.setup(camWidth,camHeight);
    ofTrueTypeFont::setGlobalDpi(72);
    font.load("MiradorVF.ttf", 20,true,true);
    
    set_1 =  string(" 10");
    set_2 =  string("  ..,,,'''``--_:;^^**""=+<>iv%&xclrs)/){}I?!][1taeo7zjLunT#@JCwfy325Fp6mqSghVd4EgXPGZbYkOA8U$KHDBWNMR0Q");
    set_3 =  string("01 ");
    set_4 =  string(" x.");
    set_5 =  string(" :)-P(B");
    set_6 =  string(" .xX");
    set_7 =  string(" .,:;/|");
    
     
    asciiCharacters = set_1;
    
    ofEnableAlphaBlending();
    ofHideCursor();
    
    
    banda_ancho = mapa.getWidth();
    banda_alto = mapa.getHeight();
    
    gui.setup();
    gui.add(zoom.set("zoom", 1.21, 0., 2.));
    gui.add(ancho_.set("pos X",183, -1080, 1080));
    gui.add(alto_.set("pos Y", 38, -1920, 1920));
    gui.add(paso_x.set("sep X", 23, 10, 300));
    gui.add(paso_y.set("sep Y", 23, 10, 300));
    
    gui.add(gap.set("H ", 22, 0, 500));
    gui.add(gapp.set("V ",22, 0, 500));
    gui.add(linea.set("linea", 1, 0, 50));
    gui.add(circulo.set("circulo", 25, 1, 50));
    gui.add(sep_banda_x.set("sep banda X", 0, 0, 500));
    gui.add(sep_banda_y.set("sep banda U", 0, 0, 500));
    gui.add(frame_ancho.set("tam frame H", 40, 1,  100));
    gui.add(frame_alto.set("tam frame V", 40, 1,  100));
    gui.add(curva.set("curva ascii", 2.2, 0., 20.));
    gui.add(curva2.set("curva banda", 2.5, 0., 20.));
    gui.add(size.set("font size", 20, 5, 40));
    
    
    frames = banda_ancho/frame_ancho;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    frames = banda_ancho/frame_ancho;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
 
    ofPushMatrix();
    ofPixelsRef pixelsRef = vidGrabber.getPixels();
    ofSetHexColor(0xffffff);
    ofNoFill();
    ofSetLineWidth(linea);
    ofSetCircleResolution(circulo);

    /*
     /// \param x X position to draw cropped image at.
     /// \param y Y position to draw cropped image at.
     /// \param w Width of subsection to draw.
     /// \param h Height of subsection to draw.
     /// \param sx X position in image to begin cropping from.
     /// \param sy Y position in image to begin cropping from.
     /// \param sw Source width of cropped area.
     /// \param sh Source height of cropped area.
     
     */
    
    if (modo==0) {
        
        for (int i = 0; i < 1920; i+= paso_y){
            for (int j = 0; j <1080; j+= paso_x){
                
                int pos_x = (1080-(j*zoom))+ancho_;
                int pos_y = (1920-(i*zoom))+alto_;
                
                float lightness = pixelsRef.getColor(i,j).getLightness();
                color=(pixelsRef.getColor(i,j));
                if (bn) {
                    if (blanco) ofSetColor(255);
                    else ofSetColor(lightness);
                }
                else ofSetColor(color);
                int character = powf( ofMap(lightness, 0, 255, 0, 1), curva) * asciiCharacters.size();
                font.drawString(ofToString(asciiCharacters[character]),pos_x,pos_y);
            }
        }
    }
    
 else   if (modo==1) {
    for (int i = 0; i < 1920; i+= frame_alto+sep_banda_y){
        for (int j = 0; j <1080; j+= frame_ancho+sep_banda_x){
            int pos_x = (1080-(j*zoom))+ancho_;
            int pos_y = (1920-(i*zoom))+alto_;
            float lightness = pixelsRef.getColor(i,j).getLightness();
            color=(pixelsRef.getColor(i,j));
            if (bn) {
                if (blanco) ofSetColor(255);
                else ofSetColor(lightness);
                }
            else ofSetColor(color);
            int frame_banda = powf( ofMap(lightness, 0, 255, 0, 1), curva2) * frames;
            mapa.drawSubsection(pos_x,pos_y,frame_ancho*zoom,frame_alto*zoom,frame_banda*frame_ancho,0,frame_ancho,frame_alto);
            }
        }
    }
    
 else   if (modo==2) {
    for (int i = 0; i < 1920; i+= paso_y){
        for (int j = 0; j <1080; j+= paso_x){
            int pos_x = (1080-(j*zoom))+ancho_;
            int pos_y = (1920-(i*zoom))+alto_;
            float lightness = pixelsRef.getColor(i,j).getLightness();
            color=(pixelsRef.getColor(i,j));
            if (bn) {
                if (blanco) ofSetColor(255);
                else ofSetColor(lightness);
                }
            else ofSetColor(color);
            
            
            if (figura == 0) {
                ofFill();
                ofDrawRectangle(pos_x,pos_y, gapp, gap);
            }
            else if (figura == 1) {
                ofFill();
                ofDrawEllipse(pos_x,pos_y, gapp, gap);
            }
            else if (figura == 2) {
                ofNoFill();
                ofDrawRectangle(pos_x,pos_y, gapp, gap);
            }
            
            else if (figura == 3) {
                ofNoFill();
                
                ofDrawEllipse(pos_x,pos_y, gapp, gap);
            }
            
            }
        }
    }
    

     
    //
     
 
    
  
    
    
    
    ofPopMatrix();
    ofSetColor(255);
    
    
    //mapa.drawSubsection(ss1,ss2,ss3,ss4,ss5,ss6,ss7,ss8);
    
    if (!show_gui)  {
        gui.draw();
        ofFill();
        ofSetColor(0,0,0,150);
        ofDrawRectangle(0, 1800, 1080, 120);
        ofSetColor(255);
        if (modo==1) {
            ofDrawBitmapString(" banda "+ ofToString(n_banda) + " : " + ofToString(banda_ancho)+ "x" + ofToString(banda_alto) ,0,1810);
            ofDrawBitmapString(" frames  : " + ofToString(frames) + " ("+ ofToString(frame_ancho)+"x"+ofToString(frame_alto)+")",0, 1822);
            mapa.draw(0,1830);
        }
    }
    
    
    if (!show_cam) {
        vidGrabber.draw(384,0,384,216);
    }
    // gui.setPosition(330,0);

    
}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    
    
    if (key == ' '){
        modo++;
        if (modo>2) modo = 0;
    }
    
    if (key == 'b') {
        n_banda++;
        if (mapa.load("banda_"+ofToString(n_banda)+".png")) {
            
        }
        else {
            n_banda = 0;
            mapa.load("banda_"+ofToString(n_banda)+".png");
        }
        
        banda_ancho = mapa.getWidth();
        banda_alto = mapa.getHeight();
       
        frame_ancho = banda_alto;
        frame_alto = banda_alto;
        
    }
    
    if (key == 'c'){
        figura++;
        if (figura>3) figura = 0;
    }
    
    if (key == 'm'){
        mapa.mirror(false,true);
    }
    
    
    if (key == 'l'){
        bn=!bn;
    }
    
    if (key == 'k'){
        blanco=!blanco;
    }
    
    if (key == 'a'){
        acolor = 0;
    }
    
    if (key == 's'){
        acolor = 1;
    }
    
    if (key == 'd'){
        acolor = 2;
    }
    
    if (key == '1') {
        asciiCharacters = set_1;
    }
    
    if (key == '2'){
        asciiCharacters = set_2;
    }
    
    if (key == '3'){
        asciiCharacters = set_3;
    }
    
    if (key == '4'){
        asciiCharacters = set_4;
    }
    
    if (key == '5'){
        asciiCharacters = set_5;
    }
    
    if (key == '6'){
        asciiCharacters = set_6;
    }
    
    if (key == '7'){
        asciiCharacters = set_7;
    }
    
    if (key == 'q'){
        font.load("verdana.ttf", size,true,true);
    }
    
    if (key == 'w'){
        font.load("MiradorVF.ttf", size,true,true);
    }
    
    if (key == 'e'){
       
        font.load("Courier New Bold.ttf", size,true,true);
        
    }
    
    if (key == 'r'){
        font.load("frabk.ttf", size,true,true);
    }
    
    if (key == 'g'){
        show_gui=!show_gui;
    }
    
    if (key == 'h'){
        show_cam=!show_cam;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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


