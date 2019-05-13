#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct EmployeeInfo 
{
    int ID, salary;
    string name, department;
};

struct DepartmentInfo 
{
    string name;
    int num = 0;
};

void PrintInfo (EmployeeInfo employee[], int i)
{
    cout << "ID: " << employee[i].ID << endl << "Name: " << employee[i].name << endl << "Salary: " << employee[i].salary << endl << "Department: "<< employee[i].department << endl;
}

void MaxSalary (EmployeeInfo employee[], int n)
{
    int max = employee[0].salary;
    int location = 0;

    for (int i = 0; i < n; i ++)
    {
        if (max < employee[i].salary)
        {
            max = employee[i].salary;
            location = i;
        }
            
    }
    
    cout << "Highest Salary Employee: \n";
    PrintInfo (employee, location);
    return;
}

void MinSalary (EmployeeInfo employee[], int n)
{
    int min = employee[0].salary;
    int location = 0;

    for (int i = 0; i < n; i ++)
    {
        if (min > employee[i].salary)
        {
            min = employee[i].salary;
            location = i;
        }
    }
    
    cout << "Lowest Salary Employee: \n";
    PrintInfo (employee, location);
    return;
}

void DepartmentClassifier (EmployeeInfo employee[], int n)
{
    DepartmentInfo department[n];

    department[0].name = employee[0].department;
    int size = 1;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < size; j ++)
        {
            if (employee[i].department == department[j].name)
            {
                department[j].num ++;
            }
                
            else 
                department[j].name = employee[i].department;
                size ++;
        }
    }

    
    return;
}

void BigestDepartment (DepartmentInfo department[], int n)
{
    int  max = department[0].num;
    int location = 0;
    for (int i = 0; i < n; i ++)
    {
        if (max < department[i].num)
        {
            max = department[i].num;
            location = i;
        }
    }


    cout << "Bigest Department: "<< department[location].name << ' ' << department[location].num << endl;
    return;
}

void input ()
{
    int size = 0, n = 0;
    
    cout << "How many employee you have?\n";
    cin >> size;
    n = size;
    EmployeeInfo employee[n];

    for (int i = 0; i < n; i ++)
    {
        employee[i].ID = i;
        employee[i].name = "abc";
        employee[i].salary = i;
        employee[i].department = "def";
    }

    MaxSalary (employee, n);
    MinSalary (employee, n);

    DepartmentInfo department[n];

    DepartmentClassifier (employee, n);
    BigestDepartment (department, n);
    return;
}


int main ()
{
    input ();  
    
    
    return 0;
}