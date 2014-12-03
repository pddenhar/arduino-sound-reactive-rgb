Arduino Setup
-------------
Connect an RGB LED strip to your arduino following [these](http://learn.adafruit.com/rgb-led-strips/usage) instructions
and upload the ledStripSerialFade code to your Arduino. You may need to change REDPIN, BLUEPIN, and GREENPIN 
depending on how you connected it to your arduino. 

Processing Script
-----------------
This project relies on sound input from your computer, which is sent to the Arduino over its serial port. 
To run the project, open simpleColor in processing and change "String portName = Serial.list()[0];" 
to match your system's serial port configuration. If you have a microphone connected (a webcam or other 
active audio device), you should now have sound reactive lighting on your RGB strip.
