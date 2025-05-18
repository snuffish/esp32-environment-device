#include <Wire.h>
#include "DisplayManager.h"

// Define the static member variable
bool DisplayManager::initialized = false;

// Private method implementation
bool DisplayManager::initializeI2C() {
    // Initialize Wire if not already done
    // Wire.begin();
    
    // Give Wire some time to initialize
    delay(50);
    
    // Initialize the display instance
    auto& display = getDisplay();
    
    // Initialize display with appropriate parameters
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println("SSD1306 allocation failed");
        return false;
    }
    
    // Initial display setup
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.display();
    
    return true;
}

Adafruit_SSD1306& DisplayManager::getDisplay() {
    static Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
    return display;
}

bool DisplayManager::initialize() {
    if (!initialized) {
        initialized = initializeI2C();
    }
    return initialized;
}

void DisplayManager::clearDisplay() {
    if (!initialized) {
        Serial.println("WARNING: Display not initialized. Call DisplayManager::initialize() first.");
        return;
    }
    
    auto& display = getDisplay();
    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
}

bool DisplayManager::isInitialized() {
    return initialized;
}