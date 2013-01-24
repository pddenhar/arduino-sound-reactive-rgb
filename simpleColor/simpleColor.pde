/*
Peter Den Hartog - 2013

*/

import ddf.minim.*;
import ddf.minim.signals.*;
 
Minim minim;

import processing.serial.*;

AudioInput in;


Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port
int lastSecond;

void setup() 
{
  minim = new Minim(this);

  //size(765, 200);

  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  in = minim.getLineIn(Minim.MONO,512); 
  lastSecond = second();
}

void draw() {
  //background(255);
  float r = (15000*in.mix.level());
  //println(r);
  int colorc = (int)r;
  int secondN = second();
  if(lastSecond != secondN){
    //colorc+=800;
    lastSecond=secondN;
  }
  myPort.write(Integer.toString(colorc));
  //if((mouseX >= 0) && (mouseX <= 765))
    //myPort.write(Integer.toString(mouseX));
  delay(15);
}

