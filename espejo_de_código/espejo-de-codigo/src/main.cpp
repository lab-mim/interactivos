#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

    //Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
    ofGLFWWindowSettings settings;
    settings.setSize(1080, 1920);
    //settings.setPosition(glm::vec2(3840,0));
    settings.windowMode = OF_FULLSCREEN; //can also be OF_FULLSCREEN
    //settings.multiMonitorFullScreen = true;
    //settings.decorated = false;
    auto window = ofCreateWindow(settings);

    ofRunApp(window, make_shared<ofApp>());
    ofRunMainLoop();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

}

