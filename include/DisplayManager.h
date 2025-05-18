#ifndef OLEDMANAGER_H
#define OLEDMANAGER_H

#include "Adafruit_SSD1306.h"

class DisplayManager {
private:
    // Private constructor to prevent direct instantiation
    DisplayManager() = default;
    
    // Flag to track initialization status
    static bool initialized;
    
    // Display dimensions
    static constexpr uint8_t SCREEN_WIDTH = 128;
    static constexpr uint8_t SCREEN_HEIGHT = 64;
    static constexpr uint8_t OLED_ADDR = 0x3C;
    
    // Initialize the I2C bus and display
    static bool initializeI2C();

public:
    // Delete copy constructor and assignment operator
    DisplayManager(const DisplayManager&) = delete;
    DisplayManager& operator=(const DisplayManager&) = delete;
    
    // Get display instance (singleton implementation)
    static Adafruit_SSD1306& getDisplay();
    
    // Initialize the display - must be called once in setup()
    static bool initialize();
    
    // Clear display and reset text properties
    static void clearDisplay();
    
    // Check if display is initialized
    static bool isInitialized();
};

#endif //OLEDMANAGER_H