int senpin = A5;
int buzzer = 12;

long val = 0;
long average = 0;
int threshold = 59;

String answ;

void setup() {
  pinMode(senpin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) { 
    answ = Serial.readStringUntil('\n');
    threshold = answ.toInt();
  }
  sensor();
}

void sensor() {
  for (int i = 0; i < 160; i++) {
    average = average + analogRead(senpin);
  }
  val = average / 1700;
  average = 0;
  delay(10);

  Serial.print(val);
  Serial.println(threshold);

  if (val >= threshold) {
    Serial.println(val);
    digitalWrite(buzzer, HIGH);
    delay(300);
    digitalWrite(buzzer, LOW);
    delay(300);
    digitalWrite(buzzer, HIGH);
    delay(350);
    digitalWrite(buzzer, LOW);
    delay(90);
  }
}
