// Traffic Jam & Smart Parking by Symorgh

#define echoPin 8            
#define initPin 6            
#define echoPin1 9
#define trigPin1 7

unsigned long pulseTime = 0;  // variable for reading the pulse
int counter = 0;
int duration1, distance1;
void setup() {
  // make the init pin an output:
  pinMode(initPin, OUTPUT);
  // make the echo pin an input:
  pinMode(echoPin, INPUT);
  // initialize the serial port:
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // send the sensor a 10microsecond pulse:
  
  digitalWrite(initPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(initPin, LOW);
  
  
  

  // wait for the pulse to return.

  
 
    
    pulseTime = pulseIn(echoPin, HIGH);
    if(pulseTime<=1000){
      counter++;
    }else{
      counter = 0;
    }
    
    
    if( counter && counter %50==0){
      
      
      Serial.println("Jam");
    }
    
    delay(100);
    
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
  if (distance1 <=10){
    Serial.println("Busy");
    
  }
  else {
    Serial.println("Free");
    
  }
}
