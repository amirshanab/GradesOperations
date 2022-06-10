//amir abu shanab
//208586214

#include "StudentList.h"
#include <stdio.h>
#include <malloc.h>
#include "GradesOperations.h"

int main( )
{

    StudentList* Lis = OperationsFunction1();
    OperationsFunction2(Lis);
    deleteList(Lis);
    return 0;
}
