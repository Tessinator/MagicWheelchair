//Wheelchair Main program

#include <Adafruit_NeoPixel.h>

//NEO PIXEL init
#define PIN            6    //NeoPixel input PIN
#define NUMPIXELS      16   //Number of NeoPixels on circle
#define BRIGHTNESS     10   //Brightness value (0-255)

//Setting up the pixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Setting up the button pins
int buttonin = 13;         // the number of the input pin
int buttonledpin = 12;   // the number of the output pin ACTIVE LOW
int ttrigger = 0;
int pixelpattern = 0;

int delayval = 100; // delay for LED spin

void setup() {
  pixels.begin(); // init NeoPixel library.

  //Init pins for buttons
  pinMode(buttonin, INPUT);
  pinMode(buttonledpin, OUTPUT);
}

void loop() {
  //Button Logic
   ttrigger = 0; // Clear trigger value
   
   do{
      delay(250);
      ttrigger += 250 ;
    
  }while(ttrigger < 1000 && digitalRead(buttonin));
  
  if (digitalRead(buttonin)) {

      digitalWrite(buttonledpin, HIGH);
      
      if(pixelpattern)
        pixelpattern = 0;
      else
        pixelpattern = 1;
        
      delay(25);
    
  }
  else {

      digitalWrite(buttonledpin, LOW);
      delay(25);
    
  }

  if(pixelpattern)
  {
    //Light animiation logic
     for(int i = 0; i < NUMPIXELS; i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(255,255,255)); //White color
      pixels.setBrightness(BRIGHTNESS); //Setting the brightness
  
      pixels.show(); // This sends the updated pixel color to the hardware.
  
      delay(delayval); 
    }
  
    //Turning the pixels off for the rotation
    for(int i = 0; i< NUMPIXELS; i++)
    {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(255,0,0)); //Red color
      pixels.setBrightness(BRIGHTNESS); //Setting the brightness
  
      pixels.show(); // This sends the updated pixel color to the hardware.
      delay(delayval); 
    }
  }
  else
  {
    //Light animiation logic
     for(int i = 0; i < NUMPIXELS; i++){
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(255,255,255)); //White color
      pixels.setBrightness(BRIGHTNESS); //Setting the brightness
  
      pixels.show(); // This sends the updated pixel color to the hardware.
  
      delay(delayval); 
  }
}
}
