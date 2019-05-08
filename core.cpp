//
// Created by Nguyen Duc Dung on 2019-04-20.
//

#include "core.h"

using namespace std;

void PrintOutput(const char* pRequest, void* pData, void* &pOutput, int N) {
    cout << pRequest << ":";
    int*    pInt = (int*)pOutput;
    for (int i = 0; i < N; ++i) {
        cout << ' ' << *pInt++;
    }
    cout << '\n';
}

void Initialization() {
    // TODO: Please implement the initialization step if it is required
    //       for your program. You can ignore this one if you don't have
    //       anything to initialize.
}

void Finalization() {
    // TODO: Please implement this finalization step if you have to clean up
    //       the application before exiting. Please ignore if you don't have
    //       anything to do before exiting.
    // NOTE: Any data that you allocated MUST BE CLEAN UP
}

void LoadData(const char* pFName, void* &pData) {
    // TODO: Load the records from the given file. The name of data file
    //       is given in pFName. The data that you load into is pointed to
    //       by the pointer pData. You should make decision on what data
    //       type will be used to store records.
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

void ReleaseData(void* &pData) {
    // TODO: Release any data that you loaded. Please remember that there
    //       MUST BE NO MEMORY LEAK in this program.
}

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int& N) {
    // TODO: Please implement this function to process requests from client.
    //       The reuqest is given in form of a string pointed by pRequest.
    //       The data that you stored if pointed by pData.
    //       The output MUST BE STORED in the memory pointed by pOutput.
    //       N is the number of integers in the output.
}

void CountLine (const char* FileName, int & count)
{
    count = 0;
    string line;

    ifstream file(FileName);

    while (getline(file, line))
        count++;
    file.close();
}

