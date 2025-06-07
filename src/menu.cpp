//
// Created by Christoffer Engman on 2025-06-06.
//

#include "menu.h"

class Menu
{
private:
    Adafruit_ST7735* display;
public:
    explicit Menu
    
};

// Define the battery indicator icon bitmap (you'll need to replace this with your actual icon data)
const uint8_t Menu::battery_indicator_icon_bits[] = {
    // Add your 16x16 bitmap data here
    // This is just a placeholder - replace with your actual battery icon
    0x00, 0x00, 0x7F, 0xFE, 0x40, 0x02, 0x40, 0x02,
    0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02,
    0x40, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x02,
    0x40, 0x02, 0x7F, 0xFE, 0x00, 0x00, 0x00, 0x00
};

Menu::Menu(Adafruit_ST7735* tft): tft(*tft)
{
}

Menu::Menu(Adafruit_ST7735& tft) : tft(tft) {
    // Constructor implementation - direct reference assignment
}

void Menu::addMenuItem(const MenuItem& item) {
    menu_items.push_back(item);
}

void Menu::addMenuItem(const std::string& name, const uint8_t* icon) {
    menu_items.emplace_back(name, icon);
}

void Menu::setSelectedItem(int index) {
    if (index >= 0 && index < static_cast<int>(menu_items.size())) {
        selected_index = index;
    }
}

int Menu::getSelectedIndex() const {
    return selected_index;
}

void Menu::selectNext() {
    if (selected_index < static_cast<int>(menu_items.size()) - 1) {
        selected_index++;
    }
}

void Menu::selectPrevious() {
    if (selected_index > 0) {
        selected_index--;
    }
}

const MenuItem& Menu::getSelectedItem() const {
    return menu_items[selected_index];
}

void Menu::drawItem(const MenuItem& item, int item_index) const {
    auto y_position = MENU_HEIGHT + (item_index * MENU_ITEM_HEIGHT);

    // Highlight selected item
    if (item_index == selected_index) {
        tft.fillRect(0, y_position, DISPLAY_WIDTH, MENU_ITEM_WIDTH, COLOR_SELECTED);
    }

    // Draw icon
    tft.drawBitmap(
        ICON_X_OFFSET,
        MENU_HEIGHT + ICON_Y_OFFSET + (MENU_ITEM_HEIGHT * item_index),
        item.icon_bits,
        ICON_WIDTH,
        ICON_HEIGHT,
        COLOR_WHITE
    );

    // Draw text
    tft.setCursor(TEXT_X_OFFSET, MENU_ITEM_PADDING + y_position);
    tft.print(item.name.c_str());
}

void Menu::draw() const {
    // Draw menu header
    tft.drawRect(0, 0, DISPLAY_WIDTH, MENU_HEIGHT, COLOR_WHITE);
    tft.setCursor(MENU_TITLE_X, MENU_TITLE_Y);
    tft.print("MENU");

    // Draw battery indicator
    tft.drawBitmap(
        BATTERY_X_OFFSET,
        BATTERY_Y_OFFSET,
        battery_indicator_icon_bits,
        BATTERY_ICON_SIZE,
        BATTERY_ICON_SIZE,
        COLOR_BATTERY
    );

    // Draw menu items
    for (int i = 0; i < static_cast<int>(menu_items.size()); ++i) {
        drawItem(menu_items[i], i);
    }
}