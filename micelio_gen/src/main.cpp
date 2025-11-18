#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofGLFWWindowSettings settings;
	settings.setSize(1920, 1080);
    //settings.setPosition(glm::vec2(400,400));
    settings.setGLVersion(3,2);
    settings.windowMode = OF_FULLSCREEN;

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

}
