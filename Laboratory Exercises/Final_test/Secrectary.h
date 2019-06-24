#include <iostream>
#include "Employee.h"

using namespace std;

class Secrectary : public Process
{
    private:
        int Bonus;
        int DaysOff;

    public:
        Secrectary (int _Bonus, int _DaysOff, int id, string name, string dateOfBirth): Bonus(_Bonus), DaysOff(_DaysOff), Process (id, name, dateOfBirth){}
        void SetBonus (int _Bonus);
        int GetBonus ();
        void SetDaysOff (int _DaysOff);
        int GetDaysOff ();
        int calculateSalary();
};

int Secrectary :: calculateSalary()
{
    int Salary = 3000000;
    Salary = Salary + GetBonus() - GetDaysOff()*100;
    return Salary;
}

void Secrectary :: SetBonus (int _Bonus)
{
    this -> Bonus = _Bonus;
}

int Secrectary :: GetBonus ()
{
    return this -> Bonus;
}

void Secrectary :: SetDaysOff (int _DaysOff)
{
    this -> DaysOff = _DaysOff;
}

int Secrectary :: GetDaysOff ()
{
    return this -> DaysOff;
}
