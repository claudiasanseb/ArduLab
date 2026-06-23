#include "ArduLab.h"

ArduLab::ArduLab(char Mod, char Comms)
{
  // Basic Outputs
  pinMode(_buzzer, OUTPUT);
  pinMode(_red, OUTPUT);
  pinMode(_green, OUTPUT);
  pinMode(_blue, OUTPUT);

  // H-Bridge for motor
  pinMode(_motor_a_1, OUTPUT);
  pinMode(_motor_a_2, OUTPUT);
  pinMode(_motor_b_1, OUTPUT);
  pinMode(_motor_b_2, OUTPUT);

  // Basic Inputs
  pinMode(_pushbutton, INPUT);

  if (Mod == "ElectroLab"){
    _mod = 1;
  }
  else if (Mod == "BotMod"){
    _mod = 2;
  }
  else if (Mod == "DomoMod"){
    _mod = 3;
  }
  else if (Mod == "KineticMod"){
    _mod = 4;
  }

  if (Comms == "Wifi"){
    _comms = 1;
  }
  else if (Comms == "Bluetooth"){
    _comms = 2;
  }
  else if (Mod == "RF24"){
    _comms = 3;
  }
}
 
void ArduLab::Beep()
{
  digitalWrite(_buzzer, HIGH);
  delay(250);
  digitalWrite(_buzzer, LOW);
  delay(250);  
}

void ArduLab::Play(int frequency, int duration, int pause)
{
  tone(_buzzer, frequency, duration);
  delay(duration + pause); 
}

void ArduLab::RGB(int r, int g, int b)
{
	analogWrite(_red, r);
	analogWrite(_green, g);
	analogWrite(_blue, b);
}

boolean ArduLab::PushButton()
{
  return digitalRead(_pushbutton);
}

float ArduLab::Battery()
{
  return analogRead(_battery);
}

float ArduLab::Light()
{
  return analogRead(_ldr);
}

void ArduLab::MotorA(int dir)
{
  if (dir == 0){
    digitalWrite(_motor_a_1, LOW);
    digitalWrite(_motor_a_2, LOW);    
  }
  else if (dir == 1){
    digitalWrite(_motor_a_1, HIGH);
    digitalWrite(_motor_a_2, LOW);    
  }
  else if (dir == 2){
    digitalWrite(_motor_a_1, LOW);
    digitalWrite(_motor_a_2, HIGH);    
  }
}

void ArduLab::MotorB(int dir)
{
  if (dir == 0){
    digitalWrite(_motor_b_1, LOW);
    digitalWrite(_motor_b_2, LOW);    
  }
  else if (dir == 1){
    digitalWrite(_motor_b_1, HIGH);
    digitalWrite(_motor_b_2, LOW);    
  }
  else if (dir == 2){
    digitalWrite(_motor_b_1, LOW);
    digitalWrite(_motor_b_2, HIGH);    
  }
}