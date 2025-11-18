#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    ofHideCursor();
    
    nada = true ;
    comienzo = false;
    
    modo = 0;
    antiguos = 0;
    nuevos = 0;
    
    
    layer_actual = -1;
    
    
    // IDENTIFICAR VARIABLES -------------------------
    puf_1 = false;          // flag indica que terminó la animación
    wait_e1 = false;
    kill_e1 = false;
    kill_m1 = false;
    wait_m1 = false;
    
    puf_2 = false;
    wait_e2 = false;
    kill_e2 = false;
    kill_m2 = false;
    wait_m2 = false;
    
    puf_3 = false;
    wait_e3 = false;
    kill_e3 = false;
    kill_m3 = false;
    wait_m3 = false;
    
    // -----------------------------------------------------
    
    layer_1_free = true;
    layer_2_free = true;
    layer_3_free = true;
    
    // llenamos el buffer de player_1
    for (int i=0; i<50; i++) avg.push_back(glm::vec2(0,0));
    for (int i=0; i<50; i++) avg2.push_back(glm::vec2(0,0));
    
  

#ifdef KINECT
    kinect.setRegistration(true);
    kinect.init(false,false,true);
    kinect.open();
    if (kinect.isConnected()) {
        ofLogNotice() << "kinect: " << kinect.getWidth() << "x" << kinect.getHeight();
    }
    kinect.setCameraTiltAngle(-10); //25
