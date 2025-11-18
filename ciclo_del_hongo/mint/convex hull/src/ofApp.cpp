#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
	//cam.setup(640, 480);
    
    kinect.setRegistration(true);
    kinect.init();
    //kinect.init(true); // shows infrared instead of RGB video image
    //kinect.init(false, false); // disable video image (faster fps)
    kinect.open();
    if (kinect.isConnected()) {
        ofLogNotice() << "kinect: " << kinect.getWidth() << "x" << kinect.getHeight();
    }
    kinect.setCameraTiltAngle(18); //25
    
    
    
	contourFinder.setMinAreaRadius(50);
	contourFinder.setMaxAreaRadius(150);
	//contourFinder.setInvert(true); // find black instead of white
    
    gui.setup();
    gui.add(threshold.set("Threshold", 128, 0, 255));
    gui.add(trackHs.set("Track Hue/Saturation", false));
    gui.add(holes.set("Holes", false));
}

void ofApp::update() {
	//cam.update();
    kinect.update();
    if(kinect.isFrameNew()) {
        mirror.setFromPixels(kinect.getDepthPixels());
        mirror.mirror(0,1);
        grayThreshNear = mirror;
        grayThreshFar = mirror;
        grayThreshNear.threshold(200, true);
        grayThreshFar.threshold(130);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), mirror.getCvImage(), NULL);
        
        
        
        
        contourFinder.setTargetColor(targetColor, trackHs ? TRACK_COLOR_HS : TRACK_COLOR_RGB);
		contourFinder.setThreshold(threshold);
        contourFinder.setFindHoles(holes);
		contourFinder.findContours(mirror);
	}
}

void ofApp::draw() {
    ofBackground(0);
	ofSetColor(255);
	//mirror.draw(0, 0, 1280, 960);
	
	ofSetLineWidth(2);
    ofPushMatrix();
    ofScale(2.);
	contourFinder.draw();
   // ofPopMatrix();
    
	ofNoFill();
	int n = contourFinder.size();
	for(int i = 0; i < n; i++) {
		// smallest rectangle that fits the contour
		//ofSetColor(cyanPrint);
		//ofPolyline minAreaRect = toOf(contourFinder.getMinAreaRect(i));
		//minAreaRect.draw();
		
		// ellipse that best fits the contour
		//ofSetColor(magentaPrint);
		//cv::RotatedRect ellipse = contourFinder.getFitEllipse(i);
		//ofPushMatrix();
		//ofVec2f ellipseCenter = toOf(ellipse.center);
		//ofVec2f ellipseSize = toOf(ellipse.size);
		//ofTranslate(ellipseCenter.x, ellipseCenter.y);
		//ofRotate(ellipse.angle);
		//ofDrawEllipse(0, 0, ellipseSize.x, ellipseSize.y);
		//ofPopMatrix();
		
		// minimum area circle that encloses the contour
		//ofSetColor(cyanPrint);
		//float circleRadius;
		//ofVec2f circleCenter = toOf(contourFinder.getMinEnclosingCircle(i, circleRadius));
		//ofDrawCircle(circleCenter, circleRadius);
		
		// convex hull of the contour
		
		ofPolyline convexHull = toOf(contourFinder.getConvexHull(i));
        convexHull.simplify(0.1);
        ofSetHexColor(0xFF00FF);
        ofFill();
        for (int i=0;i<int(convexHull.size());i++) {
            ofDrawCircle(convexHull.getVertices()[i].x,convexHull.getVertices()[i].y,10);
            }
        ofSetColor(yellowPrint);
		convexHull.draw();
		
		// defects of the convex hull
		vector<cv::Vec4i> defects = contourFinder.getConvexityDefects(i);
		for(int j = 0; j < defects.size(); j++) {
			ofDrawLine(defects[j][0], defects[j][1], defects[j][2], defects[j][3]);
		}
		
		// some different styles of contour centers
		ofVec2f centroid = toOf(contourFinder.getCentroid(i));
		ofVec2f average = toOf(contourFinder.getAverage(i));
		ofVec2f center = toOf(contourFinder.getCenter(i));
		ofSetColor(cyanPrint);
		ofDrawCircle(centroid, 8);
		ofSetColor(magentaPrint);
		ofDrawCircle(average, 8);
		ofSetColor(yellowPrint);
		ofDrawCircle(center, 8);
		
		// you can also get the area and perimeter using ofPolyline:
		// ofPolyline::getArea() and ofPolyline::getPerimeter()
		double area = contourFinder.getContourArea(i);
		double length = contourFinder.getArcLength(i);		
		
		// balance is useful for detecting when a shape has an "arm" sticking out
		// if balance.length() is small, the shape is more symmetric: like I, O, X...
		// if balance.length() is large, the shape is less symmetric: like L, P, F...
		ofVec2f balance = toOf(contourFinder.getBalance(i));
		ofPushMatrix();
		ofTranslate(centroid.x, centroid.y);
		ofScale(5, 5);
        ofSetHexColor(0xFF0000);
		ofDrawLine(0, 0, balance.x, balance.y);
		ofPopMatrix();
        
        if(contourFinder.getHole(i)) {
            ofDrawBitmapStringHighlight("hole", center.x, center.y);
        }
	}

    ofPopMatrix();
    gui.draw();
    
	ofTranslate(8, 90);
	ofFill();
	ofSetColor(0);
	ofDrawRectangle(-3, -3, 64+6, 64+6);
	ofSetColor(targetColor);
	ofDrawRectangle(0, 0, 64, 64);
}

void ofApp::mousePressed(int x, int y, int button) {
	targetColor = mirror.getPixels().getColor(x, y);
}
