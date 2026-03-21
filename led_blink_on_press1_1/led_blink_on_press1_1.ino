int sw1=5;
int sw2=6;
int sw3=7;

int led1=2;
int led2=3;
int led3=4;

int switch1_state=0;
int switch2_state=0;
int switch3_state=0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  switch1_state=digitalRead(sw1);
  switch2_state=digitalRead(sw2);
  switch3_state=digitalRead(sw3);
  if(switch1_state){
  digitalWrite(led1, HIGH);
  }
  else{
  digitalWrite(led1, LOW);
  }
  if(switch2_state){
  digitalWrite(led2, HIGH);
  }
  else{
  digitalWrite(led2, LOW);
  }
  if(switch3_state){
  digitalWrite(led3, HIGH);
  }
  else{
  digitalWrite(led3, LOW);
  }
  }