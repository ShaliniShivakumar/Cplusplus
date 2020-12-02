/******************************************************************************

universal references / Forwarding references

*******************************************************************************/
#include <iostream>

void foo(int && val)
{
   std::cout<<"foo called"<<std::endl; 
}

template <typename T>
void Bar(T&& val)
{
 std::cout<<"bar called"<<std::endl;   
}

int main()
{
    int a = 10;
    
    //foo(a); // should fail
    
    foo(100); // should pass
    
    //Temokates bind to both lvalue and rvalue,
    //so it's called as universal reference
    Bar(a); 
    Bar(50);
    
    return 0;
}
