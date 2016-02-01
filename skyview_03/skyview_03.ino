
// Teensy 3.2 to ESP8266 to PC USB Serial
// ESP8266 TX -> Teensy Pin 0
// ESP8266 RX -> Teensy Pin 1

// LED 13 - Send LED indicator
long LED_13_TimeOn = 0;

void setup() {

  pinMode(13, OUTPUT);  // YELLOW LED - SENDING
  
  // Setup computer to Teensy serial
  Serial.begin(9600);

  // Setup Teensy to ESP8266 serial
  // Use baud rate 115200 during firmware update
  Serial1.begin(9600);

}

void loop() {
  int c;
  // Send bytes from ESP8266 -> Teensy to Computer
  if ( Serial1.available() ) {
    digitalWriteFast(13, HIGH);   // set the LED on
    LED_13_TimeOn = millis();
    c = Serial1.read();
    Serial.write(c);
  }

  // Send bytes from Computer -> Teensy back to ESP8266
  if ( Serial.available() ) {
    //        digitalWriteFast(15, HIGH);   // set the LED on
    //        LED_15_TimeOn = millis();
    c = Serial.read() ;
    Serial1.write(c);
  }

  if (millis() - LED_13_TimeOn > 20) {
    digitalWriteFast(13, LOW);   // set the LED off
  }
}

