#include <iostream>
#include <string>
using namespace std;

class Device {
private:
    string brand;
    float powerConsumption;
public:
    void setBrand(string b)           { brand = b; }
    void setPower(float p)            { powerConsumption = p; }
    string getBrand()                 { return brand; }
    float getPower()                  { return powerConsumption; }

    void displayInfo() {
        cout << "Brand            : " << brand << endl;
        cout << "Power Consumption: " << powerConsumption << "W" << endl;
    }
};

class Laptop : public Device {
private:
    float screenSize;
public:
    Laptop(string b, float p, float s) {
        setBrand(b);
        setPower(p);
        screenSize = s;
    }
    void displayInfo() {
        cout << "--- Laptop Info ---" << endl;
        Device::displayInfo();
        cout << "Screen Size      : " << screenSize << " inches" << endl;
    }
};

class Smartphone : public Device {
private:
    int batteryCapacity;
public:
    Smartphone(string b, float p, int bat) {
        setBrand(b);
        setPower(p);
        batteryCapacity = bat;
    }
    void displayInfo() {
        cout << "--- Smartphone Info ---" << endl;
        Device::displayInfo();
        cout << "Battery Capacity : " << batteryCapacity << " mAh" << endl;
    }
};

int main() {
    Laptop l("Dell", 65.0, 15.6);
    Smartphone s("Samsung", 18.0, 5000);

    l.displayInfo();
    cout << endl;
    s.displayInfo();
    return 0;
}
