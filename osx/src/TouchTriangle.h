#pragma once

#include "ofApp.h"

class TouchTriangle{
public:
    
    void setup(float x, float y){
        touchY=ofGetHeight()-10;
        touchVSpeed=50;
        touchPointD=5;
        
        touchPoint.x=x;
        touchY=y;
        rotationSpeed=ofRandomf();
        rotationAngle=0;
        
//        //DEFALT COLOR = B
//        TriangleColor.r=0;
//        TriangleColor.g=0;
//        TriangleColor.b=0;
        
        
    }
    void update(){
        touchY-=touchVSpeed;
        rotationAngle+=rotationSpeed;
        
    }
    
    
    void draw(){
        ofPushMatrix();
        ofTranslate(touchPoint.x,0);
        ofRotateZ(rotationAngle);
        ofSetColor(TriangleColor.r,TriangleColor.g ,TriangleColor.b);
        ofDrawTriangle(10,touchY, 10-touchPointD,touchY+touchPointD,10+touchPointD, touchY+touchPointD);
        ofPopMatrix();
        
    }
    
    
    
    float touchY;
    float touchVSpeed;
    float touchPointD;
    
    ofPoint touchPoint;//this is local
    float rotationAngle;
    float rotationSpeed;
    
    ofColor TriangleColor;
    
};//class have to  be with semicolon

