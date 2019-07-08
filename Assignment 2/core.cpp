//
// Created by Nguyen Duc Dung on 2019-04-20.
//

#include "core.h"

using namespace std;

void PrintOutput(const char* pRequest, void* pData, void* &pOutput, int N) 
{
    cout << pRequest << ":";
    int*    pInt = (int*)pOutput;
    for (int i = 0; i < N; ++i) {
        cout << ' ' << *pInt++;
    }
    cout << '\n';
}

void Initialization() 
{
    // TODO: Please implement the initialization step if it is required
    //       for your program. You can ignore this one if you don't have
    //       anything to initialize.
}

void Finalization() 
{
    // TODO: Please implement this finalization step if you have to clean up
    //       the application before exiting. Please ignore if you don't have
    //       anything to do before exiting.
    // NOTE: Any data that you allocated MUST BE CLEAN UP
}

void LoadData(const char* pFName, void* &pData) 
{
    // TODO: Load the records from the given file. The name of data file
    //       is given in pFName. The data that you load into is pointed to
    //       by the pointer pData. You should make decision on what data
    //       type will be used to store records.
    int i = 0, count = 0;

    CountLine (pFName, count);
    Record Data;
    Data.size = count;

    RecordInitialize (Data);

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
    return;
}

void ReleaseData(void* &pData) 
{
    // TODO: Release any data that you loaded. Please remember that there
    //       MUST BE NO MEMORY LEAK in this program.
    pData = NULL;
}

void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int& N) 
{
    // TODO: Please implement this function to process requests from client.
    //       The reuqest is given in form of a string pointed by pRequest.
    //       The data that you stored if pointed by pData.
    //       The output MUST BE STORED in the memory pointed by pOutput.
    //       N is the number of integers in the output.
    int End;
    Record * Data;
    Data = (struct Record *) pData;

    if (CR (pRequest))
    {
        pOutput = &(*Data).size;
        N = 1;
    }
    else if (DI (pRequest, End))
    {
        int End1, End2;
        char * Field1, * Field2;
        int Output;
        ReadInfo (pRequest, Field1, End, End1);
        ReadInfo (pRequest, Field2, End1, End2);
        DIProcess (Data, Field1, Field2, pOutput, N);
        N = 1;
    }
    else if (HI (pRequest, End))
    {
        int End1, End2, End3, End4;
        char * Field1, * Field2, * Field3, * Field4;
        ReadInfo (pRequest, Field1, End, End1);
        ReadInfo (pRequest, Field2, End1, End2);
        ReadInfo (pRequest, Field3, End2, End3);
        ReadInfo (pRequest, Field4, End3, End4);
        HIProcess (Data, Field1, Field2, Field3, Field4, pOutput, N);
    }
    else if (FR (pRequest))
    {
        FRProcess (Data, pOutput, N);
        
    }
    else if (FRLong (pRequest, End))
    {
        int End1, End2, End3;
        char * Field1, * Field2, * Field3, * Field4;
        ReadInfo (pRequest, Field1, End, End1);
        ReadInfo (pRequest, Field2, End1, End2);
        ReadInfo (pRequest, Field3, End2, End3);
        FRLongProcess (Data, Field1, Field2, Field3, pOutput, N);
    }
    else 
        cout << "Invalid Request!";

    return;
}

void RecordInitialize (struct Record& Data)
{       
    for (int i = 0; i < Data.size; i ++)
	{
        Data.Pregnancies[i] = 0;
        Data.Glucose[i] = 0;
        Data.BloodPressure[i] = 0;
        Data.SkinThickness[i] = 0;
        Data.Insulin[i] = 0;
        Data.BMI[i] = 0;
        Data.DiabetesPedigreeFunction[i] = 0;
        Data.Age[i] = 0;
        Data.Outcome[i] = 0;
	}
}

void CountLine (const char* FileName, int& count)
{
    count = -1;
    string line;

    ifstream file(FileName);

    while (getline(file, line))
        count++;
    file.close();
    return;
}

void FindBracket (const char* pRequest, int Start, int& OpenPosition, int& ClosePosition)
{
    int i = Start;
    OpenPosition = 0;
    ClosePosition = 0;
    while (pRequest[i] != '<')
    {
        i ++;
    }
    OpenPosition = i;
    int j = OpenPosition;
    while (pRequest[j] != '>')
    {
        j ++;
    }
    ClosePosition = j;
}

void ReadInfo (const char* pRequest, char* &CharOut, int Start, int& End)
{
    int OpenPosition = 3, ClosePosition = 5, j = 0, Length;
    FindBracket (pRequest, Start, OpenPosition, ClosePosition);
    Length = ClosePosition - OpenPosition;
    CharOut = new char[Length];
    for (int i = OpenPosition + 1; i < ClosePosition; i++)
    {
      CharOut[j] = pRequest[i];
       j ++;
    }
    CharOut[j] = '\0';
    End = ClosePosition;
}

bool CR (const char * pRequest)
{
    int i = 0, j;
    if (pRequest == "CR")
        return true;

    while (pRequest[i] != 'C' && pRequest[i] == ' ')
    {
        i ++;
    }
    if (pRequest[i] == 'C' && pRequest[i+1] == 'R')
    {
        j = i+2;
        while (pRequest[j] == ' ')
        {
            j++;
        }
        if (pRequest[j] == '\0')
            return true;
    }
        
    return false;
}

bool DI (const char * pRequest, int& End)
{
    int i = 0, j;
    while (pRequest[i] != 'D' && pRequest[i] == ' ')
    {
        i ++;
    }
    if (pRequest[i] == 'D' && pRequest[i+1] == 'I')
    {
        j = i + 2;
        while (pRequest[j] == ' ')
        {
            j ++;
        }
        End = j;
        return true;
    }
    return false;
}

bool HI (const char * pRequest, int& End)
{
    int i = 0, j;
    while (pRequest[i] != 'H' && pRequest[i] == ' ')
    {
        i ++;
    }
    if (pRequest[i] == 'H' && pRequest[i+1] == 'I')
    {
        j = i + 2;
        while (pRequest[j] == ' ')
        {
            j ++;
        }
            End = j;
        return true;
    }
    return false;
}

bool FR (const char * pRequest)
{
    int i = 0, j;
    if (pRequest == "FR")
        return true;

    while (pRequest[i] != 'F' && pRequest[i] == ' ')
    {
        i ++;
    }
    if (pRequest[i] == 'F' && pRequest[i+1] == 'R')
    {
        j = i+2;
        while (pRequest[j] == ' ')
        {
            j++;
        }
        if (pRequest[j] == '\0')
            return true;
    }
        
    return false;
}

bool FRLong (const char * pRequest, int& End)
{
    int i = 0, j;
    if (pRequest == "FR")
        return false;

    while (pRequest[i] != 'F' && pRequest[i] == ' ')
    {
        i ++;
    }
    if (pRequest[i] == 'F' && pRequest[i+1] == 'R')
    {
        j = i + 2;
        while (pRequest[j] == ' ')
        {
            j ++;
        }
        End = j;
        return true;
    }
    return false;
}

void Mean (const float * array, const int size, int& result)
{
    float result_float = 0.0;
    for (int i = 0; i < size; i ++)
    {
        result_float += array[i];
    }
    result_float /= size;
    result = result_float;
}

void StandardDeviation (const float * array, const int size, int& result)
{
    float sum = 0.0, mean, variance = 0.0, stdDeviation, result_float;
    
    for(int i = 0; i < 5; ++i)
        sum += array[i];
    
    mean = sum/5;

    for(int i = 0; i < 5; ++i)
        variance += pow(array[i] - mean, 2);
    
    variance=variance/5;
    stdDeviation = sqrt(variance);
    
    result_float = stdDeviation;
    result = result_float;
}

