#define BUT1  D5
#define BUT2  D6
#define BUT3  D7

void setup() {
  Serial.begin(9600);
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);
}

void loop() {
  if(digitalRead(BUT1) == LOW)
    Serial.println("BUT1");
  if(digitalRead(BUT2) == LOW)
    Serial.println("BUT2");
  if(digitalRead(BUT3) == LOW)
    Serial.println("BUT3");
}
