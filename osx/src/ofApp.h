#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#include "Ball.h"

#include "TouchTriangle.h"

// listen on port 12345
#define PORT 12345
#define NUM_MSG_STRINGS 20

class ofApp : public ofBaseApp {
	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    //receiver

		ofxOscReceiver receiver;


		float timers[NUM_MSG_STRINGS];

		int mouseX, mouseY;
    
        Boolean isTouchSent;
        Boolean isTouchYellow;
        Boolean isTouchBlue;
        Boolean isTouchGreen;
    
        Boolean isBallYellow;
        Boolean isBallBlue;
        Boolean isBallGreen;

    
    //beef
    vector <Ball> myBalls;
    vector <TouchTriangle> myTouches;
    
    float counter;
    //ofxOscReceiver receiver;
    
    float touchStartY;

    //COLOR
    ofColor bgColor;
    
};
