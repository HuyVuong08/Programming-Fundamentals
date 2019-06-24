#include <iostream>
#include "Employee.h"

using namespace std;

class Process : public Employee
{
    public:
        Process (int _id, string _name, string _dataOfbirth) : Employee (_id, _name, _dataOfbirth) {}
        string GetName ()
        {
            return this -> name;
        }
};

