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


