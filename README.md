# ESP32 Environment Device

A Device gadget who can monitor the Environment and respond/communicate through the GSM (2G MobileNetwork).

This is an alternative if an WiFi connection isn`t avaible at the desired location of operation.

## Features

- BME280 (Environment Sensor)
- SSD1306 (Oled Display)
- SIM800L (GSM 2G MobileNetwork Receiver/Transmitter)

## Implementation details

### Schematic connections

```
BME280 (VCC) => ESP32 (3.3v)
BME280 (GND) => ESP32 (GND)
BME280 (SDA) => ESP32 (GPIO 21)
BME280 (SCL) => ESP32 (GPIO 22)

SSD1306 (VCC) => ESP32 (3.3v)
SSD1306 (GND) => ESP32 (GND)
SSD1306 (SDA) => ESP32 (GPIO 21)
SSD1306 (SCL) => ESP32 (GPIO 22)
```

-----
Work in progress...
