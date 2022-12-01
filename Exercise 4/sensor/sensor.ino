int IRSensor = A0;
int LED = 13;

void setup(){
  pinMode(IRSensor, INPUT);
  pinMode(LED, OUTPUT);
}

void loop(){
  int sensorStatus = 255 - analogRead(IRSensor);
  if (sensorStatus >= 128)
  {
    digitalWrite(LED, LOW);
  }
  else  {
    digitalWrite(LED, HIGH);
  }
}