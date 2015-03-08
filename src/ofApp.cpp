#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    unsorted.loadImage("hello.jpg");
    unsorted.resize(256, 192);
    
    sorted.clone(unsorted);
    ofPixels pixels = sorted.getPixelsRef();
    i = 3;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int j=0; j<256; j++)
    {
        if (i < sorted.getPixelsRef().size() ) {
        if ( i % 256 == 0 ) { i += 3; }
        float r=0, g=0, b=0;
        
        r = sorted.getPixelsRef()[i-3];
        g = sorted.getPixelsRef()[i-3+1];
        b = sorted.getPixelsRef()[i-3+2];
        float brightness = r + g + b;
        
        r = sorted.getPixelsRef()[i];
        g = sorted.getPixelsRef()[i+1];
        b = sorted.getPixelsRef()[i+2];
        float next_brightness = r + g + b;
        
        if (brightness >= next_brightness){
            i += 3;
        } else {
            float temp_r, temp_g, temp_b;
            temp_r = sorted.getPixelsRef()[i];
            temp_g = sorted.getPixelsRef()[i+1];
            temp_b = sorted.getPixelsRef()[i+2];
            
            sorted.getPixelsRef()[i] = sorted.getPixelsRef()[i-3];
            sorted.getPixelsRef()[i+1] = sorted.getPixelsRef()[i-3+1];
            sorted.getPixelsRef()[i+2] = sorted.getPixelsRef()[i-3+2];
            
            sorted.getPixelsRef()[i-3] = temp_r;
            sorted.getPixelsRef()[i-3+1] = temp_g;
            sorted.getPixelsRef()[i-3+2] = temp_b;
            
            i -= 3;
        }
    }
    
    sorted.reloadTexture();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    unsorted.draw(0, 0);
    sorted.draw(256, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
