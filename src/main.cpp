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

static const unsigned char PROGMEM image_music_radio_broadcast_bits[] = {0x07,0xc0,0x18,0x30,0x27,0xc8,0x48,0x24,0x93,0x92,0xa4,0x4a,0xa9,0x2a,0xa3,0x8a,0x06,0xc0,0x03,0x80,0x01,0x00,0x03,0x80,0x02,0x80,0x06,0xc0,0x04,0x40};

void setup() {
    tft.initR(INITR_BLACKTAB); // Initialize the display with the correct tab color
    tft.fillScreen(ST7735_BLACK); // Clear the screen
    tft.setTextColor(ST7735_WHITE); // Set text color to white
    // tft.setTextSize(2); // Set text size
    // tft.setCursor(10, 10); // Set cursor position
    // tft.print("Hello, World!"); // Print text

    // tft.drawBitmap(2, 1, image_Layer_1_bits, 5, 4, 0xFFFF);*/

    // // music_radio_streaming
    // tft.drawBitmap(0, 0, image_music_radio_streaming_bits, 17, 16, 0xFFFF);
    //
    // // Layer 2
    // tft.setTextColor(0xFFFF);
    // tft.setTextSize(1);
    // tft.setCursor(21, 5);
    // tft.print("IR Signals");

}

void draw() {
    tft.drawBitmap(3, 2, image_music_radio_broadcast_bits, 15, 15, 0xFFFF);

    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.setCursor(24, 7);
    tft.print("RFID");

    tft.drawLine(0, 21, 128, 21, 0xFFFF);
}

void loop() {
    draw();
}
