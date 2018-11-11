#include "Sequence.cpp"
#include <iostream>
#include <cstdlib>

int main()
{
    using namespace Data_Structures;
    Sequence seq;
    Sequence seq2;
    for(int i = 0; i < 20; i++)
    {
    seq.insert(i);
    std::cout << seq2.current() << std::endl;
    }
    for(int i = 0; i < 20; i++)
    {
    seq2.attach(i);
    std::cout << seq2.current() << std::endl;
    }
    seq.debug();
    seq2.debug();
    return 0;
}