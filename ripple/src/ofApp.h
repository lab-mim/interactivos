#pragma once

#include "ofMain.h"
#include "ofxRipples.h"
#include "ofxBounce.h"
#include "ofxGui.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"


class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxKinect kinect, kinect2;
    
    ofxCvColorImage colorImg;
    
    ofxCvGrayscaleImage grayImage; // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
  
    ofxCvGrayscaleImage grayImage2; // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear2; // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar2; // the far thresholded image
    
    ofxCv::ContourFinder contourFinder;
    ofxCv::ContourFinder contourFinder2;
    
    ofxRipples  rip;
    ofxBounce bounce;
    
    ofShader shader;
    ofFbo fbo;
    
    ofxPanel gui;
    ofParameter<float> center,gamma,fade,damping;
    ofParameter<float> minArea, maxArea, threshold, simplifica;
    ofParameter<bool> holes,filo;
    ofParameter<int> near, far, near2, far2, tamano, randiam, skip_frame, texto;
    ofParameter<float> rot,grun,blau,tropfen;
    ofParameter<int> pos_K1_X,pos_K1_Y,pos_K2_X,pos_K2_Y;
    ofParameter<float> K1_scale, K2_scale;
    
    ofImage imagen;
   
    
    ofTexture textura;
    
   int skip;
    
    ofTrueTypeFont    Mirador;
    
    //VIDEO
    

 ofVideoPlayer         vidPlayer;


  ofxCvColorImage            colorImgV;

  ofxCvGrayscaleImage     grayImageV;
  ofxCvGrayscaleImage     grayBg;
  ofxCvGrayscaleImage     grayDiff;

  

  int                 thresholdV;
  bool                bLearnBakground;
    
    bool oneshot;
    unsigned long  tkg;
    int texto_fade;
    
};
