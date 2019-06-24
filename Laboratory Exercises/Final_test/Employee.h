#include <iostream>

using namespace std;

class Employee 
{
    protected:
        int id;
        string name;
        string dateOfBirth; 
    public:
        Employee (int _id, string _name, string _dateOfbirth)
        {
            this -> id = _id;
            this -> name = _name;
            this -> dateOfBirth = _dateOfbirth;
        };

        void print ()
        {
            cout << "Employee's ID: " << this -> id << '\n';
            cout << "Name: " << this -> name << '\n';
            cout << "Date of Birth: " << this -> dateOfBirth << '\n';
            cout << "Salary: " << this -> calculateSalary() << "\n \n";
        };

        virtual int calculateSalary() = 0;
};

