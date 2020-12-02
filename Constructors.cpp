/******************************************************************************

 Copy constructor, copy assigment operator, Move constructor and move assignment operator 
 demonstrated.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class MemoryBlock
{
  int length_;
  int *data_;
  
  public:
  MemoryBlock(int l); //default const
  ~MemoryBlock(); //Des
  
  //copy semantics
  MemoryBlock(const MemoryBlock&); //copy
  MemoryBlock& operator=(const MemoryBlock&);
    
 // Move semantics
MemoryBlock(MemoryBlock &&); //move cons
 MemoryBlock& operator=(MemoryBlock &&); //move assignment 
    
};

MemoryBlock::MemoryBlock(MemoryBlock && otherObj)
{
    cout<<"Move cons"<<endl;
    length_ = otherObj.length_;
    data_ = otherObj.data_;
    
    otherObj.length_ = 0;
    otherObj.data_ = nullptr;
    
    //*this = std::move(otherObj);
}

MemoryBlock& MemoryBlock::operator=(MemoryBlock && otherObj)
{
    cout<<"Move assignment"<<endl;
    if(this != &otherObj)
    {
        delete[] data_;
        
        length_ = otherObj.length_;
        data_ = otherObj.data_;
        
        otherObj.length_ = 0;
        otherObj.data_ = nullptr;
    }
    
    return *this;
    
}

MemoryBlock::MemoryBlock(int l)
{
    cout<<"default const"<<endl;
    length_ = l;
    data_ = new int[length_];
}

MemoryBlock::~MemoryBlock()
{
    cout<<"Destructor"<<endl;

    if(data_)
        delete[] data_;
}

MemoryBlock::MemoryBlock(const MemoryBlock& otherObj)
{
    cout<<"copy const"<<endl;
    length_ = otherObj.length_;
    
    data_ = new int[length_];
    
    std::copy(otherObj.data_, otherObj.data_+length_, data_);
    
}

MemoryBlock& MemoryBlock::operator=(const MemoryBlock& otherObj)
{
    cout<<"copy assignment"<<endl;
    
    
    if(this != &otherObj)
    {
        length_ = otherObj.length_;
        if(data_)
            delete[] data_;
            
        data_ = new int[length_];
        std::copy(otherObj.data_, otherObj.data_+length_, data_);
    }

    return *this;
    
}
int main()
{
    //copy semantics
    MemoryBlock b1(10);
    
    MemoryBlock copy = b1;
    
    MemoryBlock b2(5), b3(5);
    
    b2 = b1;
    
    //move semantics
    cout<<endl;
    
    std::vector<MemoryBlock> v ;
    v.push_back(MemoryBlock(10));
    
    cout<<endl;
    b2 = MemoryBlock(10);
    return 0;
}


