#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

// Codes are in Global Cache format less the emitter ID and request ID.
// These codes can be found in GC's Control Tower database.

uint16_t Samsung_power_toggle[71] = {
    38000, 1, 1, 170, 170, 20, 63, 20, 63, 20, 63, 20, 20, 20, 20,
    20, 20, 20, 20, 20, 20, 20, 63, 20, 63, 20, 63, 20, 20, 20,
    20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 63, 20, 20, 20, 20,
    20, 20, 20, 20, 20, 20, 20, 20, 20, 63, 20, 20, 20, 63, 20,
    63, 20, 63, 20, 63, 20, 63, 20, 63, 20, 1798
};

#define IR_LED 4  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(IR_LED); // Set the GPIO to be used to sending the message.

void setup()
{
    irsend.begin();
    Serial.begin(9600);
}

void loop()
{
    // Send NEC code with UserCode 00EF and DataCode 04FB
    uint16_t userCode = 0x00EF;  // UserCode in hexadecimal
    uint16_t dataCode = 0x04FB;  // DataCode in hexadecimal
    uint32_t combinedCode = (userCode << 16) | dataCode;  // Combine into full 32-bit code

    Serial.println("Sending IR signal");
    irsend.sendNEC(combinedCode);
    Serial.println("Signal sent");
    delay(2000);  // Wait before sending again
}

// void loop()
// {
//     Serial.println("Toggling power");
// #if SEND_GLOBALCACHE
//     irsend.sendGC(Samsung_power_toggle, 71);
// #else   // SEND_GLOBALCACHE
//     Serial.println("Can't send because SEND_GLOBALCACHE has been disabled.");
// #endif  // SEND_GLOBALCACHE
//     delay(10000);
// }
