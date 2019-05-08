#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

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


int main () 
{
    LoadConfiguration ();
    return 0;
}
