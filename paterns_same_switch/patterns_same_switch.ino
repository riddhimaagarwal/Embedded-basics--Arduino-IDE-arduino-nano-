const int ledPins[] = {2, 3, 4};

const int buttonPins[] = {5, 6, 7};

int currentMode = -1;
unsigned long speed = 200;
const unsigned long minSpeed = 50;
const unsigned long maxSpeed = 500;

void setup() 
{
  for (int i = 0; i < 3; i++) 
  {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = 0; i < 3; i++) 
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() 
{
  checkButtons();

  switch (currentMode) 
  {
    case 0:
      chaserLeftToRight();
      break;
    case 1:
      chaserPingPong();
      break;
    case 2:
      chaserAllBlink();
      break;
    default:
      idleAnimation();
      break;
  }
}

void checkButtons() 
{
  for (int i = 0; i < 3; i++) 
  {
    if (digitalRead(buttonPins[i]) == LOW) 
    {
      delay(50);
      if (digitalRead(buttonPins[i]) == LOW) 
      {
        if (currentMode == i) 
        {
          currentMode = -1;
        } 
        else 
        {
          currentMode = i;
        }

        unsigned long pressedTime = millis();
        while (digitalRead(buttonPins[i]) == LOW);
        unsigned long releasedTime = millis();
        unsigned long duration = releasedTime - pressedTime;

        if (i == 0 && duration > 1000) 
        {
          speed -= 50;
          if (speed < minSpeed) speed = minSpeed;
        } 
        else if (i == 1 && duration > 1000) 
        {
          speed += 50;
          if (speed > maxSpeed) speed = maxSpeed;
        }

        delay(200);
      }
    }
  }
}

void chaserLeftToRight() 
{
  for (int i = 0; i < 3; i++) 
  {
    digitalWrite(ledPins[i], HIGH);
    delay(speed);
    digitalWrite(ledPins[i], LOW);
  }
}

void chaserPingPong() 
{
  for (int i = 0; i < 3; i++) 
  {
    digitalWrite(ledPins[i], HIGH);
    delay(speed);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = 1; i >= 0; i--) 
  {
    digitalWrite(ledPins[i], HIGH);
    delay(speed);
    digitalWrite(ledPins[i], LOW);
  }
}

void chaserAllBlink() 
{
  for (int i = 0; i < 3; i++) 
  {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(speed);
  for (int i = 0; i < 3; i++) 
  {
    digitalWrite(ledPins[i], LOW);
  }
  delay(speed);
}

void idleAnimation() 
{
  static bool state = false;
  for (int i = 0; i < 3; i++) 
  {
    digitalWrite(ledPins[i], state ? HIGH : LOW);
  }
  delay(500);
  state = !state;
}