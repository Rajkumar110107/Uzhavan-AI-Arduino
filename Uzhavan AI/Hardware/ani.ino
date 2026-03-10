int irPin = 2;
int buzzer = 8;
int buttonPin = 4;

int irVal = 0;

int buttonState = HIGH;
int lastButtonState = HIGH;

void setup() {
  Serial.begin(9600);

  pinMode(irPin, INPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  // IR SENSOR
  irVal = digitalRead(irPin);

  if (irVal == HIGH) {
    Serial.println("ANIMAL DETECTED");
    digitalWrite(buzzer, HIGH);
  } 
  else {
    Serial.println("CLEAR");
    digitalWrite(buzzer, LOW);
  }

  // BUTTON CHECK
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    Serial.println("GET_LOCATION");
    delay(300); // debounce
  }

  lastButtonState = buttonState;

  delay(500);
}