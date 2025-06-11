#ifndef MENU_H
#define MENU_H

#define MENU_ITEM_HEIGHT 25
#define MENU_ITEM_PADDING 7

#define MENU_HEIGHT 17

typedef struct
{
    const unsigned char* icon_bits;
    std::string name;
} MenuItem;

#endif //MENU_H
