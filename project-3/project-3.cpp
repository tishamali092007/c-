#include <iostream>
#include <cstring>
using namespace std;

class Vehicle
{
protected:
    int id;
    char company[40];
    char model[40];
    int year;

public:
    static int total;

Vehicle()
{
    id = 0;
    strcpy(company,"");
    strcpy(model,"");
    year = 0;       
    total++;
}

Vehicle(int i,const char c[],const char m[],int y) {
    id=i;
    strcpy(company,c);
    strcpy(model,m);
    year=y;
    total++;
}

    virtual ~Vehicle()
 {
    total--;
}

int getID()
    {
        return id;
    }

virtual void input() {
    cout<<"Enter vehicle id: ";
    cin>>id;
    cin.ignore();

    cout<<"Enter company: ";
    cin.getline(company,40);

    cout<<"Enter model: ";
    cin.getline(model,40);

    cout<<"Enter year: ";
    cin>>year;
}

    virtual void show()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Company: "<<company<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;
    }
};

int Vehicle::total=0;

class Car : public Vehicle
{
protected:
    char fuel[20];

public:
    Car():Vehicle()
    {
        strcpy(fuel,"");
    }

Car(int i,const char c[],const char m[],int y,const char f[])
    :Vehicle(i,c,m,y)
{
    strcpy(fuel,f);
}

void input()
{
    Vehicle::input();
    cin.ignore();
    cout<<"Enter fuel type: ";
    cin.getline(fuel,20);
}

void show()
{
    Vehicle::show();
    cout<<"Fuel: "<<fuel<<endl;
    }
};


class ElectricCar : public Car
{
    float battery;

public:
    ElectricCar():Car()
    {
        battery=0;
    }

    void input()
    {
        Car::input();
        cout<<"Enter battery capacity: ";
        cin>>battery;
    }

    void show()
    {
        Car::show();
        cout<<"Battery: "<<battery<<" kWh"<<endl;
    }
};


class Aircraft
{
protected:
    float range;

public:
    Aircraft()
    {
        range=0;
    }

    void inputAircraft()
    {
        cout<<"Enter flight range: ";
        cin>>range;
    }

    void showAircraft()
    {
        cout<<"Flight range: "<<range<<" km"<<endl;
    }
};


class FlyingCar : public Car , public Aircraft
{
public:

    void input()
    {
        Car::input();
        inputAircraft();
    }

    void show()
    {
        Car::show();
        showAircraft();
    }
};


class SportsCar : public ElectricCar
{
    float speed;

public:
    SportsCar():ElectricCar()
    {
        speed=0;
    }

    void input()
    {
        ElectricCar::input();
        cout<<"Enter top speed: ";
        cin>>speed;
    }

    void show()
    {
        ElectricCar::show();
        cout<<"Top speed: "<<speed<<" km/h"<<endl;
    }
};


class Sedan : public Car
{
public:

    void input()
    {
        cout<<"Sedan details"<<endl;
        Car::input();
    }

    void show()
    {
        cout<<"Type: Sedan"<<endl;
        Car::show();
    }
};


class SUV : public Car
{
public:

    void input()
    {
        cout<<"SUV details"<<endl;
        Car::input();
    }

    void show()
    {
        cout<<"Type: SUV"<<endl;
        Car::show();
    }
};


class Registry
{
    Vehicle* list[100];
    int n;

public:
    Registry()
    {
        n=0;
    }

    void add(Vehicle* v)
    {
        if(n<100)
        {
            list[n]=v;
            n++;
            cout<<"Vehicle added"<<endl;
        }
        else
        {
            cout<<"Registry full"<<endl;
        }
    }

    void display()
    {
        if(n==0)
        {
            cout<<"No vehicles"<<endl;
            return;
        }

        for(int i=0;i<n;i++)
        {
            cout<<"\nVehicle "<<i+1<<endl;
            list[i]->show();
        }
    }

    void search(int id)
    {
        for(int i=0;i<n;i++)
        {
            if(list[i]->getID()==id)
            {
                cout<<"Found vehicle"<<endl;
                list[i]->show();
                return;
            }
        }

        cout<<"Vehicle not found"<<endl;
    }

    ~Registry()
    {
        for(int i=0;i<n;i++)
            delete list[i];
    }
};



int main()
{
    Registry r;
    int ch;

    while(true)
    {
        cout<<"\n1 Add vehicle";
        cout<<"\n2 Show vehicles";
        cout<<"\n3 Search";
        cout<<"\n4 Exit";
        cout<<"\nEnter choice: ";
        cin>>ch;

        if(ch==1)
        {
            cout<<"\n1 Car";
            cout<<"\n2 Electric Car";
            cout<<"\n3 Flying Car";
            cout<<"\n4 Sports Car";
            cout<<"\n5 Sedan";
            cout<<"\n6 SUV";
            cout<<"\nEnter type: ";

            int t;
            cin>>t;

            Vehicle* v=0;

            if(t==1) v=new Car();
            else if(t==2) v=new ElectricCar();
            else if(t==3) v=new FlyingCar();
            else if(t==4) v=new SportsCar();
            else if(t==5) v=new Sedan();
            else if(t==6) v=new SUV();

            if(v!=0)
            {
                v->input();
                r.add(v);
            }
        }

        else if(ch==2)
        {
            r.display();
        }

        else if(ch==3)
        {
            int id;
            cout<<"Enter id: ";
            cin>>id;
            r.search(id);
        }

        else if(ch==4)
        {
            break;
        }

        else
        {
            cout<<"Wrong choice"<<endl;
        }
    }

    return 0;
}