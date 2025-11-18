#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofGLFWWindowSettings settings;
    settings.setGLVersion(3,2);
    settings.setSize(3840,1200);
    settings.setPosition(glm::vec2(0,0));
    settings.decorated = false;
    settings.windowMode = OF_FULLSCREEN;
    settings.multiMonitorFullScreen = true;
    auto window = ofCreateWindow(settings);
	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

}
