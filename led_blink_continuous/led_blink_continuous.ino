int sw1=2;
int sw2=3;

int led1=13;
int switch_state=0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);


  pinMode(led1, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  if(digitalRead(sw1)==LOW){
    switch_state=1;
  }
  if(digitalRead(sw2)==LOW){
    switch_state=0;
  }
  if(switch_state==0){
    digitalWrite(led1, LOW);
  }
  else{
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(1000);
  }

}

