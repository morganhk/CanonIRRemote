/**********************************************
 * Arduino Code controlling the events created by button presses and generating IR blasts
 *    for use with Canon Cameras
 *
 * Author: Morgan Aasdam
 * Contact: http://morgan.hk
 * Creation date: 2012-03-10
 * Platform/Language: Arduino 1.0
 * License: Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
 * License info: http://creativecommons.org/licenses/by-nc-sa/3.0/
 * 
 * External Libraries:
 *    - multiCameraIrControl (by Sebastian Setz)
 *      	http://sebastian.setz.name/arduino/my-libraries/multi-camera-ir-control/
 *          Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
 *
 ***********************************************/

#include <multiCameraIrControl.h>

#define irLED 9 
#define statusLED 13
#define pushBUTTON1 12
#define pushBUTTON2 11
#define buzzerPIN 8
#define interVAL 3

Canon D5(irLED);

void setup(){
  
  pinMode(statusLED, OUTPUT);
  pinMode(pushBUTTON1, INPUT);
  pinMode(pushBUTTON2, INPUT);
  digitalWrite(pushBUTTON1, HIGH);
  digitalWrite(pushBUTTON2, HIGH);
}

void loop(){
  if (digitalRead(pushBUTTON1) == LOW) {
    digitalWrite(statusLED, HIGH);
    D5.shutterNow();
    beep();
    delay(250);
    digitalWrite(statusLED, LOW);
  }
  if (digitalRead(pushBUTTON2) == LOW) {
    D5.shutterDelayed();      
    beep();
    delay(1000);      
    beep();
    delay(1000);      
    beep();
    delay(1000);
  }
  
}

void beep(){
  tone(buzzerPIN, 262,200); //C4 for 200ms
}

void shootNow(){
    digitalWrite(statusLED, HIGH); //Timelapse active
    D5.shutterNow();
    beep();
    delay(250);
    digitalWrite(statusLED, LOW);
}

void shootDelayRec(){
    D5.shutterDelayed();      
    beep();
    delay(1000);      
    beep();
    delay(1000);      
    beep();
    delay(1000);
}



