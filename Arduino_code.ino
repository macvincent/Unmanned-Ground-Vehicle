/********************************************************************** 
 *  The aim of this simulation is to show how to control two motors' direction using a H-bridge 
 *  it is proudly designed by Agha-Oko MacVincent 
 *  EEE 100 level FUTO
 **********************************************************************/
 //Here we declare and initialise the control pins for the l923D IC
  const int motor1a = 3;
  const int motor1b = 2;
  const int motor2a = 4;
  const  int motor2b = 5;
 //Here we declare and initialise the echo and trigger pins for our ultrasonic sensor
  const int trig = 8;
  const int echo = 10;
  long cm = 0;//variable for distance
  long enable = 12;//Here we initialise our IC enable pin
  int Switch = 13;//switch pin to control IC

void setup() {
  // setup codes runs only once:
  //We also set our arduino pins as either output or input pins
  pinMode(motor1a,OUTPUT);
  pinMode(motor1b, OUTPUT);
  pinMode(motor2a, OUTPUT);
  pinMode(motor2b, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(enable, OUTPUT);
  pinMode(Switch, INPUT);
  Serial.begin(9600);
  digitalWrite(enable,HIGH);

  
}
void loop() {
  //We send and receive sound waves from the ultrasonic sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  //we recieve the waves back and use it to calculate distance
  long distance = pulseIn(echo, HIGH);
  cm = distance/54;
  delay(10);
  //We print distance here for simulation and  testing purposes
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  //we use calculated distance to control the motion of our UGV
  if (cm >=500)
  {
    digitalWrite(motor1a, HIGH);
    digitalWrite(motor1b, LOW);
    digitalWrite(motor2a, HIGH);
    digitalWrite(motor2b, LOW);
  }
  else 
  {
    digitalWrite(motor1b, HIGH);
    digitalWrite(motor1a, LOW);
    digitalWrite(motor2b, HIGH);
    digitalWrite(motor2a, LOW);
    }

  //we use the status of switch to control our IC
  if (digitalRead(Switch)==HIGH)
  {
    digitalWrite(enable, LOW);
    }
  else 
  {
    digitalWrite(enable, HIGH);
  }
   delay(100);

}