void Min (const float * array, const int size, int& result)
{
    float result_float = array[0];
    for (int i = 0; i < size; i ++)
    {
        if (result_float > array[i])
            result_float = array[i];
    }
    result = result_float;
}

void Max (const float * array, const int size, int& result)
{
    float result_float = array[0];
    for (int i = 0; i < size; i ++)
    {
        if (result_float < array[i])
            result_float = array[i];
    }
    result = result_float;
}

void DIProcess (Record * Data, const char * Field1, const char * Field2, void* &pOutput, int& N)
{
    int result = 0;
    if (strcmp("Mean", Field1) == 0)
    {
        if (strcmp("Pregnancies", Field2) == 0)
            Mean ((*Data).Pregnancies, (*Data).size, result);
        else if (strcmp("Glucose", Field2) == 0)
            Mean ((*Data).Glucose, (*Data).size, result);
        else if (strcmp("BloodPressure", Field2) == 0)
            Mean ((*Data).BloodPressure, (*Data).size, result);
        else if (strcmp("SkinThickness", Field2) == 0)
            Mean ((*Data).SkinThickness, (*Data).size, result);
        else if (strcmp("Insulin", Field2) == 0)
            Mean ((*Data).Insulin, (*Data).size, result);
        else if (strcmp("BMI", Field2) == 0)
            Mean ((*Data).BMI, (*Data).size, result);
        else if (strcmp("DiabetesPedigreeFunction", Field2) == 0)
            Mean ((*Data).DiabetesPedigreeFunction, (*Data).size, result);
        else if (strcmp("Age", Field2) == 0)
            Mean ((*Data).Age, (*Data).size, result);
        else if (strcmp("Outcome", Field2) == 0)
            Mean ((*Data).Outcome, (*Data).size, result);
    }
    else if (strcmp("StandardDeviation", Field1) == 0)
    {
        if (strcmp("Pregnancies", Field2) == 0)
            StandardDeviation ((*Data).Pregnancies, (*Data).size, result);
        else if (strcmp("Glucose", Field2) == 0)
            StandardDeviation ((*Data).Glucose, (*Data).size, result);
        else if (strcmp("BloodPressure", Field2) == 0)
            StandardDeviation ((*Data).BloodPressure, (*Data).size, result);
        else if (strcmp("SkinThickness", Field2) == 0)
            StandardDeviation ((*Data).SkinThickness, (*Data).size, result);
        else if (strcmp("Insulin", Field2) == 0)
            StandardDeviation ((*Data).Insulin, (*Data).size, result);
        else if (strcmp("BMI", Field2) == 0)
            StandardDeviation ((*Data).BMI, (*Data).size, result);
        else if (strcmp("DiabetesPedigreeFunction", Field2) == 0)
            StandardDeviation ((*Data).DiabetesPedigreeFunction, (*Data).size, result);
        else if (strcmp("Age", Field2) == 0)
            StandardDeviation ((*Data).Age, (*Data).size, result);
        else if (strcmp("Outcome", Field2) == 0)
            StandardDeviation ((*Data).Outcome, (*Data).size, result);
    }
    else if (strcmp("Min", Field1) == 0)
    {
        if (strcmp("Pregnancies", Field2) == 0)
            Min ((*Data).Pregnancies, (*Data).size, result);
        else if (strcmp("Glucose", Field2) == 0)
            Min ((*Data).Glucose, (*Data).size, result);
        else if (strcmp("BloodPressure", Field2) == 0)
            Min ((*Data).BloodPressure, (*Data).size, result);
        else if (strcmp("SkinThickness", Field2) == 0)
            Min ((*Data).SkinThickness, (*Data).size, result);
        else if (strcmp("Insulin", Field2) == 0)
            Min ((*Data).Insulin, (*Data).size, result);
        else if (strcmp("BMI", Field2) == 0)
            Min ((*Data).BMI, (*Data).size, result);
        else if (strcmp("DiabetesPedigreeFunction", Field2) == 0)
            Min ((*Data).DiabetesPedigreeFunction, (*Data).size, result);
        else if (strcmp("Age", Field2) == 0)
            Min ((*Data).Age, (*Data).size, result);
        else if (strcmp("Outcome", Field2) == 0)
            Min ((*Data).Outcome, (*Data).size, result);
    }
    else if (strcmp("Max", Field1) == 0)
    {
        if (strcmp("Pregnancies", Field2) == 0)
            Max ((*Data).Pregnancies, (*Data).size, result);
        else if (strcmp("Glucose", Field2) == 0)
            Max ((*Data).Glucose, (*Data).size, result);
        else if (strcmp("BloodPressure", Field2) == 0)
            Max ((*Data).BloodPressure, (*Data).size, result);
        else if (strcmp("SkinThickness", Field2) == 0)
            Max ((*Data).SkinThickness, (*Data).size, result);
        else if (strcmp("Insulin", Field2) == 0)
            Max ((*Data).Insulin, (*Data).size, result);
        else if (strcmp("BMI", Field2) == 0)
            Max ((*Data).BMI, (*Data).size, result);
        else if (strcmp("DiabetesPedigreeFunction", Field2) == 0)
            Max ((*Data).DiabetesPedigreeFunction, (*Data).size, result);
        else if (strcmp("Age", Field2) == 0)
            Max ((*Data).Age, (*Data).size, result);
        else if (strcmp("Outcome", Field2) == 0)
            Max ((*Data).Outcome, (*Data).size, result);
    }
    pOutput = &result;
}

