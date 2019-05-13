#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#define FILENAME "08000_sol.cpp"
using namespace std;

/* Your code MUST NOT contain any of the words in the list
{"..", "~/", "expect"} even in the comment */

//----------------------------------------------
// Begin implementation
//----------------------------------------------

/// Student may define something as need

struct DataSet
{
	int Data[100];
	int Appearance [100];
	bool Printed [100];
	int size = 0;
};

void DataSetInitialize (DataSet &DataSet)
{
	for (int i = 0; i < 100; i ++)
	{
		DataSet.Appearance[i] = 1;
		DataSet.Data[i] = 0;
		DataSet.Printed[i] = false;
	}
}

void RecordData (DataSet &DataSet, int DataIn)
{
	bool Appeared = false;
	if (DataSet.size == 0)
		DataSet.Data[0] = DataIn;

	for (int i = 0; i < DataSet.size; i++)
	{
		if (DataSet.Data[i] == DataIn)
		{
			DataSet.Appearance[i] ++;
			Appeared = true;
		}
	}
	if (Appeared == false)
	{
		DataSet.Data[DataSet.size] = DataIn;
		DataSet.size ++;
	}
}

void PrintMax (DataSet DataSet)
{
	int MaxPosition = 0;
	
	for (int i = 0;i < DataSet.size; i ++)
	{
		if (DataSet.Data[MaxPosition] <= DataSet.Data[i] && DataSet.Printed[i] == false)
		{
			MaxPosition = i;
		}
	}
	DataSet.Printed[MaxPosition] = true;
	if (DataSet.Data[MaxPosition] < 10)
		cout << DataSet.Data[MaxPosition] << "         " << DataSet.Appearance[MaxPosition];
	else if (DataSet.Data[MaxPosition] < 100)
		cout << DataSet.Data[MaxPosition] << "        " << DataSet.Appearance[MaxPosition];
	else if (DataSet.Data[MaxPosition] < 1000)
		cout << DataSet.Data[MaxPosition] << "       " << DataSet.Appearance[MaxPosition];
}

void PrintMin (DataSet &DataSet)
{
	int MinPosition = 0;
	
	while (DataSet.Printed[MinPosition])
	{
		MinPosition ++;
	}
	
	
	for (int i = 0;i < DataSet.size; i ++)
	{
		if (DataSet.Data[MinPosition] >= DataSet.Data[i] && DataSet.Printed[i] == false)
		{
			MinPosition = i;
		}
	}
	DataSet.Printed[MinPosition] = true;
	if (DataSet.Data[MinPosition] < 10)
		cout << DataSet.Data[MinPosition] << "         " << DataSet.Appearance[MinPosition] << endl;
	else if (DataSet.Data[MinPosition] < 100)
		cout << DataSet.Data[MinPosition] << "        " << DataSet.Appearance[MinPosition] << endl;
	else if (DataSet.Data[MinPosition] < 1000)
		cout << DataSet.Data[MinPosition] << "       " << DataSet.Appearance[MinPosition] << endl;
}

void PrintResult (DataSet &DataSet)
{
	for (int i = 0; i < DataSet.size - 1; i ++)
	{
		PrintMin (DataSet);
	}
	PrintMax (DataSet);
}

bool process(const char* fileName) {
	DataSet DataSet;
    string Data;
	ifstream ip(fileName);

	DataSetInitialize (DataSet);

    if(!ip.is_open()) 
	{	
		std::cout << "ERROR: File Open" << '\n';
		return false;
	}

    while(ip.good()){
        getline(ip,Data,' ');
        int Data_int = stoi(Data);
		if (Data_int >= 0 && Data_int <= 100 && Data_int != -999)
		RecordData (DataSet, Data_int);
    }
    ip.close();	
	PrintResult (DataSet);
}
	
int main ()
{
	process ("text.txt");
	return 0;
}