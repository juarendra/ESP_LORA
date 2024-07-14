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
#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define LORA_NSS 15
#define LORA_RST 0
#define LORA_DIO0 27
#define LORA_EN 32

int counter = 0;

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

void setup() {
  // Initiate the LoRa Enable pin
  pinMode(LORA_EN, OUTPUT);
  // LoRa chip is Active High
  digitalWrite(LORA_EN, HIGH);

  //initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");

  //setup LoRa transceiver module
  LoRa.setPins(LORA_NSS, LORA_RST, LORA_DIO0);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(920E6)) {
    Serial.println(".");
    delay(500);
  }
  
  // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");

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

void loop() {

  getSHT21();
  displayData();

  Serial.print("Sending packet: ");
  Serial.println(counter);

  //Send LoRa packet to receiver
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.print("Temp: ==>,");
  LoRa.print(localTemp);
  LoRa.print(",");
  LoRa.print("  Hum ==>,");
  LoRa.print(localHum);
  LoRa.print(",");
  LoRa.endPacket();
  
  counter++;

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