int switchState = 0;
int lastTick = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  lastTick = digitalRead(2);
  if (lastTick == 0) {
    if (digitalRead(2) == 1) {
      if (switchState == 0) {
        switchState = 1;
      } else if (switchState == 1) {
        switchState = 0;
      } 
    } else if (lastTick == 1) {
      Serial.println("do nothing");
    }
  }
  while (switchState == 1) {
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(3, LOW);
    delay(500);
  }
  digitalWrite(3, LOW);
}
