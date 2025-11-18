#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    //ofSetupOpenGL(1024,768, OF_WINDOW);            // <-------- setup the GL context

    ofGLFWWindowSettings settings;
    //settings.setGLVersion(2,1);
    settings.setSize(3840, 1200);
    //settings.setSize(2560, 800);
    settings.windowMode = OF_FULLSCREEN; //can also be OF_FULLSCREEN
    settings.multiMonitorFullScreen = true;
    
    
    auto window = ofCreateWindow(settings);
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    
    //ofRunApp( new testApp());
    
    ofRunApp(window, make_shared<testApp>());
    ofRunMainLoop();

    
    
    

}

