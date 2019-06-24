#include <iostream>
#include "Employee.h"

using namespace std;

class Sales : public Process
{
    private:
        int TotalAmountOfSales;

    public:
        Sales (int _TotalAmountOfSales, int id, string name, string dateOfBirth):TotalAmountOfSales(_TotalAmountOfSales), Process (id, name, dateOfBirth)
        {
            this -> TotalAmountOfSales = _TotalAmountOfSales;
        }
        void SetTotalAmoutOfSalses (int _TotalAmountOfSales);
        int GetTotalAmountOfSales ();
        int calculateSalary();
};

int Sales :: calculateSalary()
{
    int Salary = 2000000;
    Salary = Salary + GetTotalAmountOfSales()*0.1;
    return Salary;
}

void Sales :: SetTotalAmoutOfSalses (int _TotalAmountOfSales)
{
    this -> TotalAmountOfSales = _TotalAmountOfSales;
}

int Sales :: GetTotalAmountOfSales ()
{
    return this -> TotalAmountOfSales;
}
