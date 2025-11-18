#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofGLFWWindowSettings settings;
	settings.setSize(1920, 1200);
    settings.setGLVersion(3,2);
    settings.windowMode = OF_WINDOW;

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

}
