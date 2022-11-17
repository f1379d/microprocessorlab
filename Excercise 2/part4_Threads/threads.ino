#include <Thread.h>
#include <ThreadController.h>

ThreadController control=ThreadController();
Thread on=Thread();
Thread off=Thread();

void setup() {
  on.onRun(digitalWrite(LED_BUILT_IN,HIGH));
  on.setInterval(500);
  off.onRun(digitalWrite(LED_BUILT_IN,LOW););
  off.setInterval(500);

  control.add(&on);
  control.add(&off);
}

void loop() {
  control.run();
}
