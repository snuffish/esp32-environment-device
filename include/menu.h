#ifndef MENU_H
#define MENU_H

#define MENU_ITEM_HEIGHT 25
#define MENU_ITEM_PADDING 7

#define MENU_HEIGHT 17
#include "icons.h"

typedef struct
{
    uint8_t id;
    const unsigned char* icon_bits;
    std::string name;
} MenuItem;

static const std::vector<MenuItem> menu_items = {
    {1, rfid_logo_bits, "RFID"},
    {2, wifi_logo_bits, "WiFi"},
    {3, ir_signal_logo_bits, "IR Signal"},
};

#endif //MENU_H
