//Traffic light for Tram by Symorgh

//pin which triggers ultrasonic sound
const int pingPin = 6;
 
//pin which delivers time to receive echo using pulseIn()
int inPin = 8;

int Tram = 10;
 
//LED pin numbers
int greenled = 10; //Led's and pins
int yellowled = 11;
int redled = 12;
int sema1 = 3;
int sema2 = 13;
 
void setup() {
  // initialize serial communication
  Serial.begin(9600);
}
 
void loop()
{
  //raw duration in milliseconds, cm is the
  //converted amount into a distance
  long duration, cm;
 
  //initializing the pin states
  pinMode(pingPin, OUTPUT);
 pinMode(greenled, OUTPUT); //Pinmodes of the leds
pinMode(yellowled, OUTPUT);
pinMode(redled, OUTPUT);  
pinMode(sema1, OUTPUT);
pinMode(sema2, OUTPUT);
 
  //sending the signal, starting with LOW for a clean signal
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
 
  //setting up the input pin, and receiving the duration in
  //microseconds for the sound to bounce off the object infront
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);
 
  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
 
  //checking if anything is within the safezone, if not, keep
  //green LED on if safezone violated, activate red LED instead
  if (cm <= Tram)
  {
    digitalWrite(sema1, HIGH);
    digitalWrite(sema2, HIGH);
    digitalWrite(redled, HIGH);
    delay(5000);
    digitalWrite(redled, LOW);
    digitalWrite(sema1, LOW);
    digitalWrite(sema2, LOW);
}
  else
  {
  digitalWrite(greenled, HIGH); //Green on for 5 seconds
  digitalWrite(yellowled, HIGH);
  delay(1000);
  digitalWrite(greenled, LOW); //Green off, yellow on for 2 seconds
  digitalWrite(yellowled, LOW);
  delay(200);
  digitalWrite(redled, HIGH);
  digitalWrite(sema2, HIGH);
  delay(1000);
  digitalWrite(redled, LOW);
  digitalWrite(sema2, LOW);
  delay(200);

   
    
  }
 
  
}
 
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