#endif
    
    ofSetBackgroundAuto(true);
    ofSetVerticalSync(true);
    ofDisableArbTex();
    shaderX.load("shaderBlurX");
    shaderY.load("shaderBlurY");
    fondo_1.load("fondo-1.jpg");
    fondo_2.load("fondo-2.jpg");
    fondo_3.load("fondo-3.png");
    fondo_4.load("fondo-4.png");

    
    // --------------  box2d settings  ----------------------
    gY = 0;
    box2d.init();
    box2d.setGravity(0.0,gY);
    box2d.registerGrabbing();
    box2d_esporas.init();
    box2d_esporas.setGravity(0.0,3);
    box2d_esporas.registerGrabbing();
  

    
    // ----------------------------------------------------------------
    fb_x = 1920;
    fb_y = 720;
    offset_fb_y = 1200-fb_y;
    allocate_fb(); // framebuffer settings
    
    //--------------------------------------------------
    Amanita.loadSequence("Amanita/Amanita-", "png", 1, 30, 2);
    Amanita.preloadAllFrames();
    Amanita.setFrameRate(1);
    
    Cortinarius.loadSequence("Cortinarius/Cortinarius-", "png", 1, 30, 2);
    Cortinarius.preloadAllFrames();
    Cortinarius.setFrameRate(1);
    
    Cortinariusx3.loadSequence("Cortinariusx3/3Cortinarius-", "png", 1, 30, 2);
    Cortinariusx3.preloadAllFrames();
    Cortinariusx3.setFrameRate(1);
    
    Leucocoprinus.loadSequence("Leucocoprinus/LeucocoprinusMice-", "png", 1, 33, 2);
    Leucocoprinus.preloadAllFrames();
    Leucocoprinus.setFrameRate(1);
    
    Morchella.loadSequence("Morchella/MorchellaMice-", "png", 1, 33, 2);
    Morchella.preloadAllFrames();
    Morchella.setFrameRate(1);
    
    //---------------------------------------------------
    carga_lineas(); // líneas horizonte guardadas en bin/data/lines.txt
    gui_settings();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (gravedadY!=gY) {
        box2d.setGravity(gravedadX,gravedadY);
        gY=gravedadY;
    }
    
    
    
    
    

    if ((f_shroom_1<58) && (play_shroom_1)){                  // chequea play y si no ha llegado al final
        f_shroom_1++;                                         // avanza cuadro
        if (!esporoma_status_1) esporoma_status_1 = true;     // activa status play
    }
    else {
        if (esporoma_status_1) {                              // si llega aquí con status play es que terminó
            puf_1 = true;                                     // esporula
            esporoma_status_1 = false; 
            primer_puf_1 = true;
            num_esp_1 = 0;
        }
    }
    
    

    if (puf_1) {
        if (primer_puf_1) inicio_puf_1 = ofGetElapsedTimeMillis();
        primer_puf_1 = false;
        ahora_puf_1 = ofGetElapsedTimeMillis();
        if ((ahora_puf_1-inicio_puf_1)>2000) {
            esporula(punto_m1,150);
            inicio_puf_1 = ofGetElapsedTimeMillis();
            ++num_esp_1;
            if (num_esp_1==3) {
                puf_1=false;
                wait_e1 = true;
                wait_m1 = true;
                tiempo_wait_e1 = true;
                tiempo_wait_m1 = true;
                
            }
        }
    }
    
    
    if (wait_e1) {
        if (tiempo_wait_e1) wait_kill_e1 = ofGetElapsedTimeMillis();
        tiempo_wait_e1 = false;
        ahora_wait_e1 = ofGetElapsedTimeMillis();
        if ((ahora_wait_e1-wait_kill_e1)>5000) {
           wait_e1 = false;
           kill_e1 = true;
            tiempo_kill_e1= true;

            }
        }
    
    if (wait_m1) {
        if (tiempo_wait_m1) wait_kill_m1 = ofGetElapsedTimeMillis();
        tiempo_wait_m1 = false;
        ahora_wait_m1 = ofGetElapsedTimeMillis();
        if ((ahora_wait_m1-wait_kill_m1)>20000) {
           wait_m1 = false;
           kill_m1 = true;
            tiempo_kill_m1 = true;

            }
        }
        
    
    if (kill_e1) {
            if (tiempo_kill_e1) inicio_kill_e1 = ofGetElapsedTimeMillis();
            tiempo_kill_e1 = false;
            ahora_kill_e1 = ofGetElapsedTimeMillis();
            if ((ahora_kill_e1-inicio_kill_e1)>10) {
                fade_esporomas_1--;
                inicio_kill_e1 = ofGetElapsedTimeMillis();
                if (fade_esporomas_1==0) {
                    kill_e1 = false;
                    play_shroom_1 = false;
                    f_shroom_1 = 0;
                    fb_esporomas_1.begin();
                    ofClear(0,0,0,0);
                    fb_esporomas_1.end();
                    fade_esporomas_1 = 255;
                }
            }
        }
    
    if (kill_m1) {
            if (tiempo_kill_m1) inicio_kill_m1 = ofGetElapsedTimeMillis();
            tiempo_kill_m1 = false;
            ahora_kill_m1 = ofGetElapsedTimeMillis();
            if ((ahora_kill_m1-inicio_kill_m1)>10) {
                fade1--;
                inicio_kill_m1 = ofGetElapsedTimeMillis();
                if (fade1==0) {
                    kill_m1 = false;
                    micelio_player_1.clear();
                    fb_player_1.begin();
                    ofClear(0,0,0,0);
                    fb_player_1.end();
                    fb_blur_X1.begin();
                    ofClear(0,0,0,0);
                    fb_blur_X1.end();
                    fb_blur_Y1.begin();
                    ofClear(0,0,0,0);
                    fb_blur_Y1.end();
                    fade1 = 255;
                    layer_1_free = true;
                    stop_m1 = false;
                    contador_1 = 0;
                }
            }
        }
    

    
    
    
    if ((f_shroom_2<58) && (play_shroom_2)){                  // chequea play y si no ha llegado al final
        f_shroom_2++;                                       // avanza cuadro
        if (!esporoma_status_2) esporoma_status_2 = true;     // activa status play
    }
    else {
        if (esporoma_status_2) {                            // si llega aquí con status play es que terminó
            puf_2 = true;                                     // esporula
            esporoma_status_2 = false;                      // status stop
            primer_puf_2 = true;
            num_esp_2 = 0;
        }
    }
    
    if (puf_2) {
        if (primer_puf_2) inicio_puf_2 = ofGetElapsedTimeMillis();
        primer_puf_2 = false;
        ahora_puf_2 = ofGetElapsedTimeMillis();
        if ((ahora_puf_2-inicio_puf_2)>2000) {
            esporula(punto_m2,150);
            inicio_puf_2 = ofGetElapsedTimeMillis();
            ++num_esp_2;
            if (num_esp_2==3) {
                puf_2=false;
                wait_e2 = true;
                wait_m2 = true;
                tiempo_wait_e2 = true;
                tiempo_wait_m2 = true;
            }
        }
    }
    
    
    if (wait_e2) {
        if (tiempo_wait_e2) wait_kill_e2 = ofGetElapsedTimeMillis();
        tiempo_wait_e2 = false;
        ahora_wait_e2 = ofGetElapsedTimeMillis();
        if ((ahora_wait_e2-wait_kill_e2)>5000) {
           wait_e2 = false;
           kill_e2 = true;
            tiempo_kill_e2= true;

            }
        }
    
    if (wait_m2) {
        if (tiempo_wait_m2) wait_kill_m2 = ofGetElapsedTimeMillis();
        tiempo_wait_m2 = false;
        ahora_wait_m2 = ofGetElapsedTimeMillis();
        if ((ahora_wait_m2-wait_kill_m2)>20000) {
           wait_m2 = false;
           kill_m2 = true;
            tiempo_kill_m2 = true;

            }
        }
        
    
    if (kill_e2) {
            if (tiempo_kill_e2) inicio_kill_e2 = ofGetElapsedTimeMillis();
            tiempo_kill_e2 = false;
            ahora_kill_e2 = ofGetElapsedTimeMillis();
            if ((ahora_kill_e2-inicio_kill_e2)>10) {
                fade_esporomas_2--;
                inicio_kill_e2 = ofGetElapsedTimeMillis();
                if (fade_esporomas_2==0) {
                    kill_e2 = false;
                    play_shroom_2 = false;
                    f_shroom_2 = 0;
                    fb_esporomas_2.begin();
                    ofClear(0,0,0,0);
                    fb_esporomas_2.end();
                    fade_esporomas_2 = 255;
                }
            }
        }
    
    if (kill_m2) {
            if (tiempo_kill_m2) inicio_kill_m2 = ofGetElapsedTimeMillis();
            tiempo_kill_m2 = false;
            ahora_kill_m2 = ofGetElapsedTimeMillis();
            if ((ahora_kill_m2-inicio_kill_m2)>10) {
                fade2--;
                inicio_kill_m2 = ofGetElapsedTimeMillis();
                if (fade2==0) {
                    kill_m2 = false;
                    micelio_player_2.clear();
                    fb_player_2.begin();
                    ofClear(0,0,0,0);
                    fb_player_2.end();
                    fb_blur_X2.begin();
                    ofClear(0,0,0,0);
                    fb_blur_X2.end();
                    fb_blur_Y2.begin();
                    ofClear(0,0,0,0);
                    fb_blur_Y2.end();
                    fade2 = 255;
                    layer_2_free = true;
                    stop_m2 = false;
                    contador_2 = 0;
                   
                }
            }
        }
    
    
    
    
    if ((f_shroom_3<58) && (play_shroom_3)){                  // chequea play y si no ha llegado al final
        f_shroom_3++;                                       // avanza cuadro
        if (!esporoma_status_3) esporoma_status_3 = true;     // activa status play
    }
    else {
        if (esporoma_status_3) {                            // si llega aquí con status play es que terminó
            puf_3 = true;                                     // esporula
            esporoma_status_3 = false;                      // status stop
            primer_puf_3 = true;
            num_esp_3 = 0;        }
    }
    
    if (puf_3) {
        if (primer_puf_3) inicio_puf_3 = ofGetElapsedTimeMillis();
        primer_puf_3 = false;
        ahora_puf_3 = ofGetElapsedTimeMillis();
        if ((ahora_puf_3-inicio_puf_3)>2000) {
            esporula(punto_m3,150);
            inicio_puf_3 = ofGetElapsedTimeMillis();
            ++num_esp_3;
            if (num_esp_3==3) {
                puf_3=false;
                wait_e3 = true;
                wait_m3 = true;
                tiempo_wait_e3 = true;
                tiempo_wait_m3 = true;
            }
        }
    }
    
    if (wait_e3) {
        if (tiempo_wait_e3) wait_kill_e3 = ofGetElapsedTimeMillis();
        tiempo_wait_e3 = false;
        ahora_wait_e3 = ofGetElapsedTimeMillis();
        if ((ahora_wait_e3-wait_kill_e3)>5000) {
           wait_e3 = false;
           kill_e3 = true;
            tiempo_kill_e3= true;

            }
        }
    
    if (wait_m3) {
        if (tiempo_wait_m3) wait_kill_m3 = ofGetElapsedTimeMillis();
        tiempo_wait_m3 = false;
        ahora_wait_m3 = ofGetElapsedTimeMillis();
        if ((ahora_wait_m3-wait_kill_m3)>20000) {
           wait_m3 = false;
           kill_m3 = true;
            tiempo_kill_m3 = true;

            }
        }
        
    
    if (kill_e3) {
            if (tiempo_kill_e3) inicio_kill_e3 = ofGetElapsedTimeMillis();
            tiempo_kill_e3 = false;
            ahora_kill_e3 = ofGetElapsedTimeMillis();
            if ((ahora_kill_e3-inicio_kill_e3)>10) {
                fade_esporomas_3--;
                inicio_kill_e3 = ofGetElapsedTimeMillis();
                if (fade_esporomas_3==0) {
                    kill_e3 = false;
                    play_shroom_3 = false;
                    f_shroom_3 = 0;
                    fb_esporomas_3.begin();
                    ofClear(0,0,0,0);
                    fb_esporomas_3.end();
                    fade_esporomas_3 = 255;
                }
            }
        }
    
    if (kill_m3) {
            if (tiempo_kill_m3) inicio_kill_m3 = ofGetElapsedTimeMillis();
            tiempo_kill_m3 = false;
            ahora_kill_m3 = ofGetElapsedTimeMillis();
            if ((ahora_kill_m3-inicio_kill_m3)>10) {
                fade3--;
                inicio_kill_m3 = ofGetElapsedTimeMillis();
                if (fade3==0) {
                    kill_m3 = false;
                    micelio_player_3.clear();
                    fb_player_3.begin();
                    ofClear(0,0,0,0);
                    fb_player_3.end();
                    fb_blur_X3.begin();
                    ofClear(0,0,0,0);
                    fb_blur_X3.end();
                    fb_blur_Y3.begin();
                    ofClear(0,0,0,0);
                    fb_blur_Y3.end();
                    fade3 = 255;
                    layer_3_free = true;
                    stop_m3 = false;
                    contador_3 = 0;
                }
            }
        }
    
