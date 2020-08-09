#pragma once //to avoid multiple includes
#include <Arduino.h>
class irqPin
  {
    private:
    bool state;
    void changeState()
    {
      state = !state;
    }
    public:
    irqPin(int pinNum)
    {
      state = digitalRead(pinNum);
      pinMode(pinNum, INPUT_PULLUP);
      //attachInterrupt(digitalPinToInterrupt(pinNum), changeState, RISING); //this will cause problem that getState not static
      attachInterrupt(digitalPinToInterrupt(pinNum), (void *)&changeState, RISING);
    }
    ~irqPin(){}
    bool getState() {return state;}
  };
