#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetOrientation(OF_ORIENTATION_90_LEFT);
    
    
    //blue
    blue.r=0;
    blue.g=215;
    blue.b=255;
    
    //yellow
    yellow.r=255;
    yellow.g=243;
    yellow.b=0;
    
    //green
    green.r=0;
    green.g=255;
    green.b=172;
    
    bgColor=green;
    
    ofBackground(bgColor);
    
    ofSetBackgroundAuto(true);

	// open an outgoing connection to HOST:PORT
	sender.setup( HOST, PORT );
    isTouchSent =false;
    
    touchCount=0;
    
    //ofSetFrameRate(60);

    
    
}

//--------------------------------------------------------------
void ofApp::update(){
	//we do a heartbeat on iOS as the phone will shut down the network connection to save power
	//this keeps the network alive as it thinks it is being used. 
	if( ofGetFrameNum() % 120 == 0 ){
		ofxOscMessage m;
		m.setAddress( "/misc/heartbeat" );
		m.addIntArg( ofGetFrameNum() );
		sender.sendMessage( m );
	}
    
    for(int i=0;i<myTouches.size();i++){
        myTouches[i].update();
    }
    
    ofBackground(bgColor);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
     ofSetColor(255, 255, 255);
     newTouch.draw();

}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){
	ofxOscMessage m;
	m.setAddress( "/mouse/button" );
//    m.addStringArg( "down" );
    m.addBoolArg(true);

    //touch create new Touch
    newTouch.setup(touch);
    
    //touch Count
    touchCount+=1;
    
    if(touchCount%3==1){
        bgColor=blue;
        m.addStringArg("Blue");
        
    }
    if(touchCount%3==2){
        bgColor=yellow;
        m.addStringArg("Yellow");
    }
    if(touchCount%3==0){
        bgColor=green;
        m.addStringArg("Green");
    }
    
//    //m.addRgbaColorArg();
//    m.addIntArg( bgColor.r );
//    m.addIntArg( bgColor.g );
//    m.addIntArg( bgColor.b );

    sender.sendMessage( m );
    
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){
	ofxOscMessage m;
	m.setAddress( "/mouse/position" );
	m.addIntArg( touch.x );
	m.addIntArg( touch.y );
	sender.sendMessage( m );
    
    //move update newTouch
    newTouch.update();
}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){
	ofxOscMessage m;
	m.setAddress( "/mouse/button" );
//    m.addStringArg( "up" );
	sender.sendMessage( m );
}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){
    isTouchSent=true;
    myTouches.push_back(newTouch);
    
    //pushback the newTouch to myTouchesList(sent)
    myTouches.push_back(newTouch);
    
    

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}
