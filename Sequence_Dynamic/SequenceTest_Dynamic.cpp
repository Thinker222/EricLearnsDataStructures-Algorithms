#include "Sequence_Dynamic.cpp"
#include <iostream>
#include <cstdlib>

int main()
{
    using namespace Data_Structures;
    Sequence seq = Sequence();
    for(int i = 0; i < 50000; i++)
    {
        seq.attach(i);
    }

    seq.start();
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            seq.advance();
        }
        seq.remove_current();
    }
    seq.debug();
}