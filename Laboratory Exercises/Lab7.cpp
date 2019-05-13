/**
    Faculty of Computer Science and Engineering
    Ho Chi Minh City University of Technology
    Programming fundamentals - spring 2019
    Lab 07: 07002_ini.cpp
    @author CSE - HCMUT
    @version 1.0 Mon Apr 22 17:09:40 2019

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>
#define FILENAME "07002_sol.cpp"
using namespace std;
//----------------------------------------------
// Begin implementation
//----------------------------------------------

class Integer {
	int value;
public:
    Integer (int _value) {value = _value;}
    // Methods prototypes only

    int getvalue ();

    friend bool operator== (const Integer &i1, const Integer &i2);
    friend bool operator!= (const Integer &i1, const Integer &i2);

    friend bool operator> (const Integer &i1, const Integer &i2);
    friend bool operator<= (const Integer &i1, const Integer &i2);
 
    friend bool operator< (const Integer &i1, const Integer &i2);
    friend bool operator>= (const Integer &i1, const Integer &i2);

    int& operator[] (const int index);
};

int Integer::getvalue ()
{
    return this -> value;
}

bool operator== (const Integer &i1, const Integer &i2)
{
    return (i1.value== i2.value);
}
 
bool operator!= (const Integer &i1, const Integer &i2)
{
    return !(i1==i2);
}

bool operator> (const Integer &i1, const Integer &i2)
{
    return i1.value > i2.value;
}
 
bool operator>= (const Integer &i1, const Integer &i2)
{
    return i1.value >= i2.value;
}
 
bool operator< (const Integer &i1, const Integer &i2)
{
    return i1.value < i2.value;
}
 
bool operator<= (const Integer &i1, const Integer &i2)
{
    return i1.value <= i2.value;
}

int& Integer::operator[] (const int index)
{
    return value[index];
}

/*
Integer max(Integer* arr, Integer numberOfElements) {
	if (arr == NULL || numberOfElements == 0) return Integer(-1);
	Integer max = arr[0];
	for (Integer i = 0; i < numberOfElements; i = i + 1) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}
*/

int main () 
{
    Integer i1 = 5, i2 = 5;
    if (i1 < i2)
        cout << "i1 < i2";
    else if (i1 > i2)
        cout << "i1 > i2";
    else if (i1 == i2)
        cout << "i1 = i2";

    return 0;
}