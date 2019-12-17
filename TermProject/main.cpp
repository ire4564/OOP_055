#include <iostream>
#include "Operate.h"
#include "Manager.h"
#include "Block.h"
#include <stdlib.h>

int main()
{
    std::srand((unsigned int)time(0));
    Manager man;
    man.firstMake();
    man.moving();

    //Operate opr;
    //opr.moving();

}