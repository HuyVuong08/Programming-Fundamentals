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
    char *pRequest = "CR";
    void * pData, *pOutput;
    int N;
    LoadData ("diabetes.csv", pData);
    ProcessRequest(pRequest, pData, pOutput, N);
    cout << *(int *)pOutput;
    return 0;
}