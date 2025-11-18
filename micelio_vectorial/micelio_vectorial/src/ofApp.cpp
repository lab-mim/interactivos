#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    gui.setup();
    gui.add(prob.set("probabilidad",0.001, 0, 0.05));
    gui.add(bump.set("bump",0.2,0, 1.));
    gui.add(tam.set("tamaño",1,0, 10));
    
    
    
    
    
	capture = false;
    hifa temporal;
    temporal.setup();
    micelio.push_back(temporal);
    micelio.push_back(temporal);
    micelio.push_back(temporal);
    micelio.push_back(temporal);
}

//--------------------------------------------------------------
void ofApp::update(){
    
         
       
	
  
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
	if(capture){
		output.beginEPS("test.ps");
	}
    
   
    for (int i=0;i<micelio.size();i++) {                    // loop por todas las hifas    micelio[0]
        micelio[i].bum = bump;
        //micelio[i].x1 = mouseX/1920.-0.5;
      //  micelio[i].y1 = mouseY/640.-0.5;
        micelio[i].puntos.push_back(glm::vec3());           //agregamos un punto a la hifa micelio[0].puntos[0]
        int last = micelio[i].puntos.size()-1;              //last = último punto
        micelio[i].puntos[last].x=micelio[i].posicion.x;    //asigna cabeza de micelio[0] último punto x
        micelio[i].puntos[last].y=micelio[i].posicion.y;    //               ''                        y
        int numPts = micelio[i].puntos.size();              //numPts = cantidad de puntos micelio[0]

        output.setColor(0xFFFFFF);
        output.noFill();
        output.setLineWidth(tam);
        output.beginShape();
        
        int rescaleRes = 6;
        for(int j = 0; j < numPts; j++){
       
            if(j == 0 || j == numPts -1){
                output.curveVertex(micelio[i].puntos[j].x,micelio[i].puntos[j].y);
            }
            if(j % rescaleRes == 0) output.curveVertex(micelio[i].puntos[j].x, micelio[i].puntos[j].y);
        }
        
        output.endShape();
        
        if (ofRandom(0,1)<prob) {
            micelio.push_back(micelio[i]);
        }
        
        micelio[i].update();
    }
    
    


   
   //  micelio.push_back(micelio[0]);
    
 

    

	if(capture){
		output.endEPS();
		capture =false;
	}
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    int total= micelio.size();
        for (int i=0;i<total;i++) {
            micelio.push_back(micelio[i]);
        }
    
	if(key == ' '){
		capture = true;
	}
    
    if(key == 'c') {
           micelio.clear();
           hifa temporal2;
           temporal2.setup();
           temporal2.posicion.x=mouseX;
           temporal2.posicion.y=mouseY;
           
             micelio.push_back(temporal2);
    }
    
    if(key == '1') {
        micelio.clear();
        hifa temporal2;
           temporal2.setup();
           temporal2.posicion.x=mouseX;
           temporal2.posicion.y=mouseY;
           
             micelio.push_back(temporal2);
    }
    
    if(key == '4') {
        micelio.clear();
        hifa temporal2;
           temporal2.setup();
           temporal2.posicion.x=mouseX;
           temporal2.posicion.y=mouseY;
           
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        
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

   
   
    
    
    //we add a new point to our line
    
    
  
 //   micelio.push_back(micelio[0]);
  //  pts.push_back(glm::vec3());
   // int last = pts.size()-1;

    //pts[last].x = ofRandom(640);
    //pts[last].y = ofRandom(480);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
        hifa temporal2;
           temporal2.setup();
           temporal2.posicion.x=mouseX;
           temporal2.posicion.y=mouseY;
           
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        micelio.push_back(temporal2);
        
    }
    
    // micelio.clear();
    
 
  /*  int total= micelio.size();
     for (int i=0;i<total;i++) {
         micelio.push_back(micelio[i]);
     } */
    
   
       
    

    //lets store the first point of the line
    //pts.push_back(glm::vec3());
    //pts[0].x = x;
    //pts[0].y = y;




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
