#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);
	
	ofVideoGrabber cam;	
    ofxKinect kinect;
    ofxCvGrayscaleImage mirror;
    ofxCvGrayscaleImage grayThreshNear;   // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar;    // the far thresholded image
	ofxCv::ContourFinder contourFinder;
	ofColor targetColor;
    
    ofxPanel gui;
    ofParameter<float> threshold;
    ofParameter<bool> trackHs;
    ofParameter<bool> holes;
};
