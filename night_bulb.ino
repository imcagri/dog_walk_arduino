#include <Wire.h>
#include <LiquidCrystal_I2C.h>  // I2C kütüphanesini verdiğim linkten indirip   include edebilirsiniz
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int SOUND_PIN = "A2";
int value;
unsigned long lastEvent = 0;
int ledPin = 10;  // LED connected to digital pin 9

void setup() {
  pinMode(SOUND_PIN, INPUT);  // Set sensor pin as an INPUT
  Serial.begin(9600);         //  setup serial
  pinMode(ledPin, OUTPUT);    // sets the pin as output

  lcd.init();  // LCD yi başlatma
  ///lcd.backlight();             // lcd nin arka ışıgını açar
}

void loop() {
  for (int i = 0; i < 255; i++) {
    analogWrite(ledPin, i);
    Serial.println(i);
    // lcd.clear();
    // lcd.setCursor(0,0);
    // lcd.print("Uuu beybi, hareket");
    // lcd.setCursor(0,1);
    // lcd.print("Degeri: " + String(i));
    
    delay(300);
  }

  delay(300);
  for (int i = 0; i < 255; i++) {
    Serial.println(i);

    // lcd.clear();
    // lcd.setCursor(0,0);
    // lcd.print("Uuu beybi, hareket");
    // lcd.setCursor(0,1);
    // lcd.print("Degeri 2: " + String(i));
    

    analogWrite(ledPin, 255 - i);
    delay(300);
  }
  delay(300);

  value = analogRead(SOUND_PIN);
  Serial.println(value);
  // If pin goes LOW, sound is detected
  if (value == LOW) {

    // If 25ms have passed since last LOW state, it means that
    // the clap is detected and not due to any spurious sounds
    if (millis() - lastEvent > 25) {
      //Serial.println("Clap detected!");
    }

    // Remember when last event happened
    lastEvent = millis();
  }

  delay(100);
}  //loop
