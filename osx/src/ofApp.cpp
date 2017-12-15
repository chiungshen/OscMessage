//communication it works
//colors! bugs!
//Collode! bugs!

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);

	mouseX = 0;
	mouseY = 0;
    
    isTouchSent=false;
    
    isTouchYellow=false;
    isTouchBlue=false;
    isTouchGreen=false;
    
    isBallYellow=false;
    isBallBlue=false;
    isBallGreen=false;
    
    //ball
    ofBackground(255,255,255);
    ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
    
    counter =0;
    
    touchStartY=ofGetHeight()-10;
}

//--------------------------------------------------------------
void ofApp::update(){
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        // check for mouse moved message
        if(m.getAddress() == "/mouse/position"){
            // both the arguments are int32's
            mouseX = m.getArgAsInt32(0);
            mouseY = m.getArgAsInt32(1);
            isTouchSent =m.getArgAsBool(1);
        }
       //TRIANGLE
        //add new touch
        if(isTouchSent){
            TouchTriangle newTouch;
            newTouch.setup(mouseX,touchStartY);
            myTouches.push_back(newTouch);
            
        }
        
        //add newTouch update remove outside screen
        for(int i=0;i<myTouches.size();i++){
            myTouches[i].update();
            //TRAINGLE_COLOR
          
          //if(m.getArgType(1) == OFXOSC_TYPE_STRING){
            if(m.getArgAsString(1)=="Blue"){
                myTouches[i].TriangleColor.r=0;
                myTouches[i].TriangleColor.g=215;
                myTouches[i].TriangleColor.b=255;
                isTouchBlue=true;
            }
            
            if(m.getArgAsString(1)=="Yellow"){
                myTouches[i].TriangleColor.r=255;
                myTouches[i].TriangleColor.g=243;
                myTouches[i].TriangleColor.b=0;
                isTouchYellow=true;
                
            }
            
            if(m.getArgAsString(1)=="Green"){
                myTouches[i].TriangleColor.r=0;
                myTouches[i].TriangleColor.g=255;
                myTouches[i].TriangleColor.b=172;
                isTouchGreen=true;
                
             }
          // }
            
//            myTouches[i].TriangleColor.r=m.getArgAsInt32(2);
//            myTouches[i].TriangleColor.g=m.getArgAsInt32(3);
//            myTouches[i].TriangleColor.b=m.getArgAsInt32(4);
            
            //remove triangle outside screen
            if(myTouches[i].touchY<0){
                myTouches.erase(myTouches.begin()+i);
                i--;
            }
        }
            
        
    }
    //BALL
    //add newBall once a while
    if (ofGetFrameNum()%80==0)
    {
        Ball newBall;
        newBall.setup();
        myBalls.push_back(newBall);
    }
    
    //add newBall update
    for(int i=0;i<myBalls.size();i++){
        myBalls[i].update();
        //remove ball outsidescreen
        if(myBalls[i].y>ofGetHeight()){
            myBalls.erase(myBalls.begin()+i);
            //i--;
        }
        
        //COLLISION
        for(int k=0;k<myTouches.size();k++){
            float distance = ofDist(myTouches[k].touchPoint.x,myTouches[k].touchY,myBalls[i].x,myBalls[i].y);
            if(distance<myBalls[i].randomSize/2){
                //ERASE IF SAME COLOR
                //if((isTouchBlue && isBallBlue)||(isTouchYellow && isBallYellow)||(isTouchGreen && isBallGreen)){
                cout << "collision" << endl;
                myBalls.erase(myBalls.begin()+i);
                //}
                
            }
        }
        
    }
    
    //COLOR
    counter+=0.1;// the speed of color change
    
    
    counter+=0.1;// the speed of color change
    
    }

    


//--------------------------------------------------------------
void ofApp::draw(){

    //match the color = to see which r or g or b is 0
    
    //Ball Fall
    float Time               = sin( counter);
    float TimeMapped        = 0;
    
    ofSetColor(0, 250, TimeMapped);
    for(int i=0;i<myBalls.size();i++){
        //ball random color
        if((i%3)==0){
            TimeMapped=ofMap(Time, -1, 1, 150, 185);
            ofSetColor(0, 250, TimeMapped);
            myBalls[i].draw();
            isBallGreen =true;
        }
        if((i%3)==1){
            TimeMapped=ofMap(Time, -1, 1, 186, 220);
            ofSetColor(0, TimeMapped, 250);
            myBalls[i].draw();
            isBallBlue =true;
        }
        if((i%3)==2){
            TimeMapped=ofMap(Time, -1, 1, 221, 255);
            ofSetColor(TimeMapped, 250, 0);
            myBalls[i].draw();
            isBallYellow=true;
        }
        
    }
    
    for(int i=0;i<myTouches.size();i++){
        myTouches[i].draw();
    }


}

//--------------------------------------------------------------

void ofApp::keyPressed  (int key){
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

