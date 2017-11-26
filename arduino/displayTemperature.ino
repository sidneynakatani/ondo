#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <DHT.h>
#define DHTPIN A1       // Analog pin A1 
#define DHTTYPE DHT11   // DHT 11
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Wire.begin();
  dht.begin(); // initialize dht
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);// initialize with the I2C addr 0x3C (for the 128x32)(initializing the display)
  Serial.begin(9600);
}
void displayTempHumid(){
  delay(2000);
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Humidity: "); 
  display.print(h);
  display.print(" %\t");
  display.setCursor(0,10);
  display.print("Temperature: "); 
  display.print(t);
  display.print(" C"); 
 
}
void loop()
{
  displayTempHumid();
  display.display();
}
