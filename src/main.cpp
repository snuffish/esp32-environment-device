#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <vector>

#include "icons.h"

#define ST7735_DRIVER
#define TFT_WIDTH 128
#define TFT_HEIGHT 160
#define ST7735_INITB
#define TFT_CS 5 // Chip select control pin
#define TFT_DC 2 // Data Command control pin
#define TFT_RST 4 // Reset pin (optional)
#define SPI_FREQUENCY 27000000

auto tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void drawMenu();

void setup()
{
    tft.initR(INITR_BLACKTAB); // Initialize the display with the correct tab color
    tft.fillScreen(ST7735_BLACK); // Clear the screen
    tft.setTextColor(ST7735_WHITE); // Set text color to white
}

// Fix the typo: rifd_logo_bits should be rfid_logo_bits


#define MENU_HEIGHT 17

// Update the struct to use a pointer to unsigned char array
typedef struct
{
    const unsigned char* icon_bits; // Changed to pointer
    std::string name;
} MenuItem;

// Now the menu_items initialization will work
std::vector<MenuItem> menu_items = {
    {rfid_logo_bits, "RFID"},
    {wifi_logo_bits, "WiFi"},
    {ir_signal_logo_bits, "IR Signal"},
};

auto selected_menu_item = &menu_items[0];

void item(const MenuItem& menu_item);

#define MENU_ITEM_HEIGHT 25
#define MENU_ITEM_PADDING 7

int current_menu_item = 0;

void drawItem(const MenuItem& item)
{
    int16_t height = MENU_HEIGHT + (current_menu_item * MENU_ITEM_HEIGHT);

    if (selected_menu_item->name == item.name)
    {
        tft.fillRect(0, height, 128, 25, 0x88E3);
    }

    tft.drawBitmap(5, MENU_HEIGHT + (MENU_ITEM_PADDING / 2) + (MENU_ITEM_HEIGHT * current_menu_item), item.icon_bits,
                   19, 15, 0xFFFF);
    tft.setCursor(30, MENU_ITEM_PADDING + height);


    tft.print(item.name.c_str());

    current_menu_item++;
}

void drawMenu()
{
    tft.fillScreen(ST7735_BLACK);
    current_menu_item = 0;

    tft.drawRect(0, 0, 128, MENU_HEIGHT, 0xFFFF);
    tft.setCursor(6, 7);
    tft.print("MENU");

    tft.drawBitmap(112, 1, battery_indicator_icon_bits, 16, 16, 0x4D6A);

    for (const auto& menu_item : menu_items)
    {
        drawItem(menu_item);
    }
}


void loop(void)
{
    drawMenu();
    delay(1000);
}
