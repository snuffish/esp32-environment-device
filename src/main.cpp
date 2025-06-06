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

static const unsigned char PROGMEM image_music_radio_streaming_bits[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x02,0x00,0x40,0x01,0x00,0x48,0x09,0x00,0x90,0x84,0x80,0xa5,0xd2,0x80,0xa9,0x4a,0x80,0xa5,0xd2,0x80,0x90,0x84,0x80,0x48,0x09,0x00,0x40,0x01,0x00,0x20,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

void setup() {
    tft.initR(INITR_BLACKTAB); // Initialize the display with the correct tab color
    tft.fillScreen(ST7735_BLACK); // Clear the screen
    tft.setTextColor(ST7735_WHITE); // Set text color to white
    tft.setTextSize(2); // Set text size
    tft.setCursor(10, 10); // Set cursor position
    tft.print("Hello, World!"); // Print text

    // music_radio_streaming
    tft.drawBitmap(0, 0, image_music_radio_streaming_bits, 17, 16, 0xFFFF);

    // Layer 2
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.setCursor(21, 5);
    tft.print("IR Signals");

}

void draw(void) {
    // Layer 1

}

void loop() {
    draw();
}
