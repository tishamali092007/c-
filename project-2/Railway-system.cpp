#include <iostream>
#include <cstring>
using namespace std;

// ==================== Train Class ====================
class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    // Default Constructor
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    Train(int num, const char* name, const char* src, const char* dest, const char* time) {
        trainNumber = num;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    // -------- Getters --------
    int getTrainNumber()         const { return trainNumber; }
    const char* getTrainName()   const { return trainName; }
    const char* getSource()      const { return source; }
    const char* getDestination() const { return destination; }
    const char* getTrainTime()   const { return trainTime; }
    static int getTrainCount()         { return trainCount; }

    // -------- Setters --------
    void setTrainNumber(int num)          { trainNumber = num; }
    void setTrainName(const char* name)   { strcpy(trainName, name); }
    void setSource(const char* src)       { strcpy(source, src); }
    void setDestination(const char* dest) { strcpy(destination, dest); }
    void setTrainTime(const char* time)   { strcpy(trainTime, time); }

    // -------- Methods --------
    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();
        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);
        cout << "Enter Source: ";
        cin.getline(source, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails(int index) const {
        cout << "\nTrain " << index << " details:" << endl;
        cout << "Train Number : " << trainNumber << endl;
        cout << "Train Name   : " << trainName   << endl;
        cout << "Source       : " << source      << endl;
        cout << "Destination  : " << destination << endl;
        cout << "Train Time   : " << trainTime   << endl;
    }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() : totalTrains(0) {}

    void preLoadTrains() {
        trains[0].setTrainNumber(101);
        trains[0].setTrainName("Okha Express");
        trains[0].setSource("Surat");
        trains[0].setDestination("Mumbai");
        trains[0].setTrainTime("10 AM");

        trains[1].setTrainNumber(102);
        trains[1].setTrainName("Shatabdi Express");
        trains[1].setSource("Ahmedabad");
        trains[1].setDestination("Delhi");
        trains[1].setTrainTime("06 AM");

        trains[2].setTrainNumber(103);
        trains[2].setTrainName("Rajdhani Express");
        trains[2].setSource("Mumbai");
        trains[2].setDestination("Kolkata");
        trains[2].setTrainTime("08 PM");

        totalTrains = 3;
        cout << "3 initial train records pre-loaded successfully." << endl;
    }

    void addTrain() {
        if (totalTrains >= 100) {
            cout << "Maximum train records reached!" << endl;
            return;
        }
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
        cout << "Train record added successfully!" << endl;
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No train records found!" << endl;
            return;
        }
        cout << "\n========== All Train Records ==========" << endl;
        for (int i = 0; i < totalTrains; i++) {
            trains[i].displayTrainDetails(i + 1);
        }
        cout << "=======================================" << endl;
    }

    void searchTrainByNumber(int number) const {
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "\n--- Train Found ---";
                trains[i].displayTrainDetails(i + 1);
                return;
            }
        }
        cout << "Train with number " << number << " not found!" << endl;
    }
};

int main() {
    RailwaySystem system;
    system.preLoadTrains();

    int choice;

    do {
        cout << "\n--- Railway Reservation System Menu ---" << endl;
        cout << "1. Add New Train Record"      << endl;
        cout << "2. Display All Train Records" << endl;
        cout << "3. Search Train by Number"    << endl;
        cout << "4. Exit"                      << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addTrain();
                break;
            case 2:
                system.displayAllTrains();
                break;
            case 3: {
                int num;
                cout << "Enter Train Number to search: ";
                cin >> num;
                system.searchTrainByNumber(num);
                break;
            }
            case 4:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 4);

    cout << "\nTotal Train Objects (static trainCount): "
         << Train::getTrainCount() << endl;

    return 0;
}