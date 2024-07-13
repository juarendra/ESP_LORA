/* Copyright 2024 Juarendra Ramadhani <jrjuarendra@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
  
#include "modified_font.h"

/*  SSD1306 */
#include "SSD1306.h" 
#define SDA_PIN 21
#define SCL_PIN 22
#define SSD_ADDRESS 0x3c
SSD1306  display(SSD_ADDRESS, SDA_PIN, SCL_PIN);

/* SHT21 */
#include "Wire.h"
#include "SHT2x.h"
uint32_t start;
uint32_t stop;

float localHum = 0;
float localTemp = 0;

SHT2x sht;

void setup() 
{
  Serial.begin(115200);
  Serial.println("");
  Serial.println("ESP32-LORA SHT21 Display to oled");
  Serial.println("");

  Serial.println(__FILE__);
  Serial.print("SHT2x_LIB_VERSION: \t");
  Serial.println(SHT2x_LIB_VERSION);

  Wire.begin(SDA_PIN, SCL_PIN);
  sht.begin();
  
  uint8_t stat = sht.getStatus();
  Serial.print(stat, HEX);
  Serial.println();

  display.init();

  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(Open_Sans_Condensed_Light_20); 
}

void loop() 
{
  getSHT21();
  displayData();
  delay(2000);
}

/***************************************************
* Get indoor Temp/Hum data
****************************************************/
void getSHT21()
{
  start = micros();
  sht.read();
  stop = micros();

  float tempIni = localTemp;
  float humIni = localHum;
  localTemp = sht.getTemperature();
  localHum = sht.getHumidity();
  if (isnan(localHum) || isnan(localTemp))   
  {
    localTemp = tempIni;
    localHum = humIni;
    return;
  }
}

/***************************************************
* Display Data
****************************************************/
void displayData() 
{
  Serial.print("Temp: ==> ");
  Serial.print(localTemp);
  Serial.print("  Hum ==> ");
  Serial.println(localHum);

  display.clear();  

  display.drawString(0, 0,  "temp: ");
  display.drawString(40, 0,  String(localTemp));
  display.drawString(90, 0,  "oC");
  display.drawString(0, 32, "hum:  ");
  display.drawString(40, 32,  String(localHum));
  display.drawString(90, 32,  "%");

  display.display();  
  delay(10);
}