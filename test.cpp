#include <iostream>

using namespace std;

class IntList
{
private:
    int m_list[10];
 
public:
    int& operator[] (const int index);
};
 
int& IntList::operator[] (const int index)
{
    return m_list[index];
}