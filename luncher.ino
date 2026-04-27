String msg = "";
#include <Servo.h>
Servo myservo;
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  delay(200);
pinMode(8, OUTPUT);
digitalWrite(8, HIGH);  
}
void loop() {
  if (Serial.available()) {
    msg = Serial.readStringUntil('\n');
    msg.trim();
  }
  if (msg.startsWith("set")) {
    String angleStr = msg.substring(3);   
    int angle = angleStr.toInt();         
    angle = constrain(angle, 0, 180);

    myservo.write(angle);
    Serial.println("Angle set to: " + String(angle));

    msg = "";
  }


  if (msg == "fire!") {
    msg = "";
    cinematicCountdown();
    Serial.println();
    fakeClearScreen();

    digitalWrite(8, LOW); 
    delay(1000);
    digitalWrite(8, HIGH); 
    delay(500);
      digitalWrite(8, LOW); 
    delay(1000);
    digitalWrite(8, HIGH); 
     delay(500);
      digitalWrite(8, LOW); 
    delay(1000);
    digitalWrite(8, HIGH); 
     delay(500);
      digitalWrite(8, LOW); 
    delay(1000);
    digitalWrite(8, HIGH); 
     delay(500);
      digitalWrite(8, LOW); 
    delay(1000);
    digitalWrite(8, HIGH); 
  }

  delay(20);
}

void fakeClearScreen() {
  for (int i = 0; i < 15; i++) Serial.println();
}

void printCentered(String s) {
  int pad = 68;
  for (int i = 0; i < pad; i++) Serial.print(" ");
  Serial.println(s);
}

void cinematicCountdown() {
  for (int i = 10; i >= 1; i--) {
    fakeClearScreen();
    printCentered(String(i));
    fakeClearScreen();
    delay(700);
  }

  fakeClearScreen();
  printCentered("🔥 START FIRE! 🔥");
  delay(1000);
}

void typeText(String txt, int delayMs) {
  for (int i = 0; i < txt.length(); i++) {
    Serial.print(txt[i]);
    delay(delayMs);
  }
}
