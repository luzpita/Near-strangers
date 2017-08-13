#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8); // Resitencia de 1M entre pines 4 y 8. Pin 8 es sensorTacto 
//1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
  cs_4_8.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
  pinMode(6,OUTPUT); // Pin 6 (pwm) es LED

}

void loop()                    
{
  long sensorTacto =  cs_4_8.capacitiveSensor(50);
  long valLED = 0;

  valLED = map(sensorTacto, 160, 4000, 0 , 255);
  //delay(100);

  if (sensorTacto > 160){
    analogWrite(6,valLED); 

  }
  else{
    analogWrite(6,0); 
  }

  Serial.print(sensorTacto);  // imprime sensorTacto  
  // print sensor output 
  Serial.print("||");

  Serial.println(valLED); // imprime valLED  
  // print valLED  

}


