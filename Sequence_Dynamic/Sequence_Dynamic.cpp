#include "Sequence_Dynamic.h"
#include <iostream>
// Constructor
namespace Data_Structures
{
Sequence::Sequence()
{
this->used = 0; 
this->current_index = 0;
this->current_capacity = INITIAL_CAPACITY;
data = new Sequence::value_type[this->current_capacity];
}

bool Sequence::is_item() const
{
    if(this->current_index < this->used)
    {
        return true;
    }

    else
    {
        return false;
    }   
}

void Sequence::start()
{
// If empty
if(this->used == 0)
{
    return;
}
// If there are items
else
{
    this->current_index = 0;
}
}

void Sequence::advance()
{
    if(this->used > this->current_index + 1)
    {
        this->current_index++;
    }
}

void Sequence::move_up_by_one(int start_index)
{
    for(int i = this->used - 1; i >= start_index; i--)
    {
        data[i + 1] = data[i];
    }
}

void Sequence::insert(const value_type& entry)
{

    if(this->used == 0)
    {
        data[0] = entry;
       this->used = this->used + 1;
    }

    else if(this->used < this->current_capacity)
    {
        move_up_by_one(this->current_index);
        data[this->current_index] = entry;
       this->used = this->used + 1;
    }

    else
    {
        this->double_data_size();
        move_up_by_one(this->current_index);
        data[this->current_index] = entry;
       this->used = this->used + 1;
    }
}

void Sequence::attach(const value_type& entry)
{
    if(this->used == 0)
    {
        data[0] = entry;
       this->used = this->used + 1;
       this->current_index = 0;
    }

    else if(this ->used < this->current_capacity)
    {
        move_up_by_one(this->current_index + 1);
        data[this->current_index + 1] = entry;
        this->current_index++;
        this->used = this->used + 1;  
    }  

    else
    {
        this->double_data_size();
        move_up_by_one(this->current_index + 1);
        data[this->current_index + 1] = entry;
        this->current_index++;
        this->used = this->used + 1;  
    } 
}

void Sequence::double_data_size()
{
        this->current_capacity *= 2;
        double* new_data = new double[this->current_capacity];
        for(int i = 0; i < this->used; i++)
        {
            new_data[i] = data[i];
        }

        data = new_data;
}

void Sequence::remove_current()
{
    if(is_item())
    {
        for(int i = current_index; i < this->used - 1; i++)
        {
            data[i] = data[i + 1];
        }
       this->used = this->used - 1;
    }
    else
    {
        std::cout << "Not an item\n"; 
    }
}

Sequence::value_type Sequence::current() const
{
    if(is_item())
    {
        return this->data[current_index];
    }
}

Sequence::size_type Sequence::size() const
{
    return this->used;
}

void Sequence::debug()
{
    std::cout << "Debugging\n";
    std::cout << this->used << " used " << " out of " << this->current_capacity << std::endl;
    for(int i = 0; i < this->current_capacity; i++)
    {
        if(i == this->used)
        {
            std::cout << "Used Cutoff Here" << std::endl;
        }
        std::cout << i << ":\t" << data[i] << std::endl;
    }
    std::cout << "Done Debugging\n";
}
}
