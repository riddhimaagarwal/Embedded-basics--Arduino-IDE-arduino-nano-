const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;

const int ledPin1 = 11;
const int ledPin2 = 12;
const int ledPin3 = 13;


const unsigned long debounceDelay = 50;

volatile bool button1InterruptFlag = false;
unsigned long lastDebounceTime1 = 0;
bool led1State = LOW;

volatile bool button2InterruptFlag = false;
unsigned long lastDebounceTime2 = 0;
bool led2State = LOW;

bool lastButton3State = HIGH;
unsigned long lastDebounceTime3 = 0;
bool led3State = LOW;

void setup() 
{
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(buttonPin1), isrButton1, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonPin2), isrButton2, FALLING);
}

void loop() 
{
  unsigned long currentTime = millis();

  if (button1InterruptFlag && (currentTime - lastDebounceTime1) >= debounceDelay) 
  {
    if (digitalRead(buttonPin1) == LOW) 
    {
      led1State = !led1State;
      digitalWrite(ledPin1, led1State);
    }
    button1InterruptFlag = false;
    lastDebounceTime1 = currentTime;
  }


  if (button2InterruptFlag && (currentTime - lastDebounceTime2) >= debounceDelay) 
  {
    if (digitalRead(buttonPin2) == LOW) 
    {
      led2State = !led2State;
      digitalWrite(ledPin2, led2State);
    }
    button2InterruptFlag = false;
    lastDebounceTime2 = currentTime;
  }
  bool currentButton3State = digitalRead(buttonPin3);
  if (currentButton3State != lastButton3State) 
  {
    lastDebounceTime3 = currentTime;
  }

  if ((currentTime - lastDebounceTime3) >= debounceDelay) 
  {
    if (lastButton3State == HIGH && currentButton3State == LOW) 
    {
      led3State = !led3State;
      digitalWrite(ledPin3, led3State);
    }
  }

  lastButton3State = currentButton3State;
}

void isrButton1() 
{
  button1InterruptFlag = true;
}

void isrButton2() 
{
  button2InterruptFlag = true;
}

