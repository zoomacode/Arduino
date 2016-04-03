#include <SPI.h>

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the number of the sspin 
//(or the latch pin of the 74HC595)
LiquidCrystal lcd(10);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Nastya!");
  Serial.print("Hello!!!\n");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  int s = millis()/1000;
  static int prev_s = 0;
  if (s != prev_s) {
    lcd.print(millis()/1000);
    Serial.print(millis()/1000);
    Serial.print("\n");
  }
  prev_s = s;
  delay(500);
}

