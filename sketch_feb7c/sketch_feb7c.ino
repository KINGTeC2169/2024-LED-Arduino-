
#include <FastLED.h>


#define NUM_LEDS 100

#define DATA_PIN 2 
#define BRIGHTNESS 35

CRGB leds[NUM_LEDS];
int dat = 0;
int times = (NUM_LEDS - (NUM_LEDS % 6)) / 6;
int choose = 3;
void setup() { 
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB > (leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.setBrightness(BRIGHTNESS); 
  
}

void loop() { 
   // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    dat = Serial.read();

  }
  Serial.println(dat); 

   //Turn the LED on, then pauses, rainbow ripple effect

  if (dat == 65){
    int break_the_loop = 0;
    
    for (int i = NUM_LEDS - 1; i >= 0; i--){
      leds[i] = CRGB::Black;
      FastLED.show();
    }

    for (int i = NUM_LEDS - 1; i >= 0; i--){
      leds[i] = CRGB::Red;
      FastLED.show();
      delay(50);
      //leds[i] = CRGB::Black;
      FastLED.show();
      i--;

      leds[i] = CRGB::Orange;
      FastLED.show();
      delay(50);
      //leds[i] = CRGB::Black;
      FastLED.show();
      i--;

      leds[i] = CRGB::Yellow;
      FastLED.show();
      delay(50);
      //leds[i] = CRGB::Black;
      FastLED.show();
      i--;

      leds[i] = CRGB::Green;
      FastLED.show();
      delay(50);
      //leds[i] = CRGB::Black;
      FastLED.show();
      i--;

      leds[i] = CRGB::Blue;
      FastLED.show();
      delay(50);
      //leds[i] = CRGB::Black;
      FastLED.show();
      i--;

      leds[i] = CRGB::Purple;
      FastLED.show();
      delay(50);
      //leds[i] = CRGB::Black;
     // if break the loop is smaller than times then make everything black 
    if(break_the_loop <= times * choose - 2){
      break_the_loop++;
      Serial.println(break_the_loop);
      
        if(i <=  0){
          i = NUM_LEDS;
          for (int x = NUM_LEDS - 1; x >= 0; x--){
              leds[x] = CRGB::Black;
              delay(50);
              FastLED.show();
            } 
      }
   }
    
    }

    
}


  // green
  if (dat == 66){
    for(int t = NUM_LEDS - 1; t >= 0; t--){
      leds[t] = CRGB::Red;
      FastLED.show();
    }
  }

  //red
   if (dat == 67){
    for (int i = NUM_LEDS - 1; i >= 0; i--){
      leds[i] = CRGB::Green;
      FastLED.show();
    }
  }
  if (dat == 68) {
    for (int i = NUM_LEDS - 1; i >= 0; i--){
      leds[i] = CRGB::Black;
      FastLED.show();
    }
  }
 

}

