#include "irqPin.hpp"

const byte ledPin = 13; //just for user interface
const byte interruptPin = 2; //external buttons to trigger ISR
const byte interruptPin2 = 3;

//volatile byte state = 0; //must be volatile, because this global changes in interrupt
//no fck global variables, use classes, not expose variables out of one file/class, as much as possible

irqPin *irqPin1 = new irqPin(interruptPin);
irqPin *irqPin2 = new irqPin(interruptPin2);

//state describes whether it is safe to run main loop
void setup() {
  pinMode(ledPin, OUTPUT);

  homing(); //real homing would take place here
  digitalWrite(ledPin, LOW); //just for user interface
  delay(1000); //just for user interface

  //attachInterrupt(digitalPinToInterrupt(interruptPin), changeState, RISING); //attach different interrupt pins to the same function
  //attachInterrupt(digitalPinToInterrupt(interruptPin2), changeState, RISING);
  //state = 1;
}

void loop() {
  while (true) { //while always
    if(!irqPin1->getState() || !irqPin2->getState())
    {
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      digitalWrite(ledPin, LOW);
    }
  }
}
/*
void changeState() { //change state if either triggers were hit
  state = 0;
}
*/
void homing() {
  while (!irqPin1->getState() && !irqPin1->getState())
  {
    digitalWrite(ledPin, HIGH);
  }
}
