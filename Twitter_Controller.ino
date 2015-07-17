/*
	* Author: Nicholas Bester
	* Title: Twitter Mention Test
	* Version: 0.1
*/

// Debuging variables
int const DEBUG = 1; // Test LED without Serial feedback

// LED control
int ledPin = A1;

// Value sent from Python
int signalState;

void setup() {
  // Transistor pin connection on board
  pinMode(ledPin, OUTPUT);

  // Enabling communication
  Serial.begin(9600);

  // Test breadboard setup to LED
  if (DEBUG) {
    tweetReceived();
  }
}

void loop() {
  if (!DEBUG) {
    if (Serial.available()) {
      byte receivedValue = Serial.read() - '0';
      signalState = receivedValue;

      if (signalState == 1) {
        tweetReceived();
      }

      else if (signalState == 0) {
        ledToggle(false);
      }
      
      Serial.flush();
    }
  }
}

// Flash the light when tweet is received
void tweetReceived() {
  for (int i = 0; i < 10; i++) {
    ledToggle(true);
    delay(100);
    ledToggle(false);
    delay(100);
  }
}

// turn LED on and off
void ledToggle(boolean value) {
  if (value) {
    analogWrite(ledPin, 1023);
  } else {
    analogWrite(ledPin, 0);
  }
}
