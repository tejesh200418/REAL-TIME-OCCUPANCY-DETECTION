//Arduino sketch for Real-time occupancy detection
#include <LiquidCrystal.h>


// RS = D7, E = D6, D4 = D5, D5 = D4, D6 = D3, D7 = D9
LiquidCrystal lcd(7, 6, 5, 4, 3, 9);


#define PIR_PIN 2       // PIR sensor output pin
#define LED_PIN 8    // LED output pin

void setup() {
  
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  // Start serial communication
  Serial.begin(9600);

  // Initialize LCD
  lcd.begin(16, 2);              // 16 columns, 2 rows
  lcd.setCursor(0, 0);
  lcd.print("Occupancy System");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);                   
  lcd.clear();
}

void loop() {
  int motion = digitalRead(PIR_PIN);  // Read PIR sensor

  if (motion == HIGH) {
    digitalWrite(LED_PIN, HIGH);           
    lcd.setCursor(0, 0);
    lcd.print("Status: Occupied ");        
    Serial.println("Motion detected!");
  } else {
    digitalWrite(LED_PIN, LOW);            
    lcd.setCursor(0, 0);
    lcd.print("Status: Vacant   ");        
    Serial.println("No motion.");
  }

  delay(300);  
}