#ifdef KINECT
    kinect.update();
    if (kinect.isFrameNew()) {
        grayImage.setFromPixels(kinect.getDepthPixels());
        grayImage.mirror(0,1);
        grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(cerca, true);
        grayThreshFar.threshold(lejos);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
        contourFinder.setMinAreaRadius(minimo);
        contourFinder.setMaxAreaRadius(maximo);
        contourFinder.setThreshold(0);
        contourFinder.findContours(grayImage);
        contourFinder.setFindHoles(false);
        contourFinder.setSimplify(false);
        
        //players = contourFinder.size();
        
      
    }
#endif
    
    players = modo;  // cambiar por contourFinder.size
    
    if (players<4) {
        if (players!=antiguos) {
            nuevos = players-antiguos;
            if (nuevos==1) {
                new_layer();
            }
            if (nuevos==2) {
                new_layer();
                new_layer();
            }
            if (nuevos==3) {
                new_layer();
                new_layer();
                new_layer();
            }
            antiguos = players;
        }
    }
    
    
    else {
        //bla
    }
    
    
  
    
    tet = morphogenesis(micelio_player_1,100);
    tet2 = morphogenesis(micelio_player_2,100);
    tet3 = morphogenesis(micelio_player_3,100);
    
    
    
    if ((tet)&&(!stop_m1)) {
        if (!players) kill_m1=true;
        else {
            contador_1++;
            if (contador_1>2) {
                stop_m1= true;
                play_shroom_1=true;
                f_shroom_1 = 0;
                shroom_1 = ofRandom(5);
                pos_esporoma_1 = origen_1;
            }
            else start_micelio_1();
        }
    }
    
    if ((tet2)&&(!stop_m2)) {
        if (!players) kill_m2=true;
        else {
            contador_2++;
            if (contador_2>3) {
                stop_m2= true;
                play_shroom_2=true;
                f_shroom_2 = 0;
                shroom_2 = ofRandom(5);
                pos_esporoma_2 = origen_2;
            }
            else start_micelio_2();
        }
    }
    
    if ((tet3)&&(!stop_m3)) {
        if (!players) kill_m3=true;
        else {
            
            contador_3++;
            if (contador_3>1) {
                stop_m3= true;
                play_shroom_3=true;
                f_shroom_3 = 0;
                shroom_3 = ofRandom(5);
                pos_esporoma_3 = origen_3;
            }
            else start_micelio_3();
        }
    }
    
    
    
    esporulacion(esporas,5000);
    
    if (ord.size()) {
        
        ofVec2f manoD(ord[2].x*3.,ord[2].y*2.);
        ofVec2f manoI(ord[0].x*3.,ord[0].y*2.);
        float minDis = 100;
        
        for(auto &box : esporas) {
            float dis = manoD.distance(box->getPosition());
            float dis2 = manoI.distance(box->getPosition());
            if(dis < minDis) box->addRepulsionForce(manoD, 3.);
            if(dis2 < minDis) box->addRepulsionForce(manoI, 3.);
            //box->addAttractionPoint(mouse, 1.0);
        }
    }
    
    
    
    float minDism = 50;
    ofVec2f posf(mouseX,mouseY);

    
    for(auto &box : esporas) {
        float dist = posf.distance(box->getPosition());
        if(dist < minDism) box->addRepulsionForce(posf, 4.);
    }
    
    
    
    
    
    
    
    
    
    

    box2d.update();
    box2d_esporas.update();
    ofRemove(micelio_player_1, ofxBox2dBaseShape::shouldRemoveOffScreen);
    ofRemove(micelio_player_2, ofxBox2dBaseShape::shouldRemoveOffScreen);
    ofRemove(micelio_player_3, ofxBox2dBaseShape::shouldRemoveOffScreen);
    ofRemove(esporas, CustomParticle::shouldRemoveEsporas);
    fb_player_1.begin();
    draw_fb_player(micelio_player_1);
    fb_player_1.end();
    fb_player_2.begin();
    draw_fb_player(micelio_player_2);
    fb_player_2.end();
    fb_player_3.begin();
    draw_fb_player(micelio_player_3);
    fb_player_3.end();
    fb_esporas.begin();
    ofClear(0,0,0,0);
    draw_fb_player(esporas);
    fb_esporas.end();
}

