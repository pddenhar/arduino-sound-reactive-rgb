/*
Peter Den Hartog - 2013

Arduino code that will accept a value from 1 to 768 over the serial port and set an RGB LED strip's 
PWM value accordingly. If no values are being received, it fades randomly.
*/
 
#define REDPIN 5
#define GREENPIN 3
#define BLUEPIN 6

#define FADESPEED 7     // make this higher to slow down
int currColor = 0;
int gotColor = 0; //seconds since we got a color
float brightness = .5;
void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(10);
}
 
 
void loop() {
  int color = 0;

  if (Serial.available()) {
    brightness = .5;
    color = Serial.parseInt();
    
    int difference = (color - currColor)/(float)FADESPEED;
    currColor += difference;
    writeColor(currColor);
    gotColor = (int)(millis() / 1000);
  } else if ((int)(millis() / 1000) - gotColor > 5) { //fade if we haven't gotten a color for a while
    brightness= .1;
    color = random(0, 765);
    int steps = abs(currColor - color) / 2;
    for(int i = 0 ; i < steps; i +=1) { 
      writeColor(currColor - i*((float)(currColor - color)/ steps));       
      delay(40);                            
    } 
    currColor = color;
  }
}
void writeColor(int color) {
  int r, g, b;

  if(color < 765){
    b=-1*pow((color-210.1)/13,2) + 255;
    g=-1*pow((color-496.1)/15,2) + 255;
    r=(-1*pow((color-765.1)/15,2) + 255);
    //Serial.println(b, DEC);
    if(r<0)
      r=0;
    if(g<0)
      g=0;
    if(b<0)
      b=0;
  } else {
    r = 255;
    g=0;
    b=0;
  }
    
  r*=(brightness + .4);
  g*=brightness;
  b*=brightness;
  g+=.3*r;

  analogWrite(BLUEPIN, b);
  analogWrite(REDPIN, r);
  analogWrite(GREENPIN, g);

}
