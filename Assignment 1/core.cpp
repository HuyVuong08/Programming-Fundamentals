//
// Created by Nguyen Duc Dung on 2019-02-15.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

/// Prototype declaration
void Initialization();
void Finalization();

void LoadConfiguration();
void LoadMenu();
void DisplayMenu();
void ProcessUserChoice();
int LoadIntroTime ();
void Introduction ();
void Login ();
void Registration ();
void Help ();
void Exit ();
void input (int & choice);
///--------------------------------------------------------------------
bool __coreInitialized = false;  /// an example of global variable
int  __userChoice;               /// a global variable to store user choice
bool __isExiting = false;        /// this variable should be turn on when the program exits
string menu[5];
// TODO: add more global variables to complete tasks

///--------------------------------------------------------------------
/**
 * Function: Initialization
 * Purpose:  Initialize anything necessary in your program before starting
 * Input:    None
 * Output:   None
 */
void Initialization() 
{
    LoadConfiguration();
    LoadMenu();
    // TODO: write the code to initialize the program
    __coreInitialized = true;

    LoadConfiguration();
    LoadMenu();    

    int intro = 0;
    intro = LoadIntroTime();
    usleep (intro*1000);
}

/**
 * Function: Finalization
 * Purpose:  Clean up everything before the program exits
 * Input:    None
 * Output:   None
 */
void Finalization () 
{
    // TODO: write the code to clean up when the program exits
    return;
}

void LoadConfiguration () 
{
    // TODO: write code to load data from the configuration file
    string conf;
    char c;
    ifstream conf_file ("conf.json", ifstream::in);

    if (conf_file) cout << "File opened\n";
    
    while (getline (conf_file, conf) && conf != "  \"WelcomeText\": {"){}

    while (1)
    {
        conf_file >> conf;
        
        if (conf == "\"line1\":" || 
            conf == "\"line2\":" || 
            conf == "\"line3\":" || 
            conf == "\"line4\":" || 
            conf == "\"line5\":" || 
            conf == "\"line6\":" || 
            conf == "\"line7\":" || 
            conf == "\"line8\":" || 
            conf == "\"line9\":") 
        {
            while (1)
            {
                char prev = c;
                conf_file.get(c);
                if (c == ',' && prev == '"') break;    
                if (c != '"' && c != '}') cout << c;
            }
            
            cout << endl;
        }

        if (conf == "},")
            break;
    } 

    conf_file.close();

    cout << "File closed\n";
}

void LoadMenu () 
{
    // TODO: write code to load menu from the configuration file
    
    string conf, str;
    char c;
    int i = 0;
    ifstream conf_file ("conf.json", ifstream::in);

    if (conf_file) cout << "File opened\n";
    
    while (getline (conf_file, conf) && conf != "  \"Menu\": {"){}

    while (1)
    {
        conf_file >> conf;
        
        if (conf == "\"opt1\":" || conf == "\"opt2\":" || conf == "\"opt3\":" || conf == "\"opt4\":" || conf == "\"opt5\":") 
        {
            while (1)
            {
                conf_file.get(c);
                if (c == ',') break;    
                if (c != '"' && c != '}' && c !=' ' && c != '\n') str.insert(str.end(), c);
            }
            menu[i] = str;
            i ++;
            str = "";
        }

        if (conf == "\"IntroTime\":")
            break;
    } 

    conf_file.close();

    cout << "File closed\n";
}

void ProcessUserChoice () {
    // TODO: Read user input and process
    
    int choice = 0;
    input (choice);
    
    while (1)
    {
            if (choice == 1) 
        {
            Introduction ();
            input (choice);
        } 
        else if (choice == 2)
        {
            Login();
            input (choice);
        }
        else if (choice == 3)
        {
            Registration ();
            input (choice);
        }
        else if (choice == 4)
        {
            Help ();
            input (choice);
        }
        else if (choice == 5)
        {
            Exit ();
            break;
        }
    }
}

void Introduction ()
{
    cout << "You select menu item 1. Processing . . . Done!\n";
}

void Login ()
{
    string inName, inPassword, password, name;
    
    ifstream f("registration.txt");
    
    if (!f.is_open())
    {
        cout<<"could not open file\n";
        return;
    }

    getline(f, name, '\n');
    getline(f, password, '\n');
    f.close();

    while (1)
    {
        cout << "Enter Username: ";
        getline(cin, inName);
        cout << "Enter Password: ";
        getline(cin, inPassword);
        
        if (inName == name && inPassword == password)
        {
            cout<<"Login Successful\n" << "Welcome, " << inName << "!\n";
            break;
        }
        cout << "incorrect name or password\n";
    }
}

void Registration ()
{
    string registerName, registerPassword;

    ofstream g("registration.txt");
    
    if (!g.is_open())
    {
        cout << "could not open file\n";
        return;
    }

    cout << "\n\n\n" << "New Username: ";
    getline(cin, registerName);
    cout << "New Password: ";
    getline(cin, registerPassword);
    g << registerName;
    g << '\n';
    g << registerPassword;
    g.close();
}

void Help ()
{
    cout << "You select menu item 4. Processing . . . Done!\n";
}

void Exit ()
{
    cout << "Exiting . . .\n";
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
                if (choice >= 1 && choice <= 5)
                    break;
                else 
                {
                    DisplayMenu();
                    cout << "Please select a number from 1 to 5.\nPlease select: \n";
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

int LoadIntroTime ()
{
    string conf;
    char c;
    int num = 0;
    ifstream conf_file ("conf.json", ifstream::in);

    if (conf_file) cout << "File opened\n";
    
    while (conf_file >> conf && conf != "\"IntroTime\":"){}

    while (conf_file.get(c)) 
    {
        if (c >= '0' && c <= '9')
            num += num * 10 + (c-'0');
    }

    conf_file.close();
    cout << "File closed\n";

    return num;
}
