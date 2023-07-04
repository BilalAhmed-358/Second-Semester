#include <iostream>
using namespace std;

class regional_office
{
public:
    string location;
    int number_of_staff_members;
    int vehicles_alloted;
    int number_of_departments;

    void Regional_office_info()
    {
        cout << "The office is located in " << location << "." << endl;
        cout << "The number of staff members in this regional office is " << number_of_staff_members << "." << endl;
        cout << vehicles_alloted << " vehicles have been alloted by the head office to this regional office" << endl;
        cout << "There are " << number_of_departments << " departments in this Regional office"
             << "." << endl;
    }
};

class Head_of_Regional_Office
{
public:
    string name;
    double salary;
    string Responsibilites; //would've made a sub-class of responsibilies and made an object of it here but since we haven't learned to do so hence just making a string attribute
    int number_of_subordinates;
    void HRO_info()
    {
        cout << "The name of the head of regional branch is " << name << "." << endl;
        cout << "His/Her salary is " << salary << "." << endl;
        cout << "His responsiblities are as follows:" << endl
             << Responsibilites << "." << endl;
        cout << number_of_subordinates << " people are working under him." << endl;
    }
};

class Staff_Member
{
public:
    string name;
    string designation;
    double salary;
    string address;
    int phone_nubmer;
};

class Office_Expenditure
{
public:
    int Electricity_bill;
    int Gas_bill;
    int Water_bill;
    int Municipality_tax;
    int Petrol_expenditure;
    int staff_salary_expenditure;
    void total_expenditure_of_the_regional_office(int Electricity_bill, int Gas_bill, int Water_bill, int Municipality_tax, int Petrol_expenditure, int staff_salary_expenditure)
    {
        double total;
        total = Electricity_bill + Gas_bill + Water_bill + Municipality_tax + Petrol_expenditure + staff_salary_expenditure;
        cout << "The total expenditure of this office is " << total << " Rupees per month." << endl;
    }
};

int main()
{
    regional_office Office_01;
    cout << "Enter the location of the office." << endl;
    cin >> Office_01.location;
    cout << "Enter the nubmer of staff members in the office." << endl;
    cin >> Office_01.number_of_staff_members;
    cout << "Enter the number of vehicles alloted by the head office to this regional office." << endl;
    cin >> Office_01.vehicles_alloted;
    cout << "Enter the number of departments in this regional office." << endl;
    cin >> Office_01.number_of_departments;
    Office_01.Regional_office_info();

    Head_of_Regional_Office HRO_01;
    cout << "Enter the name of the head of the regional office" << endl;
    cin >> HRO_01.name;
    cout << "Enter the salary of the HRO(Head of regional office)." << endl;
    cin >> HRO_01.salary;
    cout << "Enter the responsiblities of the HRO (Describe in a paragraph)." << endl;
    getline(cin, HRO_01.Responsibilites);
    cout << "Enter the number of subordinates working under the HRO." << endl;
    cin >> HRO_01.number_of_subordinates;
    HRO_01.HRO_info();

    Staff_Member staff_01;
    cout << "Enter the name of the staff member." << endl;
    cin >> staff_01.name;
    cout << "Enter the designation of the staff member." << endl;
    cin >> staff_01.designation;
    cout << "Enter the salary of the staff member." << endl;
    cin >> staff_01.salary;
    cout << "Enter the address of the staff member." << endl;
    getline(cin, staff_01.address);
    cout << "Enter the cell phone number of the staff member." << endl;
    cin >> staff_01.phone_nubmer;

    Office_Expenditure Expenditure_office_01;
    cout << "Enter the Electricity Bill of the office." << endl;
    cin >> Expenditure_office_01.Electricity_bill;
    cout << "Enter the Gas Bill of the office." << endl;
    cin >> Expenditure_office_01.Gas_bill;
    cout << "Enter the Water Bill of the office." << endl;
    cin >> Expenditure_office_01.Water_bill;
    cout << "Enter the municipality expenditure of the office." << endl;
    cin >> Expenditure_office_01.Municipality_tax;
    cout << "Enter the Petrol Expenditure of the office." << endl;
    cin >> Expenditure_office_01.Petrol_expenditure;
    cout << "Enter the total staff salary expenditure of the office." << endl;
    cin >> Expenditure_office_01.staff_salary_expenditure;
    Expenditure_office_01.total_expenditure_of_the_regional_office(Expenditure_office_01.Electricity_bill,Expenditure_office_01.Gas_bill,Expenditure_office_01.Water_bill,Expenditure_office_01.Municipality_tax,Expenditure_office_01.Petrol_expenditure,Expenditure_office_01.staff_salary_expenditure);
}