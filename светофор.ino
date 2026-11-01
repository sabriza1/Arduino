const int redLed = 7;
const int yellowLed = 6;
const int greenLed = 5;
const int startBtn = 12;
const int stopBtn = 13;

bool running = false;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(startBtn, INPUT_PULLUP);
  pinMode(stopBtn, INPUT_PULLUP);

  allOff();
}

void allOff() {
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}

bool checkStop(unsigned long duration) {
  unsigned long previousTime = millis();

  while (millis() - previousTime < duration) {
    if (digitalRead(stopBtn) == LOW) {
      running = false;
      allOff();
      return false;
    }
  }

  return true;
}

void loop() {
  if (digitalRead(stopBtn) == LOW) {
    running = false;
    allOff();
  }
  
  if (!running && digitalRead(startBtn) == LOW) {
    running = true;
    delay(200);
  }

  if (running) {
    
    digitalWrite(redLed, HIGH);
    if (!checkStop(3000)) return;
    digitalWrite(redLed, LOW);

    digitalWrite(yellowLed, HIGH);
    if (!checkStop(1000)) return;
    digitalWrite(yellowLed, LOW);

    digitalWrite(greenLed, HIGH);
    if (!checkStop(3000)) return;
    digitalWrite(greenLed, LOW);
  }
}

