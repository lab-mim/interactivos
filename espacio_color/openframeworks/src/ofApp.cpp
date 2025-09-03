#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

const int width = 1920;
const int height = 1080;

//--------------------------------------------------------------
void ofApp::setup(){
    
    sender.setup(HOST, PORT);
    tam_matrix = 560;     // 56(7x8) leds de ancho de 10px
    step = tam_matrix/56; // 10 px
    radio = tam_matrix/2; // 280
    
#ifdef KINECT
    {
        kinect.setRegistration(true);
        kinect.init(false,false,true);
        kinect.open();
        if (kinect.isConnected()) {
            ofLogNotice() << "kinect: " << kinect.getWidth() << "x" << kinect.getHeight();
        }
        kinect.setCameraTiltAngle(0);
    }
#endif
    
#ifdef SYPHON
    
    fb_syphon.allocate(1920,1080,GL_RGB);
    fb_syphon.begin();
    ofClear(0,0,0,0);
    fb_syphon.end();
    colorImg.allocate(1920,1080);
    mClient.setup();
    mClient.set("jit syphon","");
    
#endif
    
    
    
    avg.setup(10);
    avg2.setup(50);
    
    
    gui1.setup();
    gui1.add(minimo.set("min",45, 0, 255));
    gui1.add(maximo.set("max",180, 0, 255));
    gui1.add(thr.set("thr",0, 0, 255));
    gui1.add(cerca.set("umbral cerca",240, 50, 255)); //UMBRAL SALA
    gui1.add(lejos.set("umbral lejos",120, 0, 255));   //UMBRAL SALA
    gui1.add(mapx.set("paramX",0,0,55));
    gui1.add(mapy.set("paramY",0,0,55));
    gui1.add(saturation.set("saturation",1,0,2));
    gui1.add(value.set("value",1,0,2));
    gui1.add(grad.set("grad",1,0,1));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetHexColor(0xFFFFFF);
    fb_syphon.begin();
    mClient.draw(0,0,1920,1080);
    fb_syphon.end();
    
    ofTexture& textura = fb_syphon.getTexture();
    textura.readToPixels(pixeles);
    colorImg.setFromPixels(pixeles);
    grayImage = colorImg;
    contourFinder.setMinAreaRadius(minimo);
    contourFinder.setMaxAreaRadius(maximo);
    contourFinder.setThreshold(thr);
    contourFinder.findContours(grayImage);
    
    
    
    c_avg = avg.calcula(medio);
    c_avg2 = avg2.calcula(medio);
    
    
    
    ofxOscMessage m;
    m.setAddress("/kinect/rgb");
    m.addIntArg(col.x);
    m.addIntArg(col.y);
    m.addIntArg(col.z);
    sender.sendMessage(m, false);
    
#ifdef KINECT
    {
        kinect.update();
        if (kinect.isFrameNew()) {
            grayImage.setFromPixels(kinect.getDepthPixels());
            grayImage.mirror(0,1);
            grayThreshNear = grayImage;
            grayThreshFar = grayImage;
            grayThreshNear.threshold(cerca, true);
            grayThreshFar.threshold(lejos);
            cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
            grayImage.dilate();
            grayImage.dilate();
            grayImage.dilate();
            contourFinder.setMinAreaRadius(minimo);
            contourFinder.setMaxAreaRadius(maximo);
            contourFinder.setThreshold(0);
            contourFinder.findContours(grayImage);
            contourFinder.setFindHoles(false);
            contourFinder.setSimplify(false);
        }
    }
#endif
}

//--------------------------------------------------------------
void ofApp::draw(){
    
#ifdef KINECT
    {
        int n = contourFinder.size();
        
        if (n) {
            centroid1 = toOf(contourFinder.getCentroid(0));
        }
        ofPushMatrix();
        ofTranslate(20, 20);
        grayImage.draw(0,0,640,480);
        ofSetColor(255,0,255);
        contourFinder.draw();
        ofSetColor(0,255,255);
        ofDrawCircle(centroid1,10);
        ofPopMatrix();
    }
#endif
    
    ofSetHexColor(0xFFFFFF);
    ofPushMatrix();
    ofScale(0.5,0.5);
    ofPushMatrix();
    ofTranslate(440,25);
    grayImage.draw(0,0);
    contourFinder.draw();
    
    
    int size = contourFinder.size();
    
    if (size) {
        ofFill();
        ofSetHexColor(0xFF00FF);
        for (int i=0;i<size;i++) {
            ofVec2f centroid = toOf(contourFinder.getCentroid(i));
            ofDrawCircle(centroid.x, centroid.y, 40);
            ofDrawBitmapString(ofToString(i),centroid.x,centroid.y);
        }
    }
    
    if (size==2) {
        
        ofVec2f centroid1 = toOf(contourFinder.getCentroid(0));
        ofVec2f centroid2 = toOf(contourFinder.getCentroid(1));
        
        
       /* if (centroid1.x<=centroid2.x) medio.x = centroid1.x+(centroid2.x-centroid1.x)/2.;
        else medio.x = centroid2.x+(centroid1.x-centroid2.x)/2.;
        
        
        if (centroid1.y<=centroid2.y) medio.y = centroid1.y+(centroid2.y-centroid1.y)/2.;
        else medio.y = centroid2.y+(centroid1.y-centroid2.y)/2.;*/
        medio.x = (centroid1.x+centroid2.x)/2.;
        medio.y = (centroid1.y+centroid2.y)/2.;
        ofSetHexColor(0xFFFF00);
        ofFill();
        ofDrawCircle(medio.x,medio.y, 10);
        ofDrawLine(centroid1,centroid2);
    
    }
    
    if (size==3) {
        
        ofVec2f c1 = toOf(contourFinder.getCentroid(0));
        ofVec2f c2 = toOf(contourFinder.getCentroid(1));
        ofVec2f c3 = toOf(contourFinder.getCentroid(2));
        medio.x = (c1.x+c2.x+c3.x)/3.;
        medio.y = (c1.y+c2.y+c3.y)/3.;
        
        ofSetHexColor(0x00FFFF);
        ofFill();
        ofDrawBitmapString(ofToString(medio.x)+","+ofToString(medio.y),medio.x,medio.y);
        ofDrawCircle(medio.x,medio.y, 10);
        ofDrawLine(c1,c2);
        ofDrawLine(c2,c3);
        ofDrawLine(c3,c1);
    }
    
    if (size==4) {
        
        ofVec2f c1 = toOf(contourFinder.getCentroid(0));
        ofVec2f c2 = toOf(contourFinder.getCentroid(1));
        ofVec2f c3 = toOf(contourFinder.getCentroid(2));
        ofVec2f c4 = toOf(contourFinder.getCentroid(3));
        medio.x = (c1.x+c2.x+c3.x+c4.x)/4.;
        medio.y = (c1.y+c2.y+c3.y+c4.y)/4.;
        
        
    }
    
    
    ofSetHexColor(0xFF0000);
    ofFill();
    ofDrawBitmapString(ofToString(medio.x)+"."+ofToString(medio.y),medio.x,medio.y);
    ofDrawCircle(medio.x,medio.y, 10);
    ofSetHexColor(0x00FF00);
    ofDrawRectangle(c_avg.x, c_avg.y, 14, 14);
    ofSetHexColor(0xFFFFFF);
    ofDrawRectangle(c_avg2.x, c_avg2.y, 40, 40);

    ofPopMatrix();
    ofPopMatrix();
    
   
    
   ofDrawBitmapString(ofToString(medio.x)+","+ofToString(medio.y),0, 1000);
  
    ofDrawBitmapString(ofToString(c_avg.x)+","+ofToString(c_avg.y),0, 1010);
    ofDrawBitmapString(ofToString(c_avg2.x)+","+ofToString(c_avg2.y),0, 1020);
    
    gui1.draw();

    
    // ------dibuja matrix----------
    
        ofPushMatrix();
        ofTranslate(1200,0);
        rosa();
        ofNoFill();
        ofDrawRectangle(mapx*10, mapy*10, 10, 10);
        ofPopMatrix();
    
    // -----------------------------
    ofSetColor(255);
    gui1.draw();
    
#ifdef KINECT
    {
        ofDrawRectangle( floor((centroid1.x/640)*56)*10,floor((centroid1.y/480)*56)*10,10,10 );
        //ofDrawRectangle((centroid1.x/640)*10,(centroid1.y/480)*10,9,9);
        ofPopMatrix();
        ofDrawRectangle( centroid1,10,10 );
    }
#endif
    
    col= rgb(mapx,mapy);
    reporte();
    ofFill();
    ofSetColor(col.x,col.y,col.z);
    ofDrawRectangle(1200, 600, 500, 300);
}

