#include "Arduino.h"

void myIntCallback(int cnt)
{
  for (int i = 0; i < cnt; i++)
  {
    digitalWriteFast(LED_BUILTIN, HIGH);
    delay(50);
    digitalWriteFast(LED_BUILTIN, LOW);
    delay(500);
  }
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  //button1.attachClick(myIntCallback);
  button1.attachClick([] { myIntCallback(18); });
  //button2.attachClick([] { myIntCallback(someInt); });
}

void loop()
{
  // keep watching the push button:
  button1.tick();
 // button2.tick();

  // You can implement other code in here or just wait a while
  delay(10);
  //myIntCallback();
} // loop
