# include <iostream>
# include <string>

using namespace std;

bool isDigit (char c)
{
    if (c > '0' && c < '9')
        return true;
    return false;
}

bool isDecimal (char c)
{
    if (c == '.')
        return true;
    return false;
}

bool isNegative (char c)
{
    if (c == '-')
        return true;
    return false;
}

bool isPositive (char c)
{
    if (c == '+')
        return true;
    return false;
}


void getDecimal (float & decimal, int NumberOfDecimal)
{
    float dec = 1;
    for (int i = 0; i < NumberOfDecimal; i ++)
    {
        dec /= 10;
    }
    decimal = decimal * dec;
    return;
}

float str2num (string str)
{
    int i = 0, NumberOfDecimal = 0;
    float num = 0, decimal = 0;
    bool dot = false, Negative = false;
    while (str[i] != '\0')
    {
        char c = str[i];
        if (isDigit (c) && dot == false)
            num = (c - '0') + num * 10;
        else if (isDigit(c) && dot == true)
        {
            decimal = (c - '0') + decimal * 10;
            NumberOfDecimal ++;
        }
        else if (isDecimal (c))
            dot = true;
        else if (isNegative (c))
            Negative = !Negative;
        else if (isPositive (c))
            Negative = Negative;
        i ++;
    }
    getDecimal (decimal, NumberOfDecimal);
    num = num + decimal;
    if (Negative == true)
        num = 0 - num;
    return num;
}

int smallest (int * Array, int size, int start)
{
    int smallest = start, i;
    for (i = start + 1; i < size; i ++)
    {
        if (Array[smallest] > Array[i])
            smallest = i;
    }
    return smallest;
}

void swapPosition (int * Array, int P1, int P2)
{
    int temp = Array[P1];
    Array[P1] = Array[P2];
    Array[P2] = temp;

    return;
}

void sort (int * Array, int size)
{
    int start = 0, min;

    for (int i = 0; i < size; i ++)
    {
        min = smallest (Array, size, start);
        swapPosition (Array, start, min);
        start ++;
    }

    return;
}

int main ()
{
    int * Array = new int [5];
    Array[0] = 9;
    Array[1] = 5;
    Array[2] = 11;
    Array[3] = 3;
    Array[4] = 15;
    
    sort (Array, 5);

    for (int i = 0; i < 5; i ++)
    {
        cout << Array[i] << ' ';
    }

    delete [] Array;
    return 0;
}