#include <iostream>
#include <string>
using namespace std;


class Animal {
public:
    virtual void makeSound() = 0;  
    virtual void move()      = 0;  
    virtual void display() {
        makeSound();
        move();
    }

    virtual ~Animal() {}
};

class Lion : public Animal {
public:
    void makeSound() override {
        cout << "Lion says  : Roarrr! " << endl;
    }
    void move() override {
        cout << "Lion moves : Runs on 4 legs across the savanna." << endl;
    }
};

class Fish : public Animal {
public:
    void makeSound() override {
        cout << "Fish says  : Blub blub! " << endl;
    }
    void move() override {
        cout << "Fish moves : Swims using fins in water." << endl;
    }
};

int main() {
    Animal* animals[4];
    animals[0] = new Lion();
    animals[1] = new Fish();
    animals[2] = new Lion();
    animals[3] = new Fish();

    cout << "=== Animal Polymorphism Demo ===" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "\nAnimal " << i+1 << ":" << endl;
        animals[i]->makeSound();
        animals[i]->move();
    }

    for (int i = 0; i < 2; i++) delete animals[i];
    return 0;
}
