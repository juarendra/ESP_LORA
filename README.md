# ESP_LORA

ESP-LORA By [Positron Electronik](https://www.tokopedia.com/positronelectronic?source=universe&st=product) is a High-end Development Board with an [ARDUINO UNO-like](https://www.google.com/search?q=arduino+uno+format+pin&sca_esv=93393d72ee4371e2&sca_upv=1&rlz=1C1VDKB_enID1038ID1038&udm=2&biw=1366&bih=599&sxsrf=ADLYWILx3s-laQePL8CYNEJDGoxvoD8W7g%3A1719477255939&ei=ByR9Ztj2ONibseMP1Nq4yAI&ved=0ahUKEwiYlqj4r_uGAxXYTWwGHVQtDikQ4dUDCBA&uact=5&oq=arduino+uno+format+pin&gs_lp=Egxnd3Mtd2l6LXNlcnAiFmFyZHVpbm8gdW5vIGZvcm1hdCBwaW5Iyx9QiwtY-BxwA3gAkAEAmAFkoAH-BqoBBDEzLjG4AQPIAQD4AQGYAgugAsoEwgIEECMYJ8ICBhAAGAcYHsICBRAAGIAEwgIEEAAYHsICBxAAGIAEGBPCAgYQABgTGB7CAggQABgTGAgYHsICBhAAGAgYHsICBxAAGIAEGBiYAwCIBgGSBwQxMC4xoAfSNA&sclient=gws-wiz-serp) format, which will speed up your time to make your DIY projects easier.
This board is based on the [ESP32 microcontroller](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf) which makes it an AI-enabled device and is recommended as an Edge Device.
The ESP-LORA By [Positron Electronik](https://www.tokopedia.com/positronelectronic?source=universe&st=product) has three power source inputs -USB, LiPo Battery, DC Jack- that can carry out these options simultaneously. If you use a DC Jack you will get a PSU with a Voltage of 5V 3A.

This board has a LI-PO battery charging feature with a max voltage of 4.2, equipped with Charging Protection so that charging your battery can be done more safely, the charging process can only be done with a USB power source.
By default, the [ESP32 microcontroller](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf) is included with WiFi and Bluetooth Low Energy. This connectivity is even expanded with the presence of the [RFM95W](https://cdn.sparkfun.com/assets/a/e/7/e/b/RFM95_96_97_98W.pdf) LoRa(WAN) module. LoRa(WAN) has a good reputation for low power consumption, complementing the [ESP32 microcontroller](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf)'s sleep mode, making this board even more useful in low-power ecosystems. In conclusion, this is the most appropriate solution for your IoT application.

In terms of design, this board is also equipped with an Industrial SHT21 Hum Temp Sensor and 0.91 inch Oled Display

## Table of Content

* [Product Specsification](#product-specsification)
* [Technical Spesification](#technical-spesification)
* [Priview Hardware](#priview-hardware)
* [Documentation](#documentation)
  * [Pinout Diagram](#pinout-diagram)
  * [Dimension](#dimension)
  * [BOM](#bom)
  * [Schematic](#schematic0)
  * [Example Program](#examples-program)
* [FAQ](#FAQ)

## Product Specsification

* ESP32 as Microcontroller Ready for AI (Tensilica Xtensa single-/dual-core 32-bit LX6 microprocessor(s))
* WiFi & BLE Connectivity 
* LoRa/LoRaWAN Connectivity
* Industrial Temperature Humidity Sensor
* Display Oled 0.91 inch
* Battery Input 1s LiPo with Battery Protection
* Big Power PSU 5V 3A
* Sparated PSU for Microcontroller and LORA

## Technical Spesification

| Features                           | Value                |  
| ---------------------------------- | -------------------- |
| Microcontroller                    | ESP32                |
| LoRa(WAN) Chip                     | RFM95W               |
| LoRa(WAN) Base Freq                | 915 MHz              |
| LoRa(WAN) Freq Range               | 902-928 MHz          |
| Industrial Temperature Humidity Sensor | SHT21            |
| Dispaly                            | OLED 0.91 inch       |
| Main PSU                           | LM2596 5-30VDC to 5V 3A |
| PSU ESP32                          | M3406 2.0V to 6.0V to 3.3V 800mA|
| PSU LORA                           | M3406 2.0V to 6.0V to 3.3V 800mA|    

## Priview Hardware
<p align="center">
  <img src="DOC/esp32_lora_1.png" width="50%" height="50%">
  <img src="DOC/esp32_lora_4.png" width="50%" height="50%">
  <img src="DOC/esp32_lora_5.png" width="50%" height="50%">
</p>

## Documentation
### Pinout Diagram
### Dimension
* [Dimension Board with Component](https://github.com/juarendra/ESP_LORA/blob/main/HARDWARE/Dimension_ESP32_LORA.pdf)
### BOM
* [BOM Board](https://github.com/juarendra/ESP_LORA/blob/main/HARDWARE/EAGLE/BOM/esp32_lora.csv)
### Schematic
* [Schematic](https://github.com/juarendra/ESP_LORA/blob/main/HARDWARE/EAGLE/PDF/esp32_lora.pdf)
### Example Program

## FAQ