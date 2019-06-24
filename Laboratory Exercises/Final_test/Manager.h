#include <iostream>
#include "Employee.h"

using namespace std;

class Manager : public Process
{
    private:
        int Bonus;
        
    public:
        Manager (int _Bonus, int id, string name, string dateOfBirth):Bonus(_Bonus), Process (id, name, dateOfBirth)
        {
            this -> Bonus = _Bonus;
        }
        void SetBonus (int _Bonus);
        int GetBonus ();
        int calculateSalary();

};

int Manager :: calculateSalary()
{
    int Salary = 3000000;
    Salary = Salary + GetBonus();
    return Salary;
}

void Manager :: SetBonus (int _Bonus)
{
    this -> Bonus = _Bonus;
}

int Manager :: GetBonus ()
{
    return this -> Bonus;
}
