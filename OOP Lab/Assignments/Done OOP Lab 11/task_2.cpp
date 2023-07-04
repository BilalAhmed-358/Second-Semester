#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

class Vehicle
{
public:
    string type_of_car;
    string make;
    string model;
    string Color;
    string Year;
    float miles_driven;
    Vehicle(string make, string model, string Color, string Year, float miles_driven)
    {
        cout << "Enter the type of car(SUV/4x4 or any other)\n";
        fflush(stdin);
        cin >> type_of_car;
        // cout<<type_of_car<<endl;
        // this->type_of_car = type_of_car;
        this->make = make;
        this->model = model;
        this->Color = Color;
        this->Year = Year;
        this->miles_driven = miles_driven;
    }
};

class GasVehicle : virtual public Vehicle
{
public:
    float fuel_tank_size;
    GasVehicle(float fuel_tank_size, string make, string model, string Color, string Year, float miles_driven) : Vehicle(make, model, Color, Year, miles_driven)
    {
        this->fuel_tank_size = fuel_tank_size;
    }
};

class ElectricVehicle : virtual public Vehicle

{
public:
    float Energy_storage;
    ElectricVehicle(float Energy_storage, string make, string model, string Color, string Year, float miles_driven) : Vehicle(make, model, Color, Year, miles_driven)
    {
        this->Energy_storage = Energy_storage;
    }
};

class HighPerformance : virtual public GasVehicle
{
public:
    float horse_power;
    float top_speed;
    HighPerformance(float horse_power, float top_speed, float fuel_tank_size, string make, string model, string Color, string Year, float miles_driven) : GasVehicle(fuel_tank_size, make, model, Color, Year, miles_driven), Vehicle(make, model, Color, Year, miles_driven)
    {
        this->horse_power = horse_power;
        this->top_speed = top_speed;
    }
};

class HeavyVehicle : virtual public GasVehicle, virtual public ElectricVehicle
{
public:
    float maximum_weight;
    int number_of_wheels;
    float length;
    HeavyVehicle(float maximum_weight, int number_of_wheels, float length, float Energy_storage, float fuel_tank_size, string make, string model, string Color, string Year, float miles_driven) : GasVehicle(fuel_tank_size, make, model, Color, Year, miles_driven), ElectricVehicle(Energy_storage, make, model, Color, Year, miles_driven), Vehicle(make, model, Color, Year, miles_driven)
    {
        this->maximum_weight = maximum_weight;
        this->number_of_wheels = number_of_wheels;
        this->length = length;
    }
};

class SportsCar : public HighPerformance
{
public:
    string gearbox;
    string drive_system;
    SportsCar(float horse_power, float top_speed, float fuel_tank_size, string make, string model, string Color, string Year, float miles_driven) : HighPerformance(horse_power, top_speed, fuel_tank_size, make, model, Color, Year, miles_driven), GasVehicle(fuel_tank_size, make, model, Color, Year, miles_driven), Vehicle(make, model, Color, Year, miles_driven)
    {
        cout << "Enter the type of the gearbox you want in the car (Automatic/Manual)\n";
        cin >> gearbox;
        cout << "Enter the kind of driving system you want in the car (Rearwheel/frontwheel/4x4)\n";
        cin >> drive_system;
    }
};

class Construction_Truck : public HeavyVehicle
{
public:
    string cargo;
    Construction_Truck(float maximum_weight, int number_of_wheels, float length, float Energy_storage, float fuel_tank_size, string make, string model, string Color, string Year, float miles_driven) : HeavyVehicle(maximum_weight, number_of_wheels, length, Energy_storage, fuel_tank_size, make, model, Color, Year, miles_driven), GasVehicle(fuel_tank_size, make, model, Color, Year, miles_driven), ElectricVehicle(Energy_storage, make, model, Color, Year, miles_driven), Vehicle(make, model, Color, Year, miles_driven)
    {
        cout << "Enter the kind of cargo this construction truch will carry (Cement/Gravel/Sand)\n";
        cin >> cargo;
    }
};

class Bus : public HeavyVehicle
{
public:
    int number_of_seats;
    Bus(int number_of_seats, float maximum_weight, int number_of_wheels, float length, float Energy_storage, float fuel_tank_size, string make, string model, string Color, string Year, float miles_driven) : HeavyVehicle(maximum_weight, number_of_wheels, length, Energy_storage, fuel_tank_size, make, model, Color, Year, miles_driven), GasVehicle(fuel_tank_size, make, model, Color, Year, miles_driven), ElectricVehicle(Energy_storage, make, model, Color, Year, miles_driven), Vehicle(make, model, Color, Year, miles_driven)
    {
        this->number_of_seats = number_of_seats;
    }
    void Display()
    {
        cout << "The kind of vehicle is " << type_of_car << " .\n";
        cout << "The model of the vehicle is " << model << " .\n";
        cout << "The color of the vehicle is " << Color << " .\n";
        cout << "The vehicle is in use since " << Year << " .\n";
        cout << "The vehicles has been driven " << miles_driven << " miles.\n";
        cout << "The Energy Storage of the vehicle is " << Energy_storage << " Watts.\n";
        cout << "The fuel tank size of the vehicle is " << fuel_tank_size << " ltrs.\n";
        cout << "The maximum weight of the vehicle is " << maximum_weight << " kgs.\n";
        cout << "The number of wheels in the vehicle is " << number_of_wheels << " .\n";
        cout << "The length fo the vehicle is " << length << " .\n";
        cout << "The number of seats in the bus is " << number_of_seats << " .\n";
    }
};

int main()
{
    Bus bus1(25, 10000, 8, 40, 10000, 1000, "Aluminium", "2019-S", "Yellow", "2019", 1000);
    bus1.Display();
}