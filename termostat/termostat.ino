/*
 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 *One wire bus at pin 6
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe 
 modified 22 Nov 2010
 by Tom Igoe
*/

// include the library code:
#include <LiquidCrystal.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 6 on the Arduino
#define ONE_WIRE_BUS 6

// Setup a oneWire instance to communicate with ANY OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Set oneWire reference to Dallas Temperature sensor.
DallasTemperature sensors(&oneWire);

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int led = 13;

void setup() {
  // initialize the DS18B20 sensor
  sensors.begin();
  
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  
  pinMode(led, OUTPUT);
}

void loop() {
  
  sensors.requestTemperatures();
  int temperatura = sensors.getTempCByIndex(0);
  
  if (temperatura < 30) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);
  
  lcd.setCursor(0, 1);
  lcd.print(temperatura);
  
}

