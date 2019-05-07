#include <iostream>
#include <fstream>

using namespace std;


/*
struct Record {
    // TODO: Please define the detail struct for storing a record here
    int count = 0;
    float * pData = new float[count][9];
    
};

void LoadData(const char*, void* &)
{

}
*/
int main(){

    int i = 0;
    float Data[2][9];    

    ifstream ip("diabetes.csv");

    if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string Pregnancies_string;
    string Glucose_string;
    string BloodPressure_string;
    string SkinThickness_string;
    string Insulin_string;
    string BMI_string;
    string DiabetesPedigreeFunction_string;
    string Age_string;
    string Outcome_string;

    while(ip.good()){

        getline(ip,Pregnancies_string,',');
        getline(ip,Glucose_string,',');
        getline(ip,BloodPressure_string,',');
        getline(ip,SkinThickness_string,',');
        getline(ip,Insulin_string,',');
        getline(ip,BMI_string,',');
        getline(ip,DiabetesPedigreeFunction_string,',');
        getline(ip,Age_string,',');
        getline(ip,Outcome_string,'\n');

        float Pregnancies_float = stof(Pregnancies_string);
        float Glucose_float = stof(Glucose_string);
        float BloodPressure_float = stof(BloodPressure_string);
        float SkinThickness_float = stof(SkinThickness_string);
        float Insulin_float = stof(Insulin_string);
        float BMI_float = stof(BMI_string);
        float DiabetesPedigreeFunction_float = stof(DiabetesPedigreeFunction_string);
        float Age_float = stof(Age_string);
        float Outcome_float = stof(Outcome_string);

        Data[i][0] = Pregnancies_float;
        Data[i][1] = Glucose_float;
        Data[i][2] = BloodPressure_float;    
        Data[i][3] = SkinThickness_float;    
        Data[i][4] = Insulin_float;    
        Data[i][5] = BMI_float;    
        Data[i][6] = DiabetesPedigreeFunction_float;    
        Data[i][7] = Age_float;  
        Data[i][8] = Outcome_float;  
        
        i ++;
    }
/*
    for (int i = 0; i < 2; i ++)
    {
        for (int j = 0 ; j < 9; j ++)
        {
            if (j = 0)
                cout << "Pregnancies: " << Data[i][j];
            else if (j = 1)
                cout << "Glucose: " << Data[i][j];
            else if (j = 2)
                cout << "BloodPressure: " << Data[i][j];
            else if (j = 3)
                cout << "SkinThickness: " << Data[i][j];
            else if (j = 4)
                cout << "Insulin: " << Data[i][j];
            else if (j = 5)
                cout << "BMI: " << Data[i][j];
            else if (j = 6)
                cout << "DiabetesPedigreeFunction: " << Data[i][j];
            else if (j = 7)
                cout << "Age: " << Data[i][j];
            else if (j = 8)
                cout << "Outcome: " << Data[i][j];

            cout << Data[i][j] << '\n';
        }
        cout << "--------------------------------" << '\n';
    }
*/
    ip.close();

    cout << Data[1][1];
}