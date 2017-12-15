#pragma once
#include "ofxiOS.h"

class TouchTriangle{
public:
    
    void setup(ofPoint myPoint){
        touchPoint=myPoint;
        touchPointD=20;
        
    }
    void update(){
        //touchY+=touchVSpeed;
        
        
        
    }
    
    void draw(){
        ofPushMatrix();
        ofTranslate(touchPoint);
        ofDrawTriangle(10,10, 10-touchPointD,10+touchPointD*1.5,10+touchPointD, 10+touchPointD*1.5);
        ofPopMatrix();
        
    }
    
    //float touchVSpeed;
    float touchPointD;
    
    ofPoint touchPoint;//this is local

};//class have to  be with semicolon
