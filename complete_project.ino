#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
DFRobotDFPlayerMini player;
int sensor1 = A0;
int sensor2= A1;
int sensor3= A3;

int sensor4=A3;
int relay=12;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(relay, OUTPUT);
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("Sign Conversion");
  lcd.setCursor(3, 1);
  lcd.print("Device !");
  Serial.begin(9600);
    // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("OK");

    player.volume(40);
  
    

  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }
}

void loop()
{
  sensor1 = analogRead(A0);
  sensor2 = analogRead(A1);
  sensor3 = analogRead(A2);
  sensor4 = analogRead(A3);
  Serial.print("sensor1= ");
  Serial.println(sensor1);
  delay(500);
  Serial.print("sensor2= ");
  Serial.println(sensor2);
  delay(500);
  Serial.print("sensor3= ");
  Serial.println(sensor3);
  // Wait for 100 millisecond(s)
  Serial.print("sensor4= ");
  Serial.println(sensor4);
  delay(500); // Wait for 100 millisecond(s)
  if (sensor1<= 600) {
    
    Serial.println("Plz Give Me Water");
    player.playMp3Folder(2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Plz Give Me");
    lcd.setCursor(0, 1);
    lcd.print("     Water   ");
    delay(500);
    lcd.clear();

  }

  else if (sensor2<= 200) {
    
    Serial.println("Plz Give Me Food");
    player.playMp3Folder(1);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Plz Give Me ");
    lcd.setCursor(0, 1);
    lcd.print("     Food   ");
    delay(500);
    lcd.clear();
    
  }


    
  
  
    else if (sensor4<800) {
    Serial.println("Thank You");
    player.playMp3Folder(4);
    digitalWrite(relay,HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Thank");
    lcd.setCursor(0, 1);
    lcd.print("     You   ");
    delay(500);
  }

  else {
  }
  delay(200);
}