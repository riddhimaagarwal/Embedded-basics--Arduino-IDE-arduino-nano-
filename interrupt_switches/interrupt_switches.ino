const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;

const int ledPin1 = 11;
const int ledPin2 = 12;
const int ledPin3 = 13; 

volatile bool toggleLED1 = false;
volatile bool toggleLED2 = false;

bool lastButton3State = HIGH;

void setup() 
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(buttonPin1), handleButton1, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), handleButton2, FALLING);
}

void loop() 
{
  static bool led1State = LOW;
  static bool led2State = LOW;

  if (toggleLED1) 
  {
    led1State = !led1State;
    digitalWrite(ledPin1, led1State);
    toggleLED1 = false;
  }

  if (toggleLED2) 
  {
    led2State = !led2State;
    digitalWrite(ledPin2, led2State);
    toggleLED2 = false;
  }

  bool currentButton3State = digitalRead(buttonPin3);
  if (lastButton3State == HIGH && currentButton3State == LOW) 
  {
    digitalWrite(ledPin3, !digitalRead(ledPin3)); // Toggle LED3
    delay(50);
  }
  lastButton3State = currentButton3State;
}


void handleButton1() 
{
  toggleLED1 = true;
}

void handleButton2() 
{
  toggleLED2 = true;
}