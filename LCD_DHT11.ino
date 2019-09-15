// include the library code:
#include <LiquidCrystal.h>
#include <DHT.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// initialise DHT sensor data pin and DHT sensor type
#define DHTPIN 8
#define DHTTYPE DHT11

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hi, Fahmi!");
  // Set up serial baud rate and initialisation message
  Serial.begin(9600);
  Serial.println(F("DHT11 reading with LCD display initialised!!"));
  // Start DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Sensor ERROR!"));
    return;
  }

  lcd.clear();
  // set the cursor to column 0, line 0
  lcd.setCursor(0, 0);
  lcd.print(F("Hi, Fahmi!"));

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print temperature and humidity
  lcd.print(F("T:"));
  lcd.print(t, 1);
  lcd.print(F("C"));
  lcd.print(F(" H:"));
  lcd.print(h, 1);
  lcd.print(F("%"));
}
