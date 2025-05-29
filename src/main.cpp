#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define ST7735_DRIVER
#define TFT_WIDTH 128
#define TFT_HEIGHT 160
#define ST7735_INITB
#define TFT_CS 5 // Chip select control pin
#define TFT_DC 2 // Data Command control pin
#define TFT_RST 4 // Reset pin (optional)
#define SPI_FREQUENCY 27000000

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
    tft.initR(INITR_GREENTAB); // Initialize the display with the correct tab color
    tft.fillScreen(ST7735_BLACK); // Clear the screen
    tft.setTextColor(ST7735_WHITE); // Set text color to white
    tft.setTextSize(2); // Set text size
    tft.setCursor(10, 10); // Set cursor position
    tft.print("Hello, World!"); // Print text
}

void loop() {
    // Add your code here
}
