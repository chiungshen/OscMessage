#pragma once

#include "ofApp.h"

class Ball{
public:
    
    void setup(){
        y=0;
        x=ofRandom(60,(ofGetWidth()-60));
        vSpeed=ofRandom(1,5);
        //Gameover=false; //stop loop
        
    }
    void update(){
        y+=vSpeed;
        /*
         if (y>ofGetHeight())
         {
         Gameover=!Gameover;
         }
         */
        
    }
    
    
    void draw(){
        //ofPushMatrix();
        
        ofDrawEllipse(x,y, randomSize, randomSize);
        //ofPopMatrix();
        
    }
    
    
    
    float randomSize=ofRandom(60, 120);
    float y;
    float x;
    float vSpeed;
    //Boolean Gameover;
    
};//class have to  be with semicolon

