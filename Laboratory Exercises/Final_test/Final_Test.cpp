#include <iostream>
#include "Process.h"
#include "Secrectary.h"
#include "Sales.h"
#include "Manager.h"

using namespace std;

int main ()
{
    Process * list[8] = {
        new Secrectary (10000, 2, 1, "Long", "02/22/1998"),
        new Secrectary (10000, 2,  1, "Long", "02/22/1998"),
        new Secrectary (10000, 2, 1, "Long", "02/22/1998"),
        new Secrectary (10000, 2, 1, "Long", "02/22/1998"),
        new Sales (10000, 1, "Long", "02/22/1998"),
        new Sales (10000, 1, "Long", "02/22/1998"),
        new Sales (10000, 1, "Long", "02/22/1998"),
        new Manager (10000, 1, "Long", "02/22/1998")
    };

    return 0;
}