#include <LiquidCrystal.h>

int index = 1;
int numbers[] = {0, 0, 0};
int randomNumbers[] = {2, 5, 5};
char statuses[] = {'a', 'b', 'c'};
int guesses = 10;
int ledValue;
const byte ledPin = 10;
const byte interruptPin_number = 3;
const byte interruptPin_index = 2;
volatile byte state_number_but = LOW;
volatile byte state_index_but = LOW;
unsigned long lastInterrupt_index;
unsigned long lastInterrupt_number;

LiquidCrystal lcd(4, 7, 8, 11, 12, 13);

void setup() {
  randomSeed(analogRead(0));
  ledValue = random(255);
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.print(ledValue);
  pinMode(interruptPin_number, INPUT_PULLUP);
  pinMode(interruptPin_index, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin_number), updateNumber, HIGH);
  attachInterrupt(digitalPinToInterrupt(interruptPin_index), updateIndex, HIGH);
  lcd.print("welcome to");
  lcd.setCursor(0, 1);
  lcd.print("ardunio mind");
  delay(1000);
  lcd.clear();
  lcd.print("for reference");
  lcd.setCursor(0, 1);
  lcd.print("this is 255");
  analogWrite(ledPin, 255);
  delay(2000);
  lcd.clear();
  lcd.print("for reference");
  lcd.setCursor(0, 1);
  lcd.print("this is 0");
  analogWrite(ledPin, 0);
  delay(2000);
  analogWrite(ledPin, ledValue);
  setLCD();

}

void loop() {
  analogWrite(ledPin, ledValue);
}
void setLCD() {
  lcd.clear();
  lcd.print("guesses left:");
  lcd.setCursor(13,0);
  lcd.print(guesses);
  lcd.setCursor(0, 1);
  lcd.print(numbers[0]);
  lcd.setCursor(2, 1);
  lcd.print(numbers[1]);
  lcd.setCursor(4, 1);
  lcd.print(numbers[2]);

}
void updateIndex() {
  if (millis() - lastInterrupt_index > 500) {
    if (index++ > 2) {
      index = 1;
    }
    lastInterrupt_index = millis();
  }
  else if (millis() - lastInterrupt_index > 200 ) {
    submit();
  }

}
void updateNumber() {
  if (millis() - lastInterrupt_number > 200) {
    if (numbers[index - 1]++ > 4 || (index == 1 && numbers[0] > 2)) {
      numbers[index - 1] = 0;
    }
    lastInterrupt_number = millis();
    setLCD();
  }
}
void submit() {
  setLCD();
  lcd.setCursor(6, 1);

}
