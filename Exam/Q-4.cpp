#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string brand;
    float price;
public:
    Device(string b, float p) : brand(b), price(p) {}

    virtual void calculateDiscount() {
        cout << "Base discount: 5%" << endl;
    }

    virtual void displayInfo() {
        cout << "Brand: " << brand << ", Price: Rs." << price << endl;
    }

    virtual ~Device() {}
};

class Laptop : public Device {
public:
    Laptop(string b, float p) : Device(b, p) {}

    void calculateDiscount() override {
        float discount = price * 0.10;  
        cout << "Laptop [" << brand << "] - 10% Discount = Rs." 
             << discount << ", Final Price = Rs." << (price - discount) << endl;
    }
};

class Smartphone : public Device {
public:
    Smartphone(string b, float p) : Device(b, p) {}

    void calculateDiscount() override {
        float discount = price * 0.15; 
        cout << "Smartphone [" << brand << "] - 15% Discount = Rs." 
             << discount << ", Final Price = Rs." << (price - discount) << endl;
    }
};

int main() {
    Device* devices[4];
    devices[0] = new Laptop("Dell", 80000);
    devices[1] = new Laptop("HP", 65000);
    devices[2] = new Smartphone("Samsung", 40000);
    devices[3] = new Smartphone("OnePlus", 35000);

    cout << "=== Discount Calculation (Polymorphism) ===" << endl;
    for (int i = 0; i < 4; i++) {
        devices[i]->calculateDiscount();
    }

    for (int i = 0; i < 4; i++) delete devices[i];
    return 0;
}
