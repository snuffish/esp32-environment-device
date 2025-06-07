//
// Created by Christoffer Engman on 2025-06-06.
//

#ifndef MENU_H
#define MENU_H

#include "Adafruit_ST7735.h"
#include <vector>
#include <string>

struct MenuItem {
    std::string name;
    const uint8_t* icon_bits;
    
    MenuItem(const std::string& n, const uint8_t* icon) : name(n), icon_bits(icon) {}
};

class Menu {
private:
    Adafruit_ST7735& tft;
    
public:
    Menu(Adafruit_ST7735& tft);  // Constructor takes reference
    
private:
    std::vector<MenuItem> menu_items;
    
    // Menu layout constants
    static constexpr int MENU_HEIGHT = 20;
    static constexpr int MENU_ITEM_HEIGHT = 25;
    static constexpr int MENU_ITEM_PADDING = 7;
    static constexpr int DISPLAY_WIDTH = 128;
    static constexpr int MENU_ITEM_WIDTH = 25;
    static constexpr int ICON_X_OFFSET = 5;
    static constexpr int ICON_Y_OFFSET = MENU_ITEM_PADDING / 2;
    static constexpr int ICON_WIDTH = 19;
    static constexpr int ICON_HEIGHT = 15;
    static constexpr int TEXT_X_OFFSET = 30;
    static constexpr int BATTERY_X_OFFSET = 112;
    static constexpr int BATTERY_Y_OFFSET = 1;
    static constexpr int BATTERY_ICON_SIZE = 16;
    static constexpr int MENU_TITLE_X = 6;
    static constexpr int MENU_TITLE_Y = 7;
    
    // Colors
    static constexpr uint16_t COLOR_WHITE = 0xFFFF;
    static constexpr uint16_t COLOR_SELECTED = 0x88E3;
    static constexpr uint16_t COLOR_BATTERY = 0x4D6A;
    
    // Battery icon data (you'll need to define this based on your icon)
    static const uint8_t battery_indicator_icon_bits[];
    
    int selected_index = 0;

public:
    

    // Add menu items
    void addMenuItem(const MenuItem& item);
    void addMenuItem(const std::string& name, const uint8_t* icon);

    void setSelectedItem(int index);
    int getSelectedIndex() const;
    void selectNext();
    void selectPrevious();
    const MenuItem& getSelectedItem() const;
    void draw() const;

private:
    void drawItem(const MenuItem& item, int item_index) const;
};

#endif // MENU_H