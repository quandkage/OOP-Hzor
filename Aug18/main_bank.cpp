#include <iostream>
#include <string>
#include "bank.h"

int main()
{
    Bank Converse;
    int Acc_1 = Converse.creatAccout();
    Converse.printinfo(Acc_1);
    Converse.Dep(Acc_1, 4000);
    Converse.Wit(Acc_1, 4500);
    Converse.Wit(Acc_1, 2500);
    Converse.printinfo(Acc_1);
    int Acc_2 = Converse.creatAccout();
    Converse.Dep(Acc_2, 5000);
    Converse.printinfo(Acc_2);

    return 0;
}
