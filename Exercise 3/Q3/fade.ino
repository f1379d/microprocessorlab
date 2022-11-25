int ledPin = 11;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  // Fade in
  for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
    analogWrite(ledPin, ledVal);
    delay(20);
  }  

  // Fade out
  for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
    analogWrite(ledPin, ledVal);
    delay(20);
  } 
  
  delay(20);
  
}