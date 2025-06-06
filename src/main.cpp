#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <vector>

#include "Fonts/Org_01.h"
#include "Fonts/Picopixel.h"

// Remove the FreeSansBold9pt7b include since ST7735 doesn't support GFX fonts
// #include <Fonts/FreeSansBold9pt7b.h>

#define ST7735_DRIVER
#define TFT_WIDTH 128
#define TFT_HEIGHT 160
#define ST7735_INITB
#define TFT_CS 5 // Chip select control pin
#define TFT_DC 2 // Data Command control pin
#define TFT_RST 4 // Reset pin (optional)
#define SPI_FREQUENCY 27000000

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup()
{
    tft.initR(INITR_BLACKTAB); // Initialize the display with the correct tab color
    tft.fillScreen(ST7735_BLACK); // Clear the screen
    tft.setTextColor(ST7735_WHITE); // Set text color to white
}

// Fix the typo: rifd_logo_bits should be rfid_logo_bits

static const unsigned char battery_indicator_icon_bits[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x10, 0x08, 0x32, 0xa8, 0x32, 0xa8, 0x10,
    0x08, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char rfid_logo_bits[] = {
    0x20, 0x02, 0x00, 0x40, 0x01, 0x00, 0x48, 0x09, 0x00, 0x90, 0x84, 0x80, 0xa5, 0xd2, 0x80, 0xa9, 0x4a, 0x80, 0xa5,
    0xd2, 0x80, 0x90, 0x84, 0x80, 0x48, 0x09, 0x00, 0x40, 0x01, 0x00, 0x20, 0x02, 0x00
};
static const unsigned char wifi_logo_bits[] = {
    0x01, 0xf0, 0x00, 0x06, 0x0c, 0x00, 0x18, 0x03, 0x00, 0x21, 0xf0, 0x80, 0x46, 0x0c, 0x40, 0x88, 0x02, 0x20, 0x10,
    0xe1, 0x00, 0x23, 0x18, 0x80, 0x04, 0x04, 0x00, 0x08, 0x42, 0x00, 0x01, 0xb0, 0x00, 0x02, 0x08, 0x00, 0x00, 0x40,
    0x00, 0x00, 0xa0, 0x00, 0x00, 0x40, 0x00
};;
static const unsigned char ir_signal_logo_bits[] = {
    0x07, 0xc0, 0x18, 0x30, 0x27, 0xc8, 0x48, 0x24, 0x93, 0x92, 0xa4, 0x4a, 0xa9, 0x2a, 0xa3, 0x8a, 0x06, 0xc0, 0x03,
    0x80, 0x01, 0x00, 0x03, 0x80, 0x02, 0x80, 0x06, 0xc0, 0x04, 0x40, 0x00, 0x00
};

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

void drawItem(MenuItem item)
{
    auto height = MENU_HEIGHT + (current_menu_item * MENU_ITEM_HEIGHT);

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
    tft.fillScreen(ST7735_BLACK);
    //
    drawMenu();
    delay(1000);
}

void draw(void)
{
    drawMenu();

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
