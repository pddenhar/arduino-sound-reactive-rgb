Connect an RGB LED strip to your arduino following these (http://learn.adafruit.com/rgb-led-strips/usage) instructions
and upload the ledStripSerialFade code. You may need to change REDPIN, BLUEPIN, and GREENPIN depending on 
how you connected it to your arduino. 

To run the project, open simpleColor in processing and change "String portName = Serial.list()[0];" to match your system.
If you have a microphone connected, you should now have sound reactive lighting on your RGB strip.