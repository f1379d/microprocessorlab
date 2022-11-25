int motor_cw = 9;
int motor_ccw = 10;

void setup() {
  pinMode(motor_cw, OUTPUT);
  pinMode(motor_ccw, OUTPUT);
}

void loop() {

  // Speed up clockwise
  for(int val = 0; val <= 255; val +=1) {
    analogWrite(motor_cw, val);
    delay(5);
  }  

  // Speed down clockwise
  for(int val = 255; val >= 0; val -=1) {
    analogWrite(motor_cw, val);
    delay(5);
  } 

  // Speed up counter-clockwise

  for(int val = 0; val <= 255; val +=1) {
    analogWrite(motor_ccw, val);
    delay(5);
  } 

  // Speed down counter-clockwise
  for(int val = 255; val >= 0; val -=1) {
    analogWrite(motor_ccw, val);
    delay(5);
  } 
  
  delay(100);
  
}