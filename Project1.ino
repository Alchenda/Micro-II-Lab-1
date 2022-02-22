int button = 2;
int buttonState = 0;
int i = 0;
int count = 0;
int swtch = 0;
int redLED = 11;
int greenLED = 10;
int yellowLED = 12;
int buzzer = 6;

void setup() {

  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT);
  pinMode(6, OUTPUT);
  
while (0 != 1){     //Loop forever, but always check if button was pressed.
    digitalWrite(redLED, HIGH);
    for(i = 0; i < 100; i++) {    //Split one delay into smaller delays so button can be checked. 
      delay(10);                  //Break must be called twice to first exit from for loop, then from while
      if (digitalRead(button) == 1) {
        buttonState = 1;    
        break;
      }
    }
    if (buttonState == 1){
      break;
    }
    digitalWrite(redLED, LOW);
    for(i = 0; i < 100; i++) {
      delay(10);
      if (digitalRead(button) == 1) {
        buttonState = 1;
        break;
      }
    }
    if (buttonState == 1){
      break;
    }
  }
}
  /*while (1 != 0) {
    if (digitalRead(button) == 1) {
      break;
    }
    else{
      digitalWrite(redLED, HIGH);
      delay(1000);
      digitalWrite(redLED, LOW);
      delay(1000);
    }
  }*/
}

void loop() {

  if (count != 45 && count != 0) {
    delay(1000);
  }
  count += 1;
  count = count % 46;
  Serial.print(count);
  Serial.print("\n");
  if (count == 1) {
    digitalWrite(redLED, HIGH);
  }
  if (count == 17) {
    tone(buzzer, 1000);
  }
  if (count == 20) {
    digitalWrite(redLED, LOW);
    noTone(buzzer);
    digitalWrite(greenLED, HIGH);
  }
  if (count == 37) {
    tone(buzzer, 1000);
  }
  if (count == 40) {
    digitalWrite(greenLED, LOW);
    noTone(buzzer);
    digitalWrite(yellowLED, HIGH);
  }
  if (count == 43){
    tone(buzzer, 1000);
    for (int i = 0; i < 15; i++) { //Blink yellow LED for 3 sec.
      digitalWrite(yellowLED, LOW);
      delay(100);
      digitalWrite(yellowLED, HIGH);
      delay(100);
      if (i == 4 || i == 9) {
        count += 1;
        Serial.print(count);
        Serial.print("\n");
      }
    }
    noTone(buzzer);
    digitalWrite(yellowLED, LOW);
  }
}
