
/*
  Getting Started example sketch for nRF24L01+ radios
  This is a very basic example of how to send data from one node to another
  Updated: Dec 2014 by TMRh20
*/

#include <SPI.h>
#include "RF24.h"
unsigned long test;

/****************** User Config ***************************/
/***      Set this radio as radio number 0 or 1         ***/
bool radioNumber = 0;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(9, 10);
/**********************************************************/

byte addresses[][6] = {"1Node", "2Node"};

// Used to control whether this node is sending or receiving
bool role = 0;

void setup() {
  Serial.begin(115200);
  Serial.println(F("RF24/examples/GettingStarted"));

  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
  // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);


  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);


// Start the radio listening for data
radio.startListening();
}

void loop() {




  

  if ( radio.available()) {
    // Variable for the received timestamp
    while (radio.available()) {                                   // While there is data ready
      radio.read( &test, sizeof(unsigned long) );             // Get the payload
    }

    Serial.print(F("Received "));
    Serial.println(test);
  }
}

