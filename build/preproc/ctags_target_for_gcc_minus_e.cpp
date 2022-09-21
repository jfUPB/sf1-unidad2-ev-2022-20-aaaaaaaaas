# 1 "/home/pop-os/Interactivos/Unidad2/sf1-unidad2-ev-2022-20-aaaaaaaaas/sf1-unidad2-ev-2022-20-aaaaaaaaas/Reto.ino"
# 2 "/home/pop-os/Interactivos/Unidad2/sf1-unidad2-ev-2022-20-aaaaaaaaas/sf1-unidad2-ev-2022-20-aaaaaaaaas/Reto.ino" 2


String ledState (uint8_t ledState){
  if(ledState == 0x1){
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
    pinMode(led1, 0x03);
    pinMode(led2, 0x03);
    pinMode(led3, 0x03);

    pinMode(button1Pin, 0x05);
    pinMode(button2Pin, 0x05);
    pinMode(button3Pin, 0x05);
    pinMode(button4Pin, 0x05);
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
        digitalWrite(led1, 0x1);
      }
      else if (command == "led1OFF")
      {
        digitalWrite(led1, 0x0);
      }
      else if (command == "led2ON")
      {
        digitalWrite(led2, 0x1);
      }
      else if (command == "led2OFF")
      {
        digitalWrite(led2, 0x0);
      }
       else if (command == "led3ON")
      {
        digitalWrite(led3, 0x1);
      }
      else if (command == "led3OFF")
      {
        digitalWrite(led3, 0x0);
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
