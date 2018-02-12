/*
 * created by cw coleman
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin 9
        Echo: Echo (OUTPUT) - Pin 10
        GND: GND
 */
 
int trigPin = 10;    //Trig - green Jumper
int echoPin = 11;    //Echo - yellow Jumper
long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
    pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}
 int loop0 = 0;
 int c = 255;
    int d = 10;
void loop()
{
    d = 10; c = 127;
    if (loop0 == 0){
     fade(3,0,5,d,c);
     fade(5,0,5,d,c);
     fade(6,0,5,d,c);
     fade(9,0,5,d,c);
     loop0 = 1;
    }
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  
  Serial.println(cm);
// Serial.print("cm");
 // Serial.println();
   d = 2; c = 255;
  if (cm > 0 && cm < 30){Serial.println("* * * 3");fade(3,0,5,d,c);   }
   if (cm > 30 && cm < 60){Serial.println("* * * * * 5");fade(5,0,5,d,c);}
    if (cm > 60 && cm < 90){Serial.println("* * * * * * 6");fade(6,0,5,d,c); }
     if (cm > 90 && cm < 120){Serial.println("* * * * * * * * * 9");fade(9,0,5,d,c); }
  
  delay(25);
  
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

