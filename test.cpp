#include <iostream>
#include <fstream>

using namespace std;



struct Record {
    // TODO: Please define the detail struct for storing a record here
    float Pregnancies [999];
    float Glucose [999];
    float BloodPressure [999];
    float SkinThickness [999];
    float Insulin [999];
    float BMI [999];
    float DiabetesPedigreeFunction [999];
    float Age [999];
    float Outcome [999];
    int count = 0;
};

void CountLine (const char* FileName, int & count)
{
    count = 0;
    string line;

    ifstream file(FileName);

    while (getline(file, line))
        count++;
    file.close();
}

void LoadData(const char* pFName, void* & pData)
{
    int i = 0, count = 0;

    CountLine (pFName, count);
    Record Data;
    Data.count = count;

    ifstream ip(pFName);

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

        Data.Pregnancies[i] = Pregnancies_float;
        Data.Glucose[i] = Glucose_float;
        Data.BloodPressure[i] = BloodPressure_float;    
        Data.SkinThickness[i] = SkinThickness_float;    
        Data.Insulin[i] = Insulin_float;    
        Data.BMI[i] = BMI_float;    
        Data.DiabetesPedigreeFunction[i] = DiabetesPedigreeFunction_float;    
        Data.Age[i] = Age_float;  
        Data.Outcome[i] = Outcome_float;  
        
        i ++;
    }
    ip.close();
    pData = &Data;
}

int main(){
    void * pData;

    LoadData ("diabetes.csv", pData); 
    Record * a;
    a = (struct Record *) pData; 
    cout << (*a).Glucose[1];

    return 0;
}