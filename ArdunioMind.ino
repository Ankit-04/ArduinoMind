#include <LiquidCrystal.h>

int index = 1;
int numbers[] = {0, 0, 0};
int guesses = 10;
const byte interruptPin_number = 3;
const byte interruptPin_index = 2;
volatile byte state_number_but = LOW;
volatile byte state_index_but = LOW;
unsigned long lastInterrupt_index;
unsigned long lastInterrupt_number;

LiquidCrystal lcd(4, 7, 8, 11, 12, 13);

void setup() {
  lcd.begin(16, 2);
  pinMode(interruptPin_number, INPUT_PULLUP);
  pinMode(interruptPin_index, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_number), updateNumber, HIGH);
  attachInterrupt(digitalPinToInterrupt(interruptPin_index), updateIndex, HIGH);
  setLCD();

}

void loop() {

}
void setLCD() {
  lcd.clear();
  lcd.print("Enter Your Guess:");
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
void submit(){
  lcd.clear();
  lcd.print("reached");
  }