void ofApp::new_layer() {
   
    bool ready = false;
    
    if (layer_1_free&&!ready) {
        start_micelio_1();
        ready = true;
        layer_1_free = false;
    }
    
    if (layer_2_free&&!ready) {
        start_micelio_2();
        ready = true;
        layer_2_free = false;
    }
    
    if (layer_3_free&&!ready) {
        start_micelio_3();
        ready = true;
        layer_3_free = false;
    }
    
    
}
  
void ofApp::start_micelio_1() {
    origen_1 = (ofRandom(37.5,62.5))/100.;
    if (edges.size()>0) punto_m1=edges[0]->getPointAtPercent(origen_1);
    for (int i=0;i<10;i++) {
        auto particle = make_shared<CustomParticle>(box2d.getWorld(),punto_m1.x ,600-offset_fb_y); //
        particle->setRadius(0.3);
        particle->color.set(255,255,255,255);
        micelio_player_1.push_back(particle);
    }
}

void ofApp::start_micelio_2() {
    origen_2 = (ofRandom(62.5,87.5))/100.;
    if (edges.size()>0) punto_m2=edges[0]->getPointAtPercent(origen_2);
    
    for (int i=0;i<10;i++) {
        auto particle = make_shared<CustomParticle>(box2d.getWorld(),punto_m2.x,600-offset_fb_y); //
        particle->setRadius(0.3);
        particle->color.set(255,255,255,255);
        micelio_player_2.push_back(particle);
    }
}

void ofApp::start_micelio_3() {
    origen_3 = (ofRandom(12.5,37.5))/100.;
    if (edges.size()>0) punto_m3=edges[0]->getPointAtPercent(origen_3);
    
    for (int i=0;i<10;i++) {
        auto particle = make_shared<CustomParticle>(box2d.getWorld(),punto_m3.x,600-offset_fb_y); //
        particle->setRadius(0.3);
        particle->color.set(255,255,255,255);
        micelio_player_3.push_back(particle);
    }
}

void ofApp::esporula(ofVec2f punto, int espora) {
    for (int i=0;i<espora;i++) {
        auto particle = make_shared<CustomParticle>(box2d_esporas.getWorld(), punto.x, punto.y+offset_fb_y-100);
        particle->setRadius(0.05);
        esporas.push_back(particle);
    }
}

