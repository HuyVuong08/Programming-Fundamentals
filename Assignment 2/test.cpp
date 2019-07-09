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
    Initialization();

    void*   pData;
    void*   pOutput;
    int     N;
    Record Data;

    LoadData("diabetes.csv", pData);

    string req;
    req = "HI Age 0 100 10";

    ProcessRequest(req.data(), pData, pOutput, N);
    PrintOutput(req.data(), pData, pOutput, N);

    ReleaseData(pData);
    //Finalization();

    return 0;
}