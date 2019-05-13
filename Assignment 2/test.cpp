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

#include "core.h"
#include "core.cpp"

using namespace std;

int main() {
    char *pRequest = "DI <MEAN> <Age>", * CharOut;
    void * pData, *pOutput;
    int N, Start = 0, End = 0;
    LoadData ("diabetes.csv", pData);
    ProcessRequest(pRequest, pData, pOutput, N);
/*
    ReadInfo (pRequest, CharOut, Start, End);
    cout << CharOut << endl << End;
    ReadInfo (pRequest, CharOut, 8, End);
    cout << CharOut << endl << End;
*/
    return 0;
}