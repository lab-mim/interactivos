#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"
#include "ofxSvg.h"
#include "ofxImageSequence.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

#define KINECT



// ------------------------------------------------- a simple extended box2d circle
class CustomParticle : public ofxBox2dCircle {
public:
    ofColor color;
    int alpha;
    
    CustomParticle(b2World * world, float x, float y) {
        setPhysics(1, 40, 10);
        setup(world, x, y, 1);
    }
        
    
    void draw() {
        float radius = getRadius();
        
        ofPushMatrix();
        ofTranslate(getPosition());
        ofSetColor(color);
        ofNoFill();
        ofDrawCircle(0, 0, radius);
        ofPopMatrix();
    }
    
    static bool shouldRemoveEsporas(shared_ptr<ofxBox2dBaseShape> shape) {
        return !ofRectangle(0, 0, ofGetWidth(), 600).inside(shape.get()->getPosition());
    }
    
    
};

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		
    
   
    void gaussian_blur();
    void allocate_fb();
    int morphogenesis(vector <shared_ptr<CustomParticle>> &micelio_player, int lifetime) ;
    int esporulacion(vector <shared_ptr<CustomParticle>> &esporas, int lifetime) ;
    void draw_fb_player(vector <shared_ptr<CustomParticle>> &micelio_player) ;
    void carga_lineas();
    int smooth(int valor);
    
    void callampas_1(int seta, ofVec2f pos);
    void callampas_2(int seta, ofVec2f pos);
    void callampas_3(int seta, ofVec2f pos);
    void new_layer();
    
    void esporula(ofVec2f punto, int espora);
    void esporula_continuo(ofVec2f punto, int espora);
    void reporte();
    void gui_settings();
    void picture_in_picture();
    
    void start_micelio_1();
    void start_micelio_2();
    void start_micelio_3();
    
    static bool sort_x(glm::vec2 &a, glm::vec2 &b);
    static bool sort_y(glm::vec2 &a, glm::vec2 &b);
   
   
    ofShader shaderX, shaderY;
    
    ofImage fondo_1,fondo_2,fondo_3,fondo_4;
    
    ofxBox2d box2d;
    ofxBox2d box2d_esporas;
    
    vector    <shared_ptr<CustomParticle>> micelio_player_1;
    vector    <shared_ptr<CustomParticle>> micelio_player_2;
    vector    <shared_ptr<CustomParticle>> micelio_player_3;
    vector    <shared_ptr<CustomParticle>> esporas;
    vector    <shared_ptr<ofxBox2dEdge>>    edges;
    
    vector    <ofPolyline>                  lines;
    
    
    ofFbo fb_player_1, fb_player_2, fb_player_3, fb_blur_X1, fb_blur_Y1, fb_blur_X2, fb_blur_Y2, fb_blur_X3, fb_blur_Y3, fb_esporas, fb_esporomas_1, fb_esporomas_2, fb_esporomas_3;
    
    ofxPanel gui1, gui2, gui3, gui4, gui5;
    

    ofParameter<float> random, blur, gravedadX, gravedadY;
    ofParameter<int> fade1,fade2,fade3,fade_esporomas_1,fade_esporomas_2,fade_esporomas_3;
    ofParameter<float> tamano1,tamano2,tamano3;
    ofParameter<int> minimo,maximo,altura_micelio;
    ofParameter<int> cerca,lejos;
    
    int altura;
    int modo;
    int pip; //vis Kinect
    int fb_x,fb_y,offset_fb_y;
    int contador_1, contador_2, contador_3;
    
    int f_shroom_1, shroom_1;
    int f_shroom_2, shroom_2;
    int f_shroom_3, shroom_3;
    
    float pos_esporoma_1,pos_esporoma_2,pos_esporoma_3;
    
    ofxImageSequence Amanita, Cortinarius, Cortinariusx3, Morchella, Leucocoprinus;
    
    float gY;
    
    float inicio;
   
    bool vsync,lineas,info,gui,kontorno,color_fondo,silueta,simpli,puf_1,puf_2,puf_3, nada, comienzo, stop_m1, stop_m2, stop_m3;
    
#ifdef KINECT
    ofxKinect kinect;
    ofxCvGrayscaleImage mirror;
    ofxCvGrayscaleImage grayImage;        // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear;   // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar;    // the far thresholded image

    ofxCv::ContourFinder contourFinder;
    ofVec2f centroid1,centroid2,centroid3;
    
    
#endif

    deque <glm::vec2> avg,avg2;
    glm::vec2 m1,m2;
    int mx,my;
    int mxx,myy;
    int tet, tet2, tet3;
    float origen_1, origen_2, origen_3;
    
    bool play_shroom_1,play_shroom_2,play_shroom_3;
    bool esporoma_status_1,esporoma_status_2,esporoma_status_3;
    
    int centroid_smooth;
    
    ofVec2f mano;
    
    ofVec2f punto_m1, punto_m2, punto_m3;
    
    vector<glm::vec2> ord;
    
    int players, antiguos, nuevos, layer_actual;
  
    bool primer_puf_1, primer_puf_2, primer_puf_3;
    
    float inicio_puf_1, ahora_puf_1;
    float inicio_puf_2, ahora_puf_2;
    float inicio_puf_3, ahora_puf_3;
    
    int num_esp_1, num_esp_2, num_esp_3;
    
    bool kill_e1, tiempo_kill_e1;
    bool kill_m1, tiempo_kill_m1;
    
    bool kill_e2, tiempo_kill_e2;
    bool kill_m2, tiempo_kill_m2;
    
    bool kill_e3, tiempo_kill_e3;
    bool kill_m3, tiempo_kill_m3;
    
    
    float inicio_kill_e1, ahora_kill_e1;
    float inicio_kill_m1, ahora_kill_m1;
    
    float inicio_kill_e2, ahora_kill_e2;
    float inicio_kill_m2, ahora_kill_m2;
    
    float inicio_kill_e3, ahora_kill_e3;
    float inicio_kill_m3, ahora_kill_m3;
    
    bool wait_e1, tiempo_wait_e1;
    bool wait_m1, tiempo_wait_m1;
    
    bool wait_e2, tiempo_wait_e2;
    bool wait_m2, tiempo_wait_m2;
    
    bool wait_e3, tiempo_wait_e3;
    bool wait_m3, tiempo_wait_m3;
    
    float wait_kill_e1, ahora_wait_e1;
    float wait_kill_m1, ahora_wait_m1;
    
    float wait_kill_e2, ahora_wait_e2;
    float wait_kill_m2, ahora_wait_m2;
    
    float wait_kill_e3, ahora_wait_e3;
    float wait_kill_m3, ahora_wait_m3;
    
    bool layer_1_free, layer_2_free, layer_3_free;
    
};
