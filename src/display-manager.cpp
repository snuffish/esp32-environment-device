#ifndef SINGLETON_H
#define SINGLETON_H

class DisplayManager {
public:
    // Delete copy constructor and assignment operator
    DisplayManager(const DisplayManager&) = delete;
    DisplayManager& operator=(const DisplayManager&) = delete;
    
    // Get the singleton instancke
    static DisplayManager& getInstance() {
        // Guaranteed to be initialized only once (C++11)
        static DisplayManager instance;
        return instance;
    }
    
    // Example method
    void doSomething() {
        // Implementation
    }

private:
    // Private constructor to prevent direct instantiation
    DisplayManager() {
        // Initialization code
    }
    
    // Private destructor
    ~DisplayManager() {
        // Cleanup code
    }
};

#endif // SINGLETON_H