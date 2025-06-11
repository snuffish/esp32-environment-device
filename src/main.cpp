#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <vector>

#include "ESP32Encoder.h"
#include "icons.h"
#include "menu.h"
#include "OneButton.h"

#define ST7735_DRIVER
#define TFT_WIDTH 128
#define TFT_HEIGHT 160
#define ST7735_INITB
#define TFT_CS 5 // Chip select control pin
#define TFT_DC 2 // Data Command control pin
#define TFT_RST 4 // Reset pin (optional)
#define SPI_FREQUENCY 27000000

#define ENCODER_CLK 32
#define ENCODER_DT 33
#define ENCODER_BUTTON 25

std::vector<MenuItem> default_menu = {
    {rfid_logo_bits, "RFID"},
    {wifi_logo_bits, "WiFi"},
    {ir_signal_logo_bits, "IR Signal"},
};

std::vector<MenuItem> test_menu = {
    {rfid_logo_bits, "Test1"},
    {rfid_logo_bits, "Test2"},
    {rfid_logo_bits, "Test3"},
};

auto menu_items = default_menu;

auto tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
ESP32Encoder encoder;
OneButton button(ENCODER_BUTTON);

std::string menuTitle = "MENU";

void drawMenu();

void enterClick();

void longPress();

void setup()
{
    Serial.begin(9600);

    tft.initR(INITR_BLACKTAB); // Initialize the display with the correct tab color
    tft.fillScreen(ST7735_BLACK); // Clear the screen
    tft.setTextColor(ST7735_WHITE); // Set text color to white

    drawMenu();

    encoder.attachHalfQuad(ENCODER_CLK, ENCODER_DT);

    button.attachClick(enterClick);
    button.attachLongPressStart(longPress);
}

auto selected_menu_item = &menu_items[0];

void item(const MenuItem& menu_item);

int current_menu_item = 0;

void enterClick()
{
    Serial.println("ENTER CLICK");

    menuTitle = selected_menu_item->name;
    menu_items = test_menu;

    drawMenu();
};

void longPress()
{
    menuTitle = "MENU";
    menu_items = default_menu;

    drawMenu();
};

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
    tft.print(menuTitle.c_str());

    tft.drawBitmap(112, 1, battery_indicator_icon_bits, 16, 16, 0x4D6A);

    for (const auto& menu_item : menu_items)
    {
        drawItem(menu_item);
    }
}

void moveNext()
{
    Serial.println("MOVE NEXT");

    // Calculate the index of the current item
    size_t current_index = selected_menu_item - &menu_items[0];

    // Move to next item or wrap around
    current_index = (current_index + 1) % menu_items.size();
    selected_menu_item = &menu_items[current_index];

    drawMenu();
}

void movePrevious()
{
    Serial.println("MOVE PREVIOUS");

    // Calculate the index of the current item
    size_t current_index = selected_menu_item - &menu_items[0];

    // Move to previous item or wrap around
    if (current_index == 0) {
        current_index = menu_items.size() - 1; // Wrap to end
    } else {
        current_index--;
    }
    selected_menu_item = &menu_items[current_index];

    drawMenu();
}

auto last_position = 0;

void loop()
{
    button.tick();

    long newPosition = encoder.getCount() / 2;
    Serial.println(newPosition);

    if (newPosition > last_position)
    {
        moveNext();
    }
    else if (newPosition < last_position)
    {
        movePrevious();
    }

    last_position = newPosition;

    delay(10);
}
