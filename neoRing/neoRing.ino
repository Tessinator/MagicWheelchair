// This is a modified version of the NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
// It was created for students at Divine Child High School

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
// The rings we have have 12 NeoPixels
#define NUMPIXELS      16

//brightness macro
#define BRIGHTNESS     10

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // delay for half a second

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i = 0; i < NUMPIXELS; i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255,255,255));
    pixels.setBrightness(BRIGHTNESS); 

    pixels.show(); 
    // This sends the updated pixel color to the hardware.

    delay(delayval); 
    // Delay for a period of time (in milliseconds).
  }

  //Turning the pixels off for the rotation
  for(int i = 0; i< NUMPIXELS; i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255,0,0));
    pixels.setBrightness(BRIGHTNESS); 

    pixels.show(); 
    // This sends the updated pixel color to the hardware.

    delay(delayval); 
    // Delay for a period of time (in milliseconds).
  }
  
 }