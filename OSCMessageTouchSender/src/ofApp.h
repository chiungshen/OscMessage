#pragma once

#include "ofxiOS.h"
#include "ofxOsc.h"

#include "TouchTriangle.h"

#define HOST "169.254.198.230"

//#define HOST "localhost"
#define PORT 12345

class ofApp : public ofxiOSApp {

	public:
		void setup();
		void update();
		void draw();
		void exit();
		
		void touchDown(ofTouchEventArgs & touch);
		void touchMoved(ofTouchEventArgs & touch);
		void touchUp(ofTouchEventArgs & touch);
		void touchDoubleTap(ofTouchEventArgs & touch);
		void touchCancelled(ofTouchEventArgs & touch);

		void lostFocus();
		void gotFocus();
		void gotMemoryWarning();
		void deviceOrientationChanged(int newOrientation);

    ofxOscSender sender;
    Boolean isTouchSent;

    vector<TouchTriangle> myTouches;
    TouchTriangle newTouch;
    
    ofColor blue;
    ofColor yellow;
    ofColor green;
    ofColor bgColor;
    
    int touchCount;
    
    
    
    
    
};

