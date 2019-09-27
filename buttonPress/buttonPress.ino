/* switch
 * 
 * Each time the input pin goes from LOW to HIGH (e.g. because of a push-button
 * press), the output pin is toggled from LOW to HIGH or HIGH to LOW.  There's
 * a minimum delay between toggles to debounce the circuit (i.e. to ignore
 * noise).  
 *
 * David A. Mellis
 * 21 November 2006
 */

int inPin = 13;         // the number of the input pin
int outPin = 12;       // the number of the output pin
int buttonledpin = 8;

int ttrigger = 0;

void setup()
{
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
  pinMode(buttonledpin, OUTPUT);
}

void loop()
{
  ttrigger = 0;

  do{
      delay(250);
      ttrigger += 250 ;
    
  }while(ttrigger < 1000 && digitalRead(inPin));
  
  if (digitalRead(inPin)) {

      digitalWrite(buttonledpin, HIGH);
      digitalWrite(outPin, HIGH);
      delay(25);
    
  }
  else {

      digitalWrite(buttonledpin, LOW);
      digitalWrite(outPin, LOW);
      delay(25);
    
  }

}
