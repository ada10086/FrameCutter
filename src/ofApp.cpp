#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(true);
    ofClear(0);
    
    // setup the audio stream
    soundStream.setup(numberOfOutputChannels, numberOfInputChannels, sampleRate, frameSize, numberOfBuffers);
    //instead of frameSize, frameSize*2?
    //    soundStream.setup(<#int outChannels#>, <#int inChannels#>, <#int sampleRate#>, <#int bufferSize#>, <#int nBuffers#>)
    
    
    mltk.setup(frameSize, sampleRate, frameSize/2);
    mltk.run();
}

//--------------------------------------------------------------
void ofApp::update(){
    mltk.run();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (isSavingPDF) {
        ofBeginSaveScreenAsPDF("savedScreenshot_"+ofGetTimestampString()+".pdf");
    }
    
    ofSetColor(0);
    

    vector<Real> frameCutter = mltk.getData("FrameCutter");

    //    //    path.setFillColor(ofColor(255,0,0));
    //        path.setFillColor(0);
    //
    //        for(int i = 0; i < frameCutter.size(); i++){
    //            float angle = ofMap(i, 0, frameCutter.size(), 0, 2*PI, true);
    //            float p2X = frameCutter[i] * cos(angle) * 4000 + ofGetWidth()/2;
    //            float p2Y = frameCutter[i] * sin(angle) * 4000 + ofGetHeight()/2;
    //            path.lineTo(p2X,p2Y);
    //        }
    //        path.close();
    //        path.draw();
    
    glBegin(GL_LINES);
    ofSetLineWidth(3);
    //        path.setFillColor(ofColor(255,0,0));
    for(int i = 0; i < frameCutter.size(); i++){
        float p2X = i * ofGetWidth()/float(frameCutter.size());
        float p2Y = frameCutter[i] * 4000 + ofGetHeight()/2;
        //        path.lineTo(p2X,p2Y);
        glVertex2f(p2X, p2Y);
    }
    glEnd();
    
    //    ofSetLineWidth(2);
    //    float frameCutterWidth = ofGetWidth()/float(frameCutter.size());
    //    ofPolyline line;
    //
    //    for(int i = 0; i < frameCutter.size(); i++){
    //        line.lineTo(i * frameCutterWidth,
    //                    ofGetHeight()/2 + ofMap(frameCutter[i], 0, 1.0, 0, ofGetHeight()/2, false));
    //    }
    //    line.lineTo(ofGetWidth(), ofGetHeight()/2);
    //    line.draw();
    
    
    // Finish saving the PDF and reset the isSavingPDF flag to false
    // Ending the PDF tells openFrameworks to resume drawing to the screen.
    if (isSavingPDF) {
        ofEndSaveScreenAsPDF();
        isSavingPDF = false;
    }
}

void ofApp::audioIn(ofSoundBuffer &inBuffer){
    int bufCounter = 0 ;
    for(int i= 0; i < frameSize; i +=2){
        mltk.leftAudioBuffer[bufCounter] = inBuffer.getBuffer()[i];
        mltk.rightAudioBuffer[bufCounter] = inBuffer.getBuffer()[i+1];
        bufCounter ++;
    }
    //    inBuffer.getChannel(mltk.leftAudioBuffer, 0);
    //    inBuffer.getChannel(mltk.rightAudioBuffer, 1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        // isSavingPDF is a flag that lets us know whether or not save a PDF
        isSavingPDF = true;
    }
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
