#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 2, 16);


const byte numROWS = 4;
const byte numCOLS = 4;

char keys[numROWS][numCOLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'.', '0', '=', '/'}
};
  

byte rowPins[numROWS] = {9, 8, 7, 6};
byte colPins[numCOLS] =  {5, 4, 3, 2};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, numROWS, numCOLS );

uint64_t value = 0


void StartScreen() {
  lcd.print("Test");
  delay(500);

}

void updateCursor() {
  if (millis() / 250 % 2 == 0 ) {
    lcd.cursor();
  } else {
    lcd.noCursor();
  }
}

void setup() {
  lcd.begin();
  lcd.backlight();
  StartScreen();
  lcd.clear();
  lcd.cursor();
  lcd.setCursor(1, 0);
}

char operation = 0;
String memory = "";
String current = "";
uint64_t currentDecimal;
bool decimalPoint = false;

double calculate(char operation, double left, double right) {
  switch (operation) {
    case '+': return left + right;
    case '-': return left - right;
    case '*': return left * right;
    case '/': return left / right;
  }
}

void processInput(char key) {
  if ('-' == key && current == "") {
    current = "-";
    lcd.print("-");
    return;
  }

  switch (key) {
    case '+':
    case '-':
    case '*':
    case '/':
      if (!operation) {
        memory = current;
        current = "";
      }
      operation = key;
      lcd.setCursor(0, 1);
      lcd.print(key);
      lcd.setCursor(current.length() + 1, 1);
      return;

    case '=':
      float leftNum = memory.toDouble();
      float rightNum = current.toDouble();
      memory = String(calculate(operation, leftNum, rightNum));
      current = "";
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print(memory);
      lcd.setCursor(0, 1);
      lcd.print(operation)
      return;

  }

  if ('.' == key && current.indexOf('.') >= 0) {
    return;
  }

  if ('.' != key && current == "0") {
    current = String(key);
  } else if (key) {
    current += String(key);
  }

  lcd.print(key);
}

void loop() {
  updateCursor();

  char key = keypad.getKey();
  if (key) {
    processInput(key);
  }
}