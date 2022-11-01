
int trigPin = 9;      // Trig pin of HC-SR04
int echoPin = 10;     // Echo pin of HC-SR04

int revleft4 = 4;       //Initializing pins for motors
int fwdleft5 = 5;
int revright6 = 6;
int fwdright7 = 7;

int rightlight = 12;          //Initialising pin for right led
int leftlight1 = 13;
int leftlight2 = 3;

int lorr = 1;                 //Intialising the left or right variable.



long duration, distance;      //Intializing distance and duration as long instead of integer for longer data

void setup() {

  delay(random(500, 2000));       // delay for random time
  Serial.begin(9600);
  pinMode(revleft4, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft5, OUTPUT);
  pinMode(revright6, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  
  pinMode(rightlight, OUTPUT);
  pinMode(leftlight1, OUTPUT);
  pinMode(leftlight2, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);        // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);  // receive reflected waves
  distance = duration / 58.2;         // convert to distance
  delay(10);

  lorr = random(1, 3);

  if (lorr == 1)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);        // send waves for 10 us
    delayMicroseconds(10);
    duration = pulseIn(echoPin, HIGH);  // receive reflected waves
    distance = duration / 58.2;         // convert to distance
    delay(10);
    if (distance > 19)
    {
      digitalWrite(fwdright7, HIGH);                    //Move forward
      digitalWrite(revright6, LOW);
      digitalWrite(fwdleft5, HIGH);
      digitalWrite(revleft4, LOW);

      digitalWrite(rightlight, LOW);                  //Light turned off
      digitalWrite(leftlight1, LOW);
      digitalWrite(leftlight2, LOW);
    }
    while (distance < 18)
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);        // send waves for 10 us
      delayMicroseconds(10);
      duration = pulseIn(echoPin, HIGH);  // receive reflected waves
      distance = duration / 58.2;         // convert to distance
      delay(10);

      digitalWrite(fwdright7, LOW);   //Stop
      digitalWrite(revright6, LOW);
      digitalWrite(fwdleft5, LOW);
      digitalWrite(revleft4, LOW);
      delay(500);

      digitalWrite(fwdright7, LOW);   //Move backwards
      digitalWrite(revright6, HIGH);
      digitalWrite(fwdleft5, LOW);
      digitalWrite(revleft4, HIGH);
      delay(500);

      digitalWrite(fwdright7, LOW);   //Stop
      digitalWrite(revright6, LOW);
      digitalWrite(fwdleft5, LOW);
      digitalWrite(revleft4, LOW);
      delay(100);

      digitalWrite(fwdright7, HIGH);  //Turn right
      digitalWrite(revright6, LOW);
      digitalWrite(revleft4, LOW);
      digitalWrite(fwdleft5, LOW);

      digitalWrite(rightlight, HIGH);   // Led for turning right turns on

      delay(500);
    }
  }

  if (lorr == 2)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);        // send waves for 10 us
    delayMicroseconds(10);
    duration = pulseIn(echoPin, HIGH);  // receive reflected waves
    distance = duration / 58.2;         // convert to distance
    delay(10);
    if (distance > 19)
    {
      digitalWrite(fwdright7, HIGH);                    //Move forward
      digitalWrite(revright6, LOW);
      digitalWrite(fwdleft5, HIGH);
      digitalWrite(revleft4, LOW);

      digitalWrite(rightlight, LOW);                  //Light turned off
      digitalWrite(leftlight1, LOW);                 
      digitalWrite(leftlight2, LOW);
    }
    while (distance < 18)
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);        // send waves for 10 us
      delayMicroseconds(10);
      duration = pulseIn(echoPin, HIGH);  // receive reflected waves
      distance = duration / 58.2;         // convert to distance
      delay(10);

      digitalWrite(fwdright7, LOW);   //Stop
      digitalWrite(revright6, LOW);
      digitalWrite(fwdleft5, LOW);
      digitalWrite(revleft4, LOW);
      delay(500);

      digitalWrite(fwdright7, LOW);   //Move backwards
      digitalWrite(revright6, HIGH);
      digitalWrite(fwdleft5, LOW);
      digitalWrite(revleft4, HIGH);
      delay(500);

      digitalWrite(fwdright7, LOW);   //Stop
      digitalWrite(revright6, LOW);
      digitalWrite(fwdleft5, LOW);
      digitalWrite(revleft4, LOW);
      delay(100);

      digitalWrite(fwdright7, LOW);  //Turn left
      digitalWrite(revright6, LOW);
      digitalWrite(revleft4, LOW);
      digitalWrite(fwdleft5, HIGH);

      digitalWrite(leftlight1, HIGH);   // Led for turning left turns on

      delay(500);
    }
  }
}

