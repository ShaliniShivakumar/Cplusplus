/******************************************************************************

Variadic templates 

*******************************************************************************/
#include <iostream>
using namespace std;

void print()
{
    cout<<"Empty print"<<endl;
}

template <typename arg, typename... Arguments>
void print(arg arg1, Arguments... args)
{
    cout<<arg1<<endl;
    print(args...);
}
int main()
{
    print(10);

    return 0;
}

