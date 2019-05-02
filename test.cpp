#include <iostream>
#include <fstream>

using namespace std;

int main(){

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
  }

  ip.close();
}