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
 * Buttons on remote: D10, 11, 12, A0, A2 (default is 1, 0 = pressed)
 ***********************************************/

#include <multiCameraIrControl.h>

#define irLED 9 
#define statusLED 13
#define pushBUTTON1 10
#define pushBUTTON2 11
#define pushBUTTON3 12
#define rotary1 14
#define rotary2 16
#define buzzerPIN 8
#define interVAL 3

Canon D5(irLED);

void setup(){
  
  pinMode(statusLED, OUTPUT);
  pinMode(pushBUTTON1, INPUT);
  pinMode(pushBUTTON2, INPUT);
  pinMode(pushBUTTON3, INPUT);
  pinMode(rotary1, INPUT);//A0
  pinMode(rotary2, INPUT);//A2
  digitalWrite(pushBUTTON1, HIGH);
  digitalWrite(pushBUTTON2, HIGH);
  digitalWrite(pushBUTTON3, HIGH);
  digitalWrite(rotary1, HIGH);//A0
  digitalWrite(rotary2, HIGH);//A2
  
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
    delay(800);      
    beep();
    delay(800);      
    beepFinal();
  }
  if (digitalRead(pushBUTTON3) == LOW) {
    int delays[] = {5, 10, 15};
    beep();
    for (int i = 0; i < delays[mode()]-2; i++){
      delay(800);
      beep();
    }
    beepFinal();
    D5.shutterNow();
    delay(250);
  }
  
}

void beep(){
  tone(buzzerPIN, 262,200); //C4 for 200ms
}

void beepFinal(){
  tone(buzzerPIN, 600,1000); //C4 for 200ms
}

int mode(){
  //0, 1 and 2
  if(digitalRead(rotary1) == LOW) return 0;
  if(digitalRead(rotary2) == LOW) return 1;
  return 2;
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



