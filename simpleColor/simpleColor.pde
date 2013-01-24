/*
Peter Den Hartog - 2013

A simple program that listens to an attached microphone 
and outputs a linear value to the serial port. Meant to be 
paired with 
*/

import ddf.minim.*;
import ddf.minim.signals.*;
 
Minim minim;

import processing.serial.*;

AudioInput in;


Serial myPort;  // Create object from Serial class
int val;        // Data received from the serial port

void setup() 
{
  minim = new Minim(this);

  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  in = minim.getLineIn(Minim.MONO,512); 
}

void draw() {
  float r = (15000*in.mix.level());
  //println(r);
  int colorc = (int)r;
  myPort.write(Integer.toString(colorc));
  delay(15);
}