void ofApp::rosa(){
    for ( int i=0; i<tam_matrix; i+=step )
    {
        for ( int j=0; j<tam_matrix; j+=step )
        {
            float p = i-radio;
            int q = j-radio;
            float r = sqrt(p*p+q*q);
            float rad = atan2(q,p);
            hue = ((rad + PI)/(1*PI))*180;
            float chroma = value*saturation*(r/radio*0.707);
            float hue1 = hue/60;
            float x = chroma*(1-abs(fmod(hue1,2)-1));
            float m =  value-chroma;
            if (hue1>0 && hue1    <=1) ofSetColor((chroma+m)*255,(x+m)*255,m*255);
            else
                if (hue1>1 && hue1  <=2) ofSetColor((x+m)*255,(chroma+m)*255,m*255);
                else
                    if (hue1>2 && hue1  <=3) ofSetColor(m*255,(chroma+m)*255,(x+m)*255);
                    else
                        if (hue1>3 && hue1  <=4) ofSetColor(m*255,(x+m)*255,(chroma+m)*255);
                        else
                            if (hue1>4 && hue1  <=5) ofSetColor((x+m)*255,m*255,(chroma+m)*255);
                            else
                                if (hue1>5 && hue1  <=6) ofSetColor((chroma+m)*255,m*255,(x+m)*255);
            
            
            
            
            
            else ofSetColor(0,0,0);
            
            ofDrawRectangle( i, j, step-1, step-1 );
            ofSetColor(255);
          
         
            //ofDrawBitmapString(ofToString(x*255),i,j);
                               

        }
    }
}

glm::vec3 ofApp::rgb(int i, int j) {
    
    float p = i*10-radio;
    int q = j*10-radio;
    float r = sqrt(p*p+q*q);
    float rad = atan2(q,p);
    hue_grilla = ((rad + PI)/(1*PI))*180;
    chroma_g = value*saturation*(r/radio*0.707);
    float hue1 = hue_grilla/60;
    float x = chroma_g*(1-abs(fmod(hue1,2)-1));
    float m =  value-chroma_g;
    if (hue1>0 && hue1    <=1) return glm::vec3((chroma_g+m)*255,(x+m)*255,m*255);
    else
        if (hue1>1 && hue1  <=2) return glm::vec3((x+m)*255,(chroma_g+m)*255,m*255);
        else
            if (hue1>2 && hue1  <=3) return glm::vec3(m*255,(chroma_g+m)*255,(x+m)*255);
            else
                if (hue1>3 && hue1  <=4) return glm::vec3(m*255,(x+m)*255,(chroma_g+m)*255);
                else
                    if (hue1>4 && hue1  <=5) return glm::vec3((x+m)*255,m*255,(chroma_g+m)*255);
                    else
                        if (hue1>5 && hue1  <=6) return glm::vec3((chroma_g+m)*255,m*255,(x+m)*255);
                        else return(glm::vec3(255,255,255));
    

    
    
}

void ofApp::reporte () {
    ofSetHexColor(0xFFFFFF);
    ofDrawBitmapString("mouse: " + ofToString(int(mouseX))+ " "+ofToString(int(mouseY)),50,950);
    ofDrawBitmapString("RGB: " + ofToString(int(col.x))+   " "+ofToString(int(col.y))+ " " + ofToString(int(col.z)),50,650);
    ofDrawBitmapString("radio: " + ofToString(radio),50,700);
    ofDrawBitmapString("grilla: " + ofToString((mapx*10)-radio)+" "+ofToString((mapy*10)-radio),50,750);
    ofDrawBitmapString("hue: " + ofToString(hue_grilla),50,800);
    ofDrawBitmapString("chroma: " + ofToString(chroma_g),50,850);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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


