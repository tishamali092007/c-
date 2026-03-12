#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;

public:
    Student(string n, int roll) {
        name = n;
        rollNumber = roll;
    }

    void display() {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

int main() {
    Student students[] = {
        Student("Alice", 101),
        Student("Bob", 102),
        Student("Charlie", 103),
        Student("Diana", 104),
        Student("Eve", 105)
    };

    int size = sizeof(students) / sizeof(students[0]);

    cout << "=== Student Records ===" << endl;
    for (int i = 0; i < size; i++) {
        students[i].display();
    }

    return 0;
}
