#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <memory>
#include <SPI.h>

#include "icons.h"
#include "menu.h"

// Remove the FreeSansBold9pt7b include since ST7735 doesn't support GFX fonts
// #include <Fonts/FreeSansBold9pt7b.h>

#define ST7735_DRIVER
#define TFT_WIDTH 128
#define TFT_HEIGHT 160
#define ST7735_INITB
#define TFT_CS 5 
#define TFT_DC 2 
#define TFT_RST 4 
#define SPI_FREQUENCY 27000000

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// Declare menu as pointer or optional
std::unique_ptr<Menu> menu = nullptr;  // Change declaration

void setup() {
    tft.initR(INITR_BLACKTAB); 
    tft.fillScreen(ST7735_BLACK); 
    tft.setTextColor(ST7735_WHITE); 

    // Create menu after tft is initialized
    menu = std::make_unique<Menu>(&tft);   // This will work correctly
    // menu = new Menu(&tft);
    
    menu->addMenuItem("RFID", rfid_logo_bits);
    menu->addMenuItem("WiFi", wifi_logo_bits);
    menu->addMenuItem("IR Signal", ir_signal_logo_bits);
    
    menu->draw();
}

void loop(void)
{
    // tft.fillScreen(ST7735_BLACK);
    // delay(1000);
}

void draw(void)
{

    // tft.drawBitmap(58, 31, image_Layer_6_bits, 0, 0, 0xFFFF);

    // tft.setCursor(25, 48);
    // tft.print("WiFi");
    //
    // tft.drawBitmap(58, 56, image_Layer_6_bits, 0, 0, 0xFFFF);
    //
    // tft.drawBitmap(0, 0, image_Layer_6_bits, 0, 0, 0xFFFF);
    //
    // tft.drawBitmap(4, 47, image_wifi_bits, 19, 15, 0xFFFF);
    //
    // tft.drawBitmap(42, 57, image_Layer_6_bits, 0, 0, 0xFFFF);
    //
    // tft.drawBitmap(31, 54, image_Layer_6_bits, 0, 0, 0xFFFF);
    //
    // tft.drawBitmap(35, 55, image_Layer_6_bits, 0, 0, 0xFFFF);
    //
    // tft.drawBitmap(5, 24, image_music_radio_streaming_bits, 17, 11, 0xFFFF);
    //
    // tft.drawBitmap(34, 80, image_Layer_6_bits, 0, 0, 0xFFFF);
    //
    // // Fixed: Replace drawString with setCursor + print
    // tft.setCursor(26, 73);
    // tft.print("IR SIGNAL");
    //
    // tft.drawBitmap(112, 1, image_Battery_bits, 16, 16, 0x4D6A);
    //
    // tft.drawBitmap(4, 72, image_music_radio_broadcast_bits, 15, 15, 0xFFFF);
}