//
// Created by Nguyen Duc Dung on 2019-04-20.
//

#ifndef A02_CORE_H
#define A02_CORE_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cassert>

/// Prototype declaration
void Initialization();
void Finalization();

void LoadData(const char*, void* &);
void ReleaseData(void* &);

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &);
void PrintOutput(const char* pRequest, void* pData, void* &pOutput, int);

void RecordInitialize (struct Record& Data);

void CountLine (const char* FileName, int& count);
void ReadInfo (const char* pRequest, char* &CharOut, int Start, int& End);
void FindBracket (const char* CharIn, int Start, int& OpenPosition, int& ClosePosition);

bool CR (const char * pRequest);
bool DI (const char * pRequest, int& End);
bool HI (const char * pRequest, int& End);
bool FR (const char * pRequest);
bool FRLong (const char * pRequest, int& End);

void Mean (const float * array, const int size, float& result);
void StandardDeviation (const float * array, const int size, float& result);
void Min (const float * array, const int size, float& result);
void Max (const float * array, const int size, float& result);

void DIProcess (Record * Data, const char * Field1, const char * Field2, void* &pOutput, int& N);
void HIProcess (Record * Data, const char * Field1, const char * Field2, const char * Field3, const char * Field4, void* &pOutput, int& N);
void FRProcess (Record * Data, void* &pOutput, int& N);

void CountOutcome (const float * array, int size,  int& count);


struct Record {
    // TODO: Please define the detail struct for storing a record here
    int size = 0;
    float Pregnancies [999];
    float Glucose [999];
    float BloodPressure [999];
    float SkinThickness [999];
    float Insulin [999];
    float BMI [999];
    float DiabetesPedigreeFunction [999];
    float Age [999];
    float Outcome [999];
};

struct RecManager {
    // TODO: Please define the detail of this struct so that you can manage
    //       the records that you loaded from given the file. If you don't need
    //       such a struct, you can ignore or delete this one.
};

#endif //A02_CORE_H