void SizeOfHistogram (const int min, const int max, const int bin, int& size)
{
    int range = max - min;
    
    if (range%bin != 0)
        size = range/bin + 1;
    else 
        size = range/bin;
    return;
}

void HIProcess (Record * Data, const char * Field1, const char * Field2, const char * Field3, const char * Field4, void* &pOutput, int& N)
{
    int min, max, bin, size;

    CharToInt (Field2, min);
    CharToInt (Field3, max);
    CharToInt (Field4, bin);

    SizeOfHistogram (min, max, bin, size);
    int * Output = new int [size];

    for (int i = 0; i < size; i ++)
        Output[i] = 0;

    if (strcmp("Pregnancies", Field1) == 0)
    {
        for (int i = 0; i < size; i ++)
        {
            int Local_min = i * bin;
            int Local_max = (i + 1) * bin;

            for (int j = 0; j < (*Data).size; j ++)
            {
                int value = (*Data).Pregnancies[j];
                if (value >= Local_min && value <= Local_max)
                    Output[i] ++;
            }    
        }
    }
    else if (strcmp("Glucose", Field1) == 0)
    {
        for (int i = 0; i < size; i ++)
        {
            int Local_min = i * bin;
            int Local_max = (i + 1) * bin;

            for (int j = 0; j < (*Data).size; j ++)
            {
                int value = (*Data).Glucose[j];
                if (value >= Local_min && value <= Local_max)
                    Output[i] ++;
            }    
        }
    }   
    else if (strcmp("BloodPressure", Field1) == 0)
    {
        for (int i = 0; i < size; i ++)
        {
            int Local_min = i * bin;
            int Local_max = (i + 1) * bin;

            for (int j = 0; j < (*Data).size; j ++)
            {
                int value = (*Data).BloodPressure[j];
                if (value >= Local_min && value <= Local_max)
                    Output[i] ++;
            }   
        }
    }
    else if (strcmp("SkinThickness", Field1) == 0)
    {
        for (int i = 0; i < size; i ++)
        {
            int Local_min = i * bin;
            int Local_max = (i + 1) * bin;

            for (int j = 0; j < (*Data).size; j ++)
            {
                int value = (*Data).SkinThickness[j];
                if (value >= Local_min && value <= Local_max)
                    Output[i] ++;
            }   
        }
    }
    else if (strcmp("Insulin", Field1) == 0)
    {
        for (int i = 0; i < size; i ++)
        {
            int Local_min = i * bin;
            int Local_max = (i + 1) * bin;

            for (int j = 0; j < (*Data).size; j ++)
            {
                int value = (*Data).Insulin[j];
                if (value >= Local_min && value <= Local_max)
                    Output[i] ++;
            }   
        }
    }
    else if (strcmp("BMI", Field1) == 0)
    {
        for (int i = 0; i < size; i ++)
        {
            int Local_min = i * bin;
            int Local_max = (i + 1) * bin;

            for (int j = 0; j < (*Data).size; j ++)
            {
                int value = (*Data).BMI[j];
                if (value >= Local_min && value <= Local_max)
                    Output[i] ++;
            }   
        }
    }
    else if (strcmp("DiabetesPedigreeFunction", Field1) == 0)
    {
        for (int i = 0; i < size; i ++)
        {
            int Local_min = i * bin;
            int Local_max = (i + 1) * bin;

            for (int j = 0; j < (*Data).size; j ++)
            {
                int value = (*Data).DiabetesPedigreeFunction[j];
                if (value >= Local_min && value <= Local_max)
                    Output[i] ++;
            }   
        }
    }
    else if (strcmp("Age", Field1) == 0)
    {
        for (int i = 0; i < size; i ++)
        {
            int Local_min = i * bin;
            int Local_max = (i + 1) * bin;

            for (int j = 0; j < (*Data).size; j ++)
            {
                int value = (*Data).Age[j];
                if (value >= Local_min && value <= Local_max)
                    Output[i] ++;
            }   
        }
    }
    else if (strcmp("Outcome", Field1) == 0)
    {
        for (int i = 0; i < size; i ++)
        {
            int Local_min = i * bin;
            int Local_max = (i + 1) * bin;

            for (int j = 0; j < (*Data).size; j ++)
            {
                int value = (*Data).Outcome[j];
                if (value >= Local_min && value <= Local_max)
                    Output[i] ++;
            }   
        }
    }

    pOutput = Output;
    N = size;
    return;
}

