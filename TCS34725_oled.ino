#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_TCS34725.h"
 

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);
 

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
 
 
void setup() {

display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
tcs.begin();
 
 

  display.clearDisplay();
  display.display();
 
 

}
 
void loop() {
 
  uint16_t r, g, b, c, colorTemp, lux;   
  
  tcs.getRawData(&r, &g, &b, &c);

  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
 
 
 
  display.setTextSize(1);        
  display.setTextColor(SSD1306_WHITE);
 
  display.drawRect(0, 0, 69, 27, SSD1306_WHITE);
  display.display(); 
  
  display.setCursor(2,2);         
  display.print(" Red  :"); 
  display.println(r, DEC);
  display.print(" Green:");
  display.println(g, DEC);
  display.print(" Blue :");
  display.println(b, DEC);
  
  display.setCursor(75,5);
  display.print("C.T:");
  display.println(colorTemp, DEC);
 
  display.setCursor(75,15);
  display.print("Lux:");
  display.println(lux, DEC);
  
 
  display.display();
  display.clearDisplay();
 
  delay(50);
 
}