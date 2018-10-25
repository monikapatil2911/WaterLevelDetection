//#include <NewPing.h>
#define TRIGGER_PIN  11 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     12 // Arduino pin tied to echo pin on the ultrasonic sensor.
//#define MAX_DISTANCE 30
int led=13;

//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup(){
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(led, OUTPUT);
}

void loop(){
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(0);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance=(duration/2)/29.1;
//  unsigned int distance= sonar.ping_cm();

if(distance<=25)
{
  Serial.print(distance);
  Serial.print("cm");

  digitalWrite(led, LOW);
}
else
{
digitalWrite(led, HIGH);
}
delay(200);
}