void CountOutcome (const float * array, int size,  int& count)
{
    count = 0;
    for (int i = 0; i < size; i ++)
    {
        if (array[i] == 1)
            count ++;
    }
}

void FRProcess (Record * Data, void* &pOutput, int& N)
{
    int count, j = 0;
    CountOutcome ((*Data).Outcome, (*Data).size, count);
    N = count;
    int * Output = new int [count];
    for (int i = 0; i < (*Data).size; i ++)
    {
        if ((*Data).Outcome[i] == 1)
        {
            Output[j] = i;
            j ++;
        }
    }
    pOutput = Output;
}

void CountIntervalOutcome (const float * array, const float * Field, const int min, const int max, int size,  int& count)
{
    int Field_int;
    count = 0;
    for (int i = 0; i < size; i ++)
    {
        Field_int = Field[i];
        if (array[i] == 1 && Field_int > min && Field_int < max )
            count ++;
    }
}

void CharToInt (const char * Char, int& Int)
{
    Int = 0;
    for (int i = 0; Char[i] != '\0'; i ++)
    {
        Int = (Char[i] - '0') + Int*10;
    }
}

bool isInteger (const char * Char)
{
    for (int i = 0; Char[i] != '\0'; i ++)
    {
        if (Char[i] > '9' && Char[i] < '0')
            return false;
    }
}

