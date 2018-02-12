/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/


int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
    int c = 255;
    int d = 2;
     fade(3,0,5,d,c);
     fade(5,0,5,d,c);
     fade(6,0,5,d,c);
     fade(9,0,5,d,c);
}


void fade(int l, int b, int f, int d, int c){
// l (led), b(brightness), f(fade amount), d (delay), c(count)
int count = 0;
  while (count < c){
        analogWrite(l, b);
      
        // change the brightness for next time through the loop:
        b = b + f;
      
        // reverse the direction of the fading at the ends of the fade:
        if (b <= 0 || b  >= 255) {
          f  = -f ; // changes polarity (negative to postive or postive to negative)
        }
        // wait for 30 milliseconds to see the dimming effect
        delay(d);
        count++;
  }
      analogWrite(l, 0);
}
  
