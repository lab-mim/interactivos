#include "ofApp.h"

int main() {

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLFWWindowSettings settings;
	settings.setSize(3840,1200);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();
	
}
