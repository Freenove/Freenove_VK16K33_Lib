#include "Emotion.h"

void setup() {
  Emotion_Setup();      //Initializes the Led Matrix
  Emotion_SetMode(8);   //Set the emotion show mode：0-Display off,1-Turn the eyes,2-cry eyes,3-smile,4-right-wheel,5-left-wheel,6-blink,7-rand static emotion,8-set static emotion
}

void loop() {
  Emotion_Show();    //Display
}
