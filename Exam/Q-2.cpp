#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int year;
    float speed;

public:
    void setModel(string m) {
        model = m;
    }

    void setYear(int y) {
        if (y > 1885)  
            year = y;
        else
            cout << "Invalid year!" << endl;
    }

    void setSpeed(float s) {
        if (s >= 0)
            speed = s;
        else
            cout << "Speed cannot be negative!" << endl;
    }

    string getModel() {
        return model;
    }

    int getYear() {
        return year;
    }

    float getSpeed() {
        return speed;
    }

    void display() {
        cout << "--------------------------" << endl;
        cout << "Model : " << model << endl;
        cout << "Year  : " << year  << endl;
        cout << "Speed : " << speed << " km/h" << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    Car car1;

    car1.setModel("Toyota Camry");
    car1.setYear(2022);
    car1.setSpeed(180.5);

    cout << "=== Car Details ===" << endl;
    car1.display();

    cout << "Accessing via Getters:" << endl;
    cout << "Model : " << car1.getModel() << endl;
    cout << "Year  : " << car1.getYear()  << endl;
    cout << "Speed : " << car1.getSpeed() << " km/h" << endl;

    cout << "\nTrying invalid values..." << endl;
    car1.setYear(1800);   
    car1.setSpeed(-50);   

    return 0;
}
