/*
 Parking Lot by Semir Sakanovic 
*/

#define echoPin1 9
#define echoPin2 8
#define trigPin1 7
#define trigPin2 6


void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  int duration1, distance1;
  int duration2, distance2;
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(500);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
  if (distance1 <=10){
    Serial.println("Busy");
    
  }
  else {
    Serial.println("Free");
    
  }
  delay(500);
 
}