void ofApp::esporula_continuo(ofVec2f punto, int espora) {
    int rojo = ofRandom(255);
    int verde = ofRandom(255);
    int azul = ofRandom(255);
    
    for (int i=0;i<espora;i++) {
        auto particle = make_shared<CustomParticle>(box2d_esporas.getWorld(), ofRandom(500)+500, ofRandom(500));
        particle->color.set(255,255,255,255);
        particle->setRadius(0.2);
        esporas.push_back(particle);
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
  
    if (!color_fondo) ofBackground(0,0,0);
    else ofBackground(0,0,255);
   
    ofSetColor(230,200,0);
    for (auto &line : lines) line.draw();
    if (lineas) {                    // Tecla 'l' dibuja línea horizonte
    for (auto & edge : edges) {
        ofPushMatrix();
        ofTranslate(0,offset_fb_y);
        edge->draw();
        ofPopMatrix();
    }
}

    gaussian_blur();
    
    ofSetColor(255,255,255,255);
    fb_esporas.draw(0,0);                        // dibuja framebuffer de esporas
    
    ofSetColor(255,255,255,fade_esporomas_1);    // dibuja framebuffers de esporomas
    fb_esporomas_1.draw(0,0);
    ofSetColor(255,255,255,fade_esporomas_2);
    fb_esporomas_2.draw(0,0);
    ofSetColor(255,255,255,fade_esporomas_3);
    fb_esporomas_3.draw(0,0);
    
    ofSetColor(255,255,255,fade1);               // dibuja framebuffers de micelios
    fb_blur_Y1.draw(0,offset_fb_y);
    ofSetColor(255,255,255,fade2);
    fb_blur_Y2.draw(0,offset_fb_y);
    ofSetColor(255,255,255,fade3);
    fb_blur_Y3.draw(0,offset_fb_y);
    ofSetColor(255,255,255,255);
    ofNoFill();
    ofDrawCircle(mouseX,mouseY,30);
 
#ifdef KINECT
   
        int n = contourFinder.size();
    
    if (n) {
        centroid1 = toOf(contourFinder.getCentroid(0));
        ofFill();
        ofSetHexColor(0xFF0000);
        ofDrawCircle(centroid1.x,centroid1.y, 15);
    }
    
  //  if (n) {
        //if (n==2) {
         //   centroid1 = toOf(contourFinder.getCentroid(0));
         //   centroid2 = toOf(contourFinder.getCentroid(1));
           // ofFill();
            //ofSetHexColor(0xFF0000);
           // ofDrawCircle(centroid1.x*3.,600, 15);
           // ofDrawCircle(centroid2.x*3.,600, 15);
      //  }
        
     //  if (n==1) {
       //     centroid1 = toOf(contourFinder.getCentroid(0));
       //     ofFill();
           // ofSetHexColor(0xFF0000);
           // ofDrawCircle(centroid1.x*3.,600, 15);
      //  }
        
      //  if (n==3) {
      //  }
       // }
        
        
    if (n>0) {
        ofPolyline convexHull = toOf(contourFinder.getFitQuad(0));
        ord.clear();
        for (int i=0;i<int(convexHull.size());i++) {
            glm::vec2 ordi(convexHull.getVertices()[i].x,convexHull.getVertices()[i].y);
            ord.push_back(ordi);
        }
        
       
        ofSort(ord,&sort_y);
        ord.pop_back();
        ord.pop_back();
        ofSort(ord,&sort_x);
        
        
        
        glm::vec2 mano1(ord[0].x*3.,ord[0].y*2.);
        avg.pop_front();
        avg.push_back(mano1);
        glm::vec2 pl;
        int tam = avg.size();
        for (int i=0; i<tam ; i++) pl +=avg[i];
        pl = pl/tam;
        m1.x=pl.x;
        m1.y=pl.y;
        
        glm::vec2 mano2(ord[2].x*3.,ord[2].y*2.);
        avg2.pop_front();
        avg2.push_back(mano2);
        glm::vec2 pl2;
        int tam2 = avg2.size();
        for (int i=0; i<tam2 ; i++) pl2 +=avg2[i];
        pl2 = pl2/tam2;
        m2.x=pl2.x;
        m2.y=pl2.y;
        
        grayImage.draw(0,0,640,480);
        
       
        ofDrawCircle(m2,20);
        convexHull.draw();
        contourFinder.draw();
        ofSetColor(255);
        ofDrawCircle(centroid1,10);
        
    }
#endif

    if (play_shroom_1) callampas_1(shroom_1,punto_m1);
    if (play_shroom_2) callampas_2(shroom_2,punto_m2);
    if (play_shroom_3) callampas_3(shroom_3,punto_m3);
 
    if (gui) {
        gui1.draw();
        gui2.draw();
        gui3.draw();
        gui4.draw();
        gui5.draw();
    }
    picture_in_picture();
    reporte();
    ofDrawBitmapString(ofToString(players),1222,72);
    int n_esporas = esporas.size();
    ofDrawBitmapString(ofToString(n_esporas),800,72);
    if (n_esporas<300) esporula_continuo(ofVec2f(500,500-offset_fb_y),100);
}

bool ofApp::sort_x(glm::vec2 &a, glm::vec2 &b) {
    if (a.x < b.x){
         return true;
     } else {
         return false;
     }
}

bool ofApp::sort_y(glm::vec2 &a, glm::vec2 &b) {
    if (a.y < b.y){
         return true;
     } else {
         return false;
     }
}

void ofApp::callampas_1(int seta, ofVec2f pos) {
    
    fb_esporomas_1.begin();
    ofClear(0,0,0,0);
        if (seta==0) {
            Amanita.getFrame(f_shroom_1/2)->draw(pos.x-50,pos.y+offset_fb_y-114 ,100,150);
        }
        if (seta==1) {
            Cortinarius.getFrame(f_shroom_1/2)->draw(pos.x-50,pos.y+offset_fb_y-120,100,150);
        }
        if (seta==2) {
            Cortinariusx3.getFrame(f_shroom_1/2)->draw(pos.x-50,pos.y+offset_fb_y-130,100,150);
        }
        if (seta==3) {
            Leucocoprinus.getFrame(f_shroom_1/2)->draw(pos.x-50,pos.y+offset_fb_y-100,100,150);
    }
        if (seta==4) {
            Morchella.getFrame(f_shroom_1/2)->draw(pos.x-50,pos.y+offset_fb_y-100,100,150);
    }
    
fb_esporomas_1.end();
    
}

void ofApp::callampas_2(int seta, ofVec2f pos) {
    
    fb_esporomas_2.begin();
    ofClear(0,0,0,0);
        if (seta==0) {
            Amanita.getFrame(f_shroom_2/2)->draw(pos.x-50,pos.y+offset_fb_y-114 ,100,150);
        }
        if (seta==1) {
            Cortinarius.getFrame(f_shroom_2/2)->draw(pos.x-50,pos.y+offset_fb_y-120,100,150);
        }
        if (seta==2) {
            Cortinariusx3.getFrame(f_shroom_2/2)->draw(pos.x-50,pos.y+offset_fb_y-130,100,150);
        }
        if (seta==3) {
            Leucocoprinus.getFrame(f_shroom_2/2)->draw(pos.x-50,pos.y+offset_fb_y-100,100,150);
    }
        if (seta==4) {
            Morchella.getFrame(f_shroom_2/2)->draw(pos.x-50,pos.y+offset_fb_y-90,100,150);
    }
    
fb_esporomas_2.end();
    
}

void ofApp::callampas_3(int seta, ofVec2f pos) {
    
    fb_esporomas_3.begin();
    ofClear(0,0,0,0);
        if (seta==0) {
            Amanita.getFrame(f_shroom_3/2)->draw(pos.x-50,pos.y+offset_fb_y-114 ,100,150);
        }
        if (seta==1) {
            Cortinarius.getFrame(f_shroom_3/2)->draw(pos.x-50,pos.y+offset_fb_y-120,100,150);
        }
        if (seta==2) {
            Cortinariusx3.getFrame(f_shroom_3/2)->draw(pos.x-50,pos.y+offset_fb_y-130,100,150);
        }
        if (seta==3) {
            Leucocoprinus.getFrame(f_shroom_3/2)->draw(pos.x-50,pos.y+offset_fb_y-100,100,150);
    }
        if (seta==4) {
            Morchella.getFrame(f_shroom_3/2)->draw(pos.x-50,pos.y+offset_fb_y-90,100,150);
    }
    
fb_esporomas_3.end();
    
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    bool flecha = true;
    
    if (key>47 && key<58) modo=key-48;
    if (key == 'y') {
       // play_shroom=true;
        //f_shroom = 0;
        //shroom = ofRandom(5);
        //pos_esporoma = ofRandom(1);
    }
    if (key == 'k') kontorno=!kontorno ;
    if (key == 'g') gui=!gui ;
    if (key == 'i') info=!info ;
    if (key == 'l') lineas=!lineas ;
    if (key == 'f') ofHideCursor();
    if (key == 'm') ofShowCursor();
    if (key == 'q') color_fondo=!color_fondo;
    if (key == 'o') silueta=!silueta;
    if (key == 't') simpli=!simpli;
    if (key == 'p') {
        pip++;
        pip%=3;
    }
    if (key == 's') {
        micelio_player_1.clear();
        fb_player_1.begin();
        ofClear(0,0,0,0);
        fb_player_1.end();
        fb_blur_X1.begin();
        ofClear(0,0,0,0);
        fb_blur_X1.end();
        fb_blur_Y1.begin();
        ofClear(0,0,0,0);
        fb_blur_Y1.end();
        micelio_player_2.clear();
        fb_player_2.begin();
        ofClear(0,0,0,0);
        fb_player_2.end();
        fb_blur_X2.begin();
        ofClear(0,0,0,0);
        fb_blur_X2.end();
        fb_blur_Y2.begin();
        ofClear(0,0,0,0);
        fb_blur_Y2.end();
        micelio_player_3.clear();
        fb_player_3.begin();
        ofClear(0,0,0,0);
        fb_player_3.end();
        fb_blur_X3.begin();
        ofClear(0,0,0,0);
        fb_blur_X3.end();
        fb_blur_Y3.begin();
        ofClear(0,0,0,0);
        fb_blur_Y3.end();
    }
    if (key == 'a') {
        vsync=!vsync;
        ofSetVerticalSync(vsync);
    }
    if (key == 'z') {
        //ofSetBackgroundAuto(false);
        for (int i=0;i<10;i++) {
            auto particle = make_shared<CustomParticle>(box2d.getWorld(), mouseX ,mouseY-offset_fb_y); //
            particle->setRadius(0.3);
            particle->color.set(0,255,255,255);
            micelio_player_1.push_back(particle);
        }
    }
    
    if (key == 'x') {
        for (int i=0;i<5;i++) {
            auto particle = make_shared<CustomParticle>(box2d.getWorld(), mouseX ,mouseY-offset_fb_y);
            particle->setRadius(0.3);
            particle->color.set(255,0,255,255);
            micelio_player_2.push_back(particle);
        }
    }
    
    if(key == 'c') {
        //ofSetBackgroundAuto(false);
        for (int i=0;i<3;i++) {
            auto particle = make_shared<CustomParticle>(box2d.getWorld(), mouseX ,mouseY-offset_fb_y);
            particle->setRadius(0.3);
            particle->color.set(255,255,0,255);
            micelio_player_3.push_back(particle);
        }
    }
    
    if(key == 'v') {
    esporula(ofVec2f(mouseX,mouseY-offset_fb_y+100),100);
    }
        
        // want to save out some line...
        if(key == ' ') {
            ofstream f;
            f.clear();
            f.open(ofToDataPath("lines_.txt").c_str());
            for (int i=0; i<lines.size(); i++) {
                for (int j=0; j<lines[i].size(); j++) {
                    float x = lines[i][j].x;
                    float y = lines[i][j].y;
                    f << x << "," << y << ",";
                }
                f << "\n";
            }
            f.close();lines.clear();
        }
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
   // lines.back().addVertex(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
   // lines.push_back(ofPolyline());
   // lines.back().addVertex(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
   // auto edge = make_shared<ofxBox2dEdge>();
   // lines.back().simplify();
  //  for (int i=0; i<lines.back().size(); i++) {
  //      edge->addVertex(lines.back()[i]+ofPoint(0,-offset_fb_y));
  //  }
  //  edge->create(box2d.getWorld());
  //  edges.push_back(edge);
}

//--------------------------------------------------------------

int ofApp::morphogenesis(vector<shared_ptr<CustomParticle>> &micelio_player, int lifetime) {
    
    int ret= 0;
    bool borra_micelio = false;                                 // flag para limpiar micelio al fin del loop
    int size = micelio_player.size();                           // asignamos tamaño antes del loop ya que lo modificaremos
    
    if (size) {                                                 // si el micelio tiene hifas ejecuta el loop
        
        for (int i=0;i<size;i++) {
            ofVec2f bump;                                       // creamos vector 2f temporal para bump
            bump.set(ofRandom(-1,1),ofRandom(-1,1));            // le asignamos valores random
            bump *= random;                                     // multiplicamos for factor random
            bump += micelio_player[i]->getVelocity();           // sumamos velocidad de hifa[i]
            bump.normalize();                                   // normaliza
            
            if (size<lifetime)   {                              // si es menor al máximo de hifas
                micelio_player[i]->setVelocity(bump.x,bump.y);  //
                
              //if (ofRandom(0,1)<0.5) micelio_player[i]->addAttractionPoint(mouseX,mouseY-(ofRandom(3)*100),0.0001);
                
                if (ofRandom(0,1)<0.003) {                      // factor de mitosis
                    auto nueva = make_shared<CustomParticle>(box2d.getWorld(), micelio_player[i]->getPosition().x,micelio_player[i]->getPosition().y);
                    nueva->setRadius(micelio_player[i]->getRadius());
                    micelio_player.push_back(nueva);
                }
            }
            else {
                borra_micelio = true;
                ret = 1;
            }
        }
        if (borra_micelio) micelio_player.clear();
    }
    return(ret);
}

int ofApp::esporulacion(vector<shared_ptr<CustomParticle>> &esporas, int lifetime) {
    
    int ret= 0;
    bool borra_esporas = false;                                 // flag para limpiar micelio al fin del loop
    int size = esporas.size();                                  // asignamos tamaño antes del loop ya que lo modificaremos
    
    if (size) {                                                 // si el micelio tiene hifas ejecuta el loop
        for (int i=0;i<size;i++) {
            ofVec2f bump;                                       // creamos vector 2f temporal para bump
            bump.set(ofRandom(-1,1),ofRandom(-1,1));            // le asignamos valores random
            bump *= random;                                     // multiplicamos for factor random
            bump += esporas[i]->getVelocity();                  // sumamos velocidad de hifa[i]
            bump.normalize();                                   // normaliza
            
            if (size<lifetime)   {                              // si es menor al máximo de hifas
                esporas[i]->setVelocity(bump.x,bump.y);
            }
            else {
                borra_esporas = true;
                ret = 1;
            }
        }
        if (borra_esporas) esporas.clear();
    }
    return(ret);
}

void ofApp::draw_fb_player(vector <shared_ptr<CustomParticle>> &micelio_player) {
    for (auto &particle : micelio_player) {
        particle->draw();
    }
}

void ofApp::carga_lineas() {
    
        ifstream f;
        f.open(ofToDataPath("lines.txt").c_str());
        vector <string> strLines;
        while (!f.eof()) {
            string ptStr;
            getline(f, ptStr);
            strLines.push_back(ptStr);
        }
        f.close();
        
        for (int i=0; i<strLines.size(); i++) {
            vector <string> pts = ofSplitString(strLines[i], ",");
            if(pts.size() > 0) {
                auto edge = make_shared<ofxBox2dEdge>();
               // auto edge2 = make_shared<ofxBox2dEdge>();
                for (int j=0; j<pts.size(); j+=2) {
                    if(pts[j].size() > 0) {
                        float x = ofToFloat(pts[j]);
                        float y = ofToFloat(pts[j+1]);
                        edge->addVertex(x, y-offset_fb_y);
                      //  edge2->addVertex(x, y);
                        
                    }
                }
                edge->create(box2d.getWorld());
               // edge2->create(box2d_esporas.getWorld());
                
                edges.push_back(edge);
               // edges_esporas.push_back(edge2);
            }
        }
}

void ofApp::gaussian_blur() {
    
    fb_blur_X1.begin();
    ofSetColor(255);
    shaderX.begin();
    shaderX.setUniformTexture("tex0", fb_player_1.getTexture(),1);
    shaderX.setUniform1f("blurAmnt", blur);
    shaderX.setUniform1f("texwidth", fb_x);
    fb_player_1.draw(0,0);
    shaderX.end();
    fb_blur_X1.end();
    
    fb_blur_Y1.begin();
    ofSetColor(255);
    shaderY.begin();
    shaderY.setUniformTexture("tex0", fb_blur_X1.getTexture(),1);
    shaderY.setUniform1f("blurAmnt", blur);
    shaderY.setUniform1f("texheight", fb_y);
    fb_blur_Y1.draw(0,0);
    shaderY.end();
    fb_blur_Y1.end();
    
    fb_blur_X2.begin();
    ofSetColor(255);
    shaderX.begin();
    shaderX.setUniformTexture("tex0", fb_player_2.getTexture(),1);
    shaderX.setUniform1f("blurAmnt", blur);
    shaderX.setUniform1f("texwidth", fb_x);
    fb_player_2.draw(0,0);
    shaderX.end();
    fb_blur_X2.end();
    
    fb_blur_Y2.begin();
    ofSetColor(255);
    shaderY.begin();
    shaderY.setUniformTexture("tex0", fb_blur_X2.getTexture(),1);
    shaderY.setUniform1f("blurAmnt", blur);
    shaderY.setUniform1f("texheight", fb_y);
    fb_blur_Y2.draw(0,0);
    shaderY.end();
    fb_blur_Y2.end();
    
    fb_blur_X3.begin();
    ofSetColor(255);
    shaderX.begin();
    shaderX.setUniformTexture("tex0", fb_player_3.getTexture(),1);
    shaderX.setUniform1f("blurAmnt", blur);
    shaderX.setUniform1f("texwidth", fb_x);
    fb_player_3.draw(0,0);
    shaderX.end();
    fb_blur_X3.end();
    
    fb_blur_Y3.begin();
    ofSetColor(255);
    shaderY.begin();
    shaderY.setUniformTexture("tex0", fb_blur_X3.getTexture(),1);
    shaderY.setUniform1f("blurAmnt", blur);
    shaderY.setUniform1f("texheight", fb_y);
    fb_blur_Y3.draw(0,0);
    shaderY.end();
    fb_blur_Y3.end();
}

void ofApp::allocate_fb(){
    
    
    //  -------------- framebuffer settings -----------------------
    
    fb_esporomas_1.allocate(1920,1200,GL_RGBA);
    fb_esporomas_1.begin();
    ofClear(0,0,0,0);
    fb_esporomas_1.end();
    
    fb_esporomas_2.allocate(1920,1200,GL_RGBA);
    fb_esporomas_2.begin();
    ofClear(0,0,0,0);
    fb_esporomas_2.end();
    
    fb_esporomas_3.allocate(1920,1200,GL_RGBA);
    fb_esporomas_3.begin();
    ofClear(0,0,0,0);
    fb_esporomas_3.end();
    
    fb_esporas.allocate(1920,1200,GL_RGBA);
    fb_esporas.begin();
    ofClear(0,0,0,255);
    fb_esporas.end();
    
    fb_player_1.allocate(fb_x,fb_y,GL_RGBA);
    fb_player_1.begin();
    ofClear(0,0,0,0);
    fb_player_1.end();
    
    fb_player_2.allocate(fb_x,fb_y,GL_RGBA);
    fb_player_2.begin();
    ofClear(0,0,0,0);
    fb_player_2.end();
    
    fb_player_3.allocate(fb_x,fb_y,GL_RGBA);
    fb_player_3.begin();
    ofClear(0,0,0,0);
    fb_player_3.end();
    
    fb_blur_X1.allocate(fb_x,fb_y,GL_RGBA);
    fb_blur_X1.begin();
    ofClear(0,0,0,0);
    fb_blur_X1.end();
    
    fb_blur_Y1.allocate(fb_x,fb_y,GL_RGBA);
    fb_blur_Y1.begin();
    ofClear(0,0,0,0);
    fb_blur_Y1.end();
    
    fb_blur_X2.allocate(fb_x,fb_y,GL_RGBA);
    fb_blur_X2.begin();
    ofClear(0,0,0,0);
    fb_blur_X2.end();
    
    fb_blur_Y2.allocate(fb_x,fb_y,GL_RGBA);
    fb_blur_Y2.begin();
    ofClear(0,0,0,0);
    fb_blur_Y2.end();
    
    fb_blur_X3.allocate(fb_x,fb_y,GL_RGBA);
    fb_blur_X3.begin();
    ofClear(0,0,0,0);
    fb_blur_X3.end();
    
    fb_blur_Y3.allocate(fb_x,fb_y,GL_RGBA);
    fb_blur_Y3.begin();
    ofClear(0,0,0,0);
    fb_blur_Y3.end();
    // ---------------------------------------------------------------
}

void ofApp::gui_settings() {
    // ------------------ gui settings -------------------------------
    gui1.setup();
    gui1.add(gravedadX.set("gravedad X",0.f,-2.0,2.0));
    gui1.add(gravedadY.set("gravedad Y",gY,-2.0,2.0));
    gui1.add(blur.set("blur",0.6,0.0,2.0));
    gui1.add(random.set("random",0.2, 0.0, 1.0));
    gui1.add(minimo.set("min",45, 0, 255));
    gui1.add(maximo.set("max",180, 0, 255));
    gui1.add(altura_micelio.set("altura micelio",-223, -250, 100));
    gui1.add(cerca.set("umbral cerca",240, 50, 255)); //UMBRAL SALA
    gui1.add(lejos.set("umbral lejos",120, 0, 255));   //UMBRAL SALA
    
    gui2.setup("player 1");
    gui2.setPosition(220,10);
    gui2.add(fade1.set("fade",255, 0, 255));
    gui2.add(tamano1.set("radio",0.3, 0.0, 3.0));
    
    gui3.setup("player 2");
    gui3.setPosition(440,10);
    gui3.add(fade2.set("fade",255, 0, 255));
    gui3.add(tamano2.set("radio",0.4, 0.0, 3.0));
    
    gui4.setup("player 3");
    gui4.setPosition(660,10);
    gui4.add(fade3.set("fade",255, 0, 255));
    gui4.add(tamano3.set("radio",0.5, 0.0, 3.0));
    
    gui5.setup("shroom");
    gui5.add(fade_esporomas_1.set("fade 1",255, 0, 255));
    gui5.add(fade_esporomas_2.set("fade 2",255, 0, 255));
    gui5.add(fade_esporomas_3.set("fade 3",255, 0, 255));
    gui5.setPosition(880,10);
}

void ofApp::reporte() {
    if (info) {
        ofPushMatrix();
        ofTranslate(1440,10);
        ofDrawBitmapString("x: "+ ofToString(mouseX),0,10);
        ofDrawBitmapString("y: "+ ofToString(mouseY),0,20);
        ofDrawBitmapString("player 1: "+ ofToString(micelio_player_1.size()),0,30);
        ofDrawBitmapString("player 2: "+ ofToString(micelio_player_2.size()),0,40);
        ofDrawBitmapString("player 3: "+ ofToString(micelio_player_3.size()),0,50);
        ofDrawBitmapString("lineas: "+ ofToString(edges.size()),0,60);
#ifdef KINECT
        ofDrawBitmapString("Kinect W: "+ ofToString(kinect.getWidth()),0,70);
        ofDrawBitmapString("Kinect H: "+ ofToString(kinect.getHeight()),0,80);
#endif
        ofDrawBitmapString("key: "+ ofToString(modo),0,90);
        //ofDrawBitmapString("CX: "+ ofToString(centroid.x),0,100);
        ofDrawBitmapString("gY: "+ ofToString(gravedadY),0,110);
        ofDrawBitmapString("TEST: "+ ofToString(tet),0,120);
        ofDrawBitmapString("players: "+ ofToString(players),0,130);
        ofDrawBitmapString("nuevos: "+ ofToString(nuevos),0,140);
        ofDrawBitmapString("antiguos: "+ ofToString(antiguos),0,150);
        ofDrawBitmapString("layer: "+ ofToString(layer_actual),0,160);
        ofDrawBitmapString("origen_1 "+ ofToString(origen_1),0,170);

        ofPopMatrix();
    }
}

void ofApp::picture_in_picture() {
    
    ofVec2f posk,tamk;
    if (pip!=0) {
        if (pip==1) {
            posk.set(1600,10);
            tamk.set(320,240);
        }
        if (pip==2) {
            posk.set(160,0);
            tamk.set(1600,1200);
        }
        ofPushMatrix();
        ofTranslate(posk);
#ifdef KINECT
        grayImage.draw(0,0,tamk.x,tamk.y);
#endif
        ofPopMatrix();
        ofSetColor(255);
    }
}


