
#include <Mouse.h>
int pages = 3; //The number of pages that will be flipped
int swipeLength = 9;//this might change, depending on the device.
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Mouse.end(); //give myself a chance to upload a sketch
  delay(20000);
  Mouse.begin();
  Mouse.click();
  delay(500);
  for (int i = 0; i < swipeLength; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    Mouse.press();
    Mouse.move(-swipeLength, 0, 0);
    delay(10);
  }
  delay(500);
}
void loop() {
  for (int i = 0; i < pages; i++) {
    for (int i = 0; i < swipeLength; i++) {
      digitalWrite(LED_BUILTIN, HIGH);
      Mouse.press();
      Mouse.move(-10, 0, 0);
      delay(10);
    }
    delay(100);
    Mouse.release();
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    for (int i = 0; i < swipeLength; i++) {
      Mouse.move(10, 0, 0);
      delay(10);
    }
  }
  for (int i = 0; i < swipeLength; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    Mouse.move(-10, 0, 0);
    delay(10);
  }
  for (int i = 0; i < pages; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    Mouse.press();
    for (int i = 0; i < swipeLength; i++) {
      Mouse.move(10, 0, 0);
      delay(10);
    }
    delay(100);
    Mouse.release();
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
    for (int i = 0; i < swipeLength; i++) {
      Mouse.move(-10, 0, 0);
      delay(10);
    }
  }
  for (int i = 0; i < swipeLength; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    Mouse.move(10, 0, 0);
    delay(10);
  }
}