void FRLongProcess (Record * Data, const char * Field1, const char * Field2, const char * Field3, void* &pOutput, int& N)
{
    int count, j = 0, min, max;

    CharToInt (Field2, min);
    CharToInt (Field3, max);

    if (strcmp("Pregnancies", Field1) == 0)
        CountIntervalOutcome ((*Data).Outcome, (*Data).Pregnancies, min, max, (*Data).size, count);
    else if (strcmp("Glucose", Field1) == 0)
        CountIntervalOutcome ((*Data).Outcome, (*Data).Glucose, min, max, (*Data).size, count);
    else if (strcmp("BloodPressure", Field1) == 0)
        CountIntervalOutcome ((*Data).Outcome, (*Data).BloodPressure, min, max, (*Data).size, count);
    else if (strcmp("SkinThickness", Field1) == 0)
        CountIntervalOutcome ((*Data).Outcome, (*Data).SkinThickness, min, max, (*Data).size, count);
    else if (strcmp("Insulin", Field1) == 0)
        CountIntervalOutcome ((*Data).Outcome, (*Data).Insulin, min, max, (*Data).size, count);
    else if (strcmp("BMI", Field1) == 0)
        CountIntervalOutcome ((*Data).Outcome, (*Data).BMI, min, max, (*Data).size, count);
    else if (strcmp("DiabetesPedigreeFunction", Field1) == 0)
        CountIntervalOutcome ((*Data).Outcome, (*Data).DiabetesPedigreeFunction, min, max, (*Data).size, count);
    else if (strcmp("Age", Field1) == 0)
        CountIntervalOutcome ((*Data).Outcome, (*Data).Age, min, max, (*Data).size, count);

    N = count;
    int * Output = new int [count];
    
    if (strcmp("Pregnancies", Field1) == 0)
    {
        int value;
        for (int i = 0; i < (*Data).size; i ++)
        {
            value = (*Data).Pregnancies[i];
            if ((*Data).Outcome[i] == 1 && value > min && value < max)
            {
                Output[j] = i;
                j ++;
            }
        }
    }
    else if (strcmp("Glucose", Field1) == 0)
    {
        int value;
        for (int i = 0; i < (*Data).size; i ++)
        {
            value = (*Data).Glucose[i];
            if ((*Data).Outcome[i] == 1 && value > min && value < max)
            {
                Output[j] = i;
                j ++;
            }
        }
    }
    else if (strcmp("BloodPressure", Field1) == 0)
    {
        int value;
        for (int i = 0; i < (*Data).size; i ++)
        {
            value = (*Data).BloodPressure[i];
            if ((*Data).Outcome[i] == 1 && value > min && value < max)
            {
                Output[j] = i;
                j ++;
            }
        }
    }
    else if (strcmp("SkinThickness", Field1) == 0)
    {
        int value;
        for (int i = 0; i < (*Data).size; i ++)
        {
            value = (*Data).SkinThickness[i];
            if ((*Data).Outcome[i] == 1 && value > min && value < max)
            {
                Output[j] = i;
                j ++;
            }
        }
    }
    else if (strcmp("Insulin", Field1) == 0)
    {
        int value;
        for (int i = 0; i < (*Data).size; i ++)
        {
            value = (*Data).Insulin[i];
            if ((*Data).Outcome[i] == 1 && value > min && value < max)
            {
                Output[j] = i;
                j ++;
            }
        }
    }
    else if (strcmp("BMI", Field1) == 0)
    {
        int value;
        for (int i = 0; i < (*Data).size; i ++)
        {
            value = (*Data).BMI[i];
            if ((*Data).Outcome[i] == 1 && value > min && value < max)
            {
                Output[j] = i;
                j ++;
            }
        }
    }
    else if (strcmp("DiabetesPedigreeFunction", Field1) == 0)
    {
        int value;
        for (int i = 0; i < (*Data).size; i ++)
        {
            value = (*Data).DiabetesPedigreeFunction[i];
            if ((*Data).Outcome[i] == 1 && value > min && value < max)
            {
                Output[j] = i;
                j ++;
            }
        }
    }
    else if (strcmp("Age", Field1) == 0)
    {
        int value;
        for (int i = 0; i < (*Data).size; i ++)
        {
            value = (*Data).Age[i];
            if ((*Data).Outcome[i] == 1 && value > min && value < max)
            {
                Output[j] = i;
                j ++;
            }
        }
    }

    pOutput = Output;
}

