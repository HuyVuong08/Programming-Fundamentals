#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

struct Product
{
    char * ID;
    char * name;
    double price;
};

//Question 1:
void reverseString(char* str) 
{ 
    int l, i; 
    char *begin_ptr, *end_ptr, ch; 
  
    l = strlen(str); 

    begin_ptr = str; 
    end_ptr = str; 
  
    for (i = 0; i < l - 1; i++) 
        end_ptr++; 
  
    for (i = 0; i < l / 2; i++) { 
  
        ch = *end_ptr; 
        *end_ptr = *begin_ptr; 
        *begin_ptr = ch; 

        begin_ptr++; 
        end_ptr--; 
    } 
} 

//Question 2:
void swap (int & a, int & b)
{
    int c = a;
    a = b;
    b = a;
    return;
}

//Question 3:
void swapArray (int ** a, int ** b)
{
    int *p = *a;
    *a = *b;
    *b = p;
}

//Question 4:
void sum (int array[], int &sum)
{
    int * p, n;
    
    p = array;    
    sum = 0;

    n = sizeof (array)/sizeof(array[0]);

    for (int i = 0; i < n; i ++)
    {
        sum += *p;
        p++;
    }
}

int main ()
{
    Product a;
    Product * pointer1 = &a;
    Product * b = new Product [2];
    Product * pointer2 = b;
    Product * pointer3 = pointer2 + 1;

    pointer1->name = "abc"; // Assign a.name = "abc"
    pointer2->name = "cde"; // Assign b[0].name = "cde"
    pointer3->name = "efg"; // Assign b[1].name = "efg"
}

/*
 *Question 6:
 *
 * Version 1 return 10 because data is updated to 20 which is applied to a clone variable inside 
 * the function, in the other words, q is remained unchanged outside of the function setValue 
 * 
 * On the other hand, Version 2 the value in the adress, not the clone of q created by the function.
 * Therefore, this time, q is changed.
 */