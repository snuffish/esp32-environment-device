#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
protected:
    explicit Singleton(const Adafruit_SSD1306& value);

    static Singleton* singleton_;

    Adafruit_SSD1306 value_;

public:
    Singleton(Singleton& other) = delete;

    void operator=(const Singleton&) = delete;

    static Singleton* GetInstance(const Adafruit_SSD1306& value);

    Adafruit_SSD1306& value()
    {
        return value_;
    }
};

Singleton* Singleton::singleton_ = nullptr;

inline Singleton::Singleton(const Adafruit_SSD1306& value): value_(value)
{
    // Initialize display settings
    value_.clearDisplay();
    value_.setTextSize(1);
    value_.setTextColor(SSD1306_WHITE);
    value_.setCursor(0, 0);
}

inline Singleton* Singleton::GetInstance(const Adafruit_SSD1306& value)
{
    if (singleton_ == nullptr)
    {
        singleton_ = new Singleton(value);
    }

    return singleton_;
}

#endif //SINGLETON_H