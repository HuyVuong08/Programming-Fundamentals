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
    char *pRequest = "DI <Max> <Age>", * CharOut;
    void * pData, *pOutput;
    int N, Start = 0, End = 0;
    float * result;
    Record * Data;
    LoadData ("diabetes.csv", pData);
    ProcessRequest(pRequest, pData, pOutput, N);
    result = (float *)pOutput;
    cout << *result << endl << N;
    return 0;
}