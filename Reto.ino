#include <Arduino.h>


String ledState (uint8_t ledState){
  if(ledState == HIGH){
    return "0";
  }
  else return "1";
}

void task()
{
  enum class TaskStates
  {
    INIT,
    WAIT_COMMANDS
  };
  static TaskStates taskState = TaskStates::INIT;
  constexpr uint8_t led1 = 25;
  constexpr uint8_t led2 = 26;
  constexpr uint8_t led3 = 27;
  constexpr uint8_t button1Pin = 12;
  constexpr uint8_t button2Pin = 13;
  constexpr uint8_t button3Pin = 32;
  constexpr uint8_t button4Pin = 33;

  switch (taskState)
  {
  case TaskStates::INIT:
  {
    Serial.begin(115200);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);

    pinMode(button1Pin, INPUT_PULLUP);
    pinMode(button2Pin, INPUT_PULLUP);
    pinMode(button3Pin, INPUT_PULLUP);
    pinMode(button4Pin, INPUT_PULLUP);
    taskState = TaskStates::WAIT_COMMANDS;
    break;
  }
  case TaskStates::WAIT_COMMANDS:
  {
    if (Serial.available() > 0)
    {
      String command = Serial.readStringUntil('\n');
      if (command == "led1ON")
      {
        digitalWrite(led1, HIGH);
      }
      else if (command == "led1OFF")
      {
        digitalWrite(led1, LOW);
      }
      else if (command == "led2ON")
      {
        digitalWrite(led2, HIGH);
      }
      else if (command == "led2OFF")
      {
        digitalWrite(led2, LOW);
      }
       else if (command == "led3ON")
      {
        digitalWrite(led3, HIGH);
      }
      else if (command == "led3OFF")
      {
        digitalWrite(led3, LOW);
      }
      else if (command == "readBUTTONS")
      {


        Serial.print(ledState(digitalRead(button1Pin)).c_str());
        Serial.print('\n');
        Serial.print(ledState(digitalRead(button2Pin)).c_str());
        Serial.print('\n');
        Serial.print(ledState(digitalRead(button3Pin)).c_str());
        Serial.print('\n');
      }
    }
    break;
  }
  default:
  {
    break;
  }
  }
}
void setup()
{
  task();
}

void loop()
{
  task();
}