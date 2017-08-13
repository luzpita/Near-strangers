#include <CapacitiveSensor.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6 //pin de tira
#define NUMPIXELS      27 // n´mero de LEDs
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8); // Resitencia de 1M entre pines 4 y 8. Pin 8 es sensorTacto 
//1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
  cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
  pixels.begin(); // This initializes the NeoPixel library.

}

void loop()                    
{
  long sensorTacto =  cs_4_8.capacitiveSensor(50);
  long valLED = 0;

  valLED = map(sensorTacto, 160, 4000, 0 , 255);
  //delay(100);

  if (sensorTacto > 160){
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(valLED,valLED,valLED)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    //delay(delayval); // Delay for a period of time (in milliseconds).
  }
}

  else{
    for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    //delay(delayval); // Delay for a period of time (in milliseconds).

  }
} 
  

  Serial.print(sensorTacto);  // imprime sensorTacto  
  // print sensor output 
  Serial.print("||");

  Serial.println(valLED); // imprime valLED  
  // print valLED  

}


