#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void DisplayMenu()
{
    cout << "Hi There, please choose one of these options: \n1. Convert seconds to 12-hour clock time \n2. Exit \n";
    
}

void input (int & choice)
{
    DisplayMenu();
    
    string line;
    bool integer = false;

    cout << "Please select: \n";

    while (getline(cin, line))
    {
        stringstream ss(line);
        if (ss >> choice)
        {
            if (ss.eof())
            {
                if (choice >= 1 && choice <= 2)
                    break;
                else 
                {
                    DisplayMenu();
                    cout << "Please select a number from 1 to 2.\nPlease select: \n";
                    integer = true;
                }
            }
        }
        
        if (integer == false) 
        {
            DisplayMenu();
            cout << "Invalid input, please input an integer number.\nPlease select: \n";
        }   
    }
}

void DisplayConverter ()
{
    cout << "Welcom to Time-Converting Program!\n";
    return;
}

void InputConverter (int & second)
{
    DisplayConverter();
    
    string line;
    bool integer = false;

    cout << "Please input a number of seconds iin one day: \n";

    while (getline(cin, line))
    {
        stringstream ss(line);
        if (ss >> second)
        {
            if (ss.eof())
            {
                if (second >= 0 && second <= 86400)
                    break;
                else 
                {
                    DisplayConverter();
                    cout << "The mumber of seconds in one day ranges from 0 to 86400.\nPlease input a number of seconds in one day: \n";
                    integer = true;
                }
            }
        }
        
        if (integer == false) 
        {
            DisplayConverter();
            cout << "Invalid input, please input an integer number.\nPlease input a number of seconds in one day: \n";
        }   
    }
}

void PrintTime (int hour, int minute, int second, string DayOrNight)
{
    if (hour >= 10 && minute >= 10 && second >= 10)
        cout << hour << ':' << minute << ':' << second << ':' << DayOrNight << endl;
    else if (hour >= 10 && minute >= 10 && second < 10)
        cout << hour << ':' << minute << ":0" << second << ':' << DayOrNight << endl;
    else if (hour >= 10 && minute < 10 && second >= 10)
        cout << hour << ":0" << minute << ':' << second << ':' << DayOrNight << endl;
    else if (hour < 10 && minute >= 10 && second >= 10)
        cout << '0' << hour << ':' << minute << ':' << second << ':' << DayOrNight << endl;
    else if (hour >= 10 && minute < 10 && second < 10)
        cout << hour << ":0" << minute << ":0" << second << ':' << DayOrNight << endl;
    else if (hour < 10 && minute >= 10 && second < 10)
        cout << '0' << hour << ':' << minute << ":0" << second << ':' << DayOrNight << endl;
    else if (hour < 10 && minute < 10 && second >= 10)
        cout << '0' << hour << ":0" << minute << ':' << second << ':' << DayOrNight << endl;
    else if (hour < 10 && minute < 10 && second < 10)
        cout << '0' << hour << ":0" << minute << ":0" << second << ':' << DayOrNight << endl;
}

void Converter ()
{
    int hour = 0, minute = 0, second = 0;
    string DayOrNight = "AM";
    
    InputConverter (second);
     
    hour = second / 3600;
    
    minute = (second - hour * 3600) / 60;
    
    second = second - hour * 3600 - minute * 60;

    if (hour >= 12)
    {
        hour = hour - 12;
        DayOrNight = "PM";
    }

    PrintTime (hour, minute, second, DayOrNight);

    

    return;
}

void Exit ()
{
    cout << "Exiting ... ";
    return;
}

void select ()
{
    int choice = 0;
    
    input (choice);

    while (1)
    {
        if (choice == 1) 
        {
            Converter ();
            input (choice);
        } 
        else if (choice == 2)
        {
            Exit ();
            break;
        }
    }
    return;
}

int main ()
{
    select ();
    
    return 0;
}