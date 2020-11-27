#include <LiquidCrystal.h>

int index = 1;
int numbers[] = {0, 0, 0};
const byte interruptPin_number = 3;
const byte interruptPin_index = 2;
volatile byte state_number_but = LOW;
volatile byte state_index_but = LOW;
unsigned long lastInterrupt;

LiquidCrystal lcd(4, 7, 8, 11, 12, 13);

void setup() {
  lcd.begin(16, 2);
  pinMode(interruptPin_number, INPUT_PULLUP);
  pinMode(interruptPin_index, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin_number), updateNumber, HIGH);
  attachInterrupt(digitalPinToInterrupt(interruptPin_index), updateIndex, HIGH);

}

void loop() {

}
void setLCD() {
lcd.clear();
}
void updateIndex() {
  lcd.print("hello");
}
void updateNumber() {
 lcd.print("hello");
}
