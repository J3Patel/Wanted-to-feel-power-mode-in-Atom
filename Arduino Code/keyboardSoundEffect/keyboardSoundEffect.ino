int currentRandm = 0;

void setup() {

  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  digitalWrite(9, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}

void loop() {
  if (Serial.available() > 0) {
    // read incoming serial data:
    char inChar = Serial.read();
    if(inChar == '2') {
        digitalWrite(8, LOW);
        delay(40);
        digitalWrite(8, HIGH);
    } else {
        currentRandm = random(2,8);
        digitalWrite(7, LOW);
        digitalWrite(9, LOW);
        delay(50);
        digitalWrite(7, HIGH);
        digitalWrite(9, HIGH);
    }
  }
}
