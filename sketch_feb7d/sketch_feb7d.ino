
#include <FastLED.h>


#define NUM_LEDS 60

#define DATA_PIN 2 
#define BRIGHTNESS 30

CRGB leds[NUM_LEDS];
int dat = 0;
int times = (NUM_LEDS - (NUM_LEDS % 6)) / 6;
int choose = 3;
int middle = (NUM_LEDS - NUM_LEDS % 2) / 2; 
int limes = (middle - (middle % 6)) / 6;
int r = middle;
int k = middle;
void setup() { 
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB > (leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.setBrightness(BRIGHTNESS); 
  
}

void loop() { 
   // send data only when you receive data:
 
    // read the incoming byte:
    dat = Serial.read();

  
  Serial.println(dat + "TURN OFF LEDS"); 

   //Turn the LED on, then pauses, rainbow ripple effect

  if (dat == 65){
    int break_the_loop = 0;
    r = middle;
    for (int i = NUM_LEDS; i >= 0; i--){
      leds[i] = CRGB::Black;
      FastLED.show();
      
    }

    for (int i = middle; i >= 0; i--){
      leds[i] = CRGB::Red;
      FastLED.show();
      leds[r] = CRGB::Purple;

      delay(15);
      //leds[i] = CRGB::Black;
      FastLED.show();
      i--;
      r++;

      leds[i] = CRGB::Orange;
      leds[r] = CRGB::Blue;
      FastLED.show();
      delay(15);
      //leds[i] = CRGB::Black;
      FastLED.show();
      i--;
      r++;

      leds[i] = CRGB::Yellow;
      leds[r] = CRGB::Green;
      FastLED.show();
      delay(15);
      //leds[i] = CRGB::Black;
      FastLED.show();
      i--;
      r++;

      leds[i] = CRGB::Green;
      leds[r] = CRGB::Yellow;
      FastLED.show();
      delay(15);
      //leds[i] = CRGB::Black;
      FastLED.show();
      i--;
      r++;

      leds[i] = CRGB::Blue;
      leds[r] = CRGB::Orange;
      FastLED.show();
      delay(15);
      //leds[i] = CRGB::Black;
      FastLED.show();
      i--;
      r++;

      leds[i] = CRGB::Purple;
      leds[r] = CRGB::Red;
      FastLED.show();
      delay(15);
      r++;
      //leds[i] = CRGB::Black;
     // if break the loop is smaller than times then make everything black 
    if(break_the_loop <= limes * (choose - 1)){
      break_the_loop++;
      Serial.println(limes * (choose - 1));
       
        if(i <=  1){
          i = middle;
          r = middle ;
          k = middle ;
          for (int x = middle; x >= 0; x--){
              leds[x] = CRGB::Black;
              leds[k] = CRGB::Black;

              delay(15);
              FastLED.show();
              k++;
            } 
      }
   }
    
    }

    
}


  // green
  if (dat == 66){
    r = middle;
    for(int t = middle; t >= 0; t--){
      leds[t] = CRGB::Red;
      leds[r] = CRGB::Red;

      FastLED.show();
      r++;
    }
  }

  //red
   if (dat == 67){
    r = middle;
    for (int i = middle ; i >= 0; i--){
      leds[i] = CRGB::Green;
      leds[r] = CRGB::Green;

      FastLED.show();
      r++;
    }
  }
   if (dat == 68) {
    r = middle;
    for (int i = middle ; i >= 0; i--){
      leds[i] = CRGB::Blue;
      leds[r] = CRGB::Blue;

      FastLED.show();
      r++;
    }
  }

  if (dat == 69) {
    r = middle;
    for (int i = middle ; i >= 0; i--){
      leds[i] = CRGB::Black;
      leds[r] = CRGB::Black;

      FastLED.show();
      r++;
    }
  }

  


}

