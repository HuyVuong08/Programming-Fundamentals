#include <iostream>
#include <fstream>

using namespace std;

int main(){

    string Data[2][9];

    ifstream ip("diabetes.csv");

    if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string Pregnancies;
    string Glucose;
    string BloodPressure;
    string SkinThickness;
    string Insulin;
    string BMI;
    string DiabetesPedigreeFunction;
    string Age;
    string Outcome;

    while(ip.good()){

        getline(ip,Pregnancies,',');
        getline(ip,Glucose,',');
        getline(ip,BloodPressure,',');
        getline(ip,SkinThickness,',');
        getline(ip,Insulin,',');
        getline(ip,BMI,',');
        getline(ip,DiabetesPedigreeFunction,',');
        getline(ip,Age,',');
        getline(ip,Outcome,'\n');

        for (int i = 0; i < 30; i ++)
        {
            for (int j = 0; i < 9; j ++)
            {
                if (j = 0)
                    Data[i][j] = Pregnancies;
                else if (j = 1)
                    Data[i][j] = Glucose;
                else if (j = 2)
                    Data[i][j] = BloodPressure;    
                else if (j = 3)
                    Data[i][j] = SkinThickness;    
                else if (j = 4)
                    Data[i][j] = Insulin;    
                else if (j = 5)
                    Data[i][j] = BMI;    
                else if (j = 6)
                    Data[i][j] = DiabetesPedigreeFunction;    
                else if (j = 7)
                    Data[i][j] = Age;  
                else if (j = 8)
                    Data[i][j] = Outcome;  
            }
        }

        for (int i = 0; i < 30; i ++)
        {
            for (int j = 0 ; j < 30; j ++)
            {
                if (j = 0)
                    cout << "Pregnancies: ";
                else if (j = 1)
                    cout << "Glucose: ";
                else if (j = 2)
                    cout << "BloodPressure: ";
                else if (j = 3)
                    cout << "SkinThickness: ";
                else if (j = 4)
                    cout << "Insulin: ";
                else if (j = 5)
                    cout << "BMI: ";
                else if (j = 6)
                    cout << "DiabetesPedigreeFunction: ";
                else if (j = 7)
                    cout << "Age: ";
                else if (j = 8)
                    cout << "Outcome: ";

                cout << Data[i][j] << '\n';
            }
            cout << "--------------------------------" << '\n';
        }

/*        
        cout << "Pregnancies: " << Pregnancies << '\n';
        cout << "Glucose: " << Glucose << '\n';
        cout << "BloodPressure: " << BloodPressure << '\n';
        cout << "SkinThickness: " << SkinThickness << '\n';
        cout << "Insulin: " << Insulin << '\n';
        cout << "BMI: " << BMI << '\n';
        cout << "DiabetesPedigreeFunction: " << DiabetesPedigreeFunction << '\n';
        cout << "Age: " << Age << '\n';
        cout << "Outcome: " << Outcome << '\n';
        cout << "--------------------------------" << '\n';
*/
    }
    ip.close();
}