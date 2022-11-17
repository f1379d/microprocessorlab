unsigned long pre = 0;
int state = LOW;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  unsigned long current = millis();
  if ((current - pre) >= 500){
    pre = current;
    state = state == LOW? HIGH : LOW;
  }
  digitalWrite(13, state);   
}
 