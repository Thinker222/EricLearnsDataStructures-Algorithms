#ifndef SEQUENCE
#define SEQUENCE
# include <cstdlib>
namespace Data_Structures
{
class Sequence
{
public:
// TypeDefs and MEMBER CONSTANTS
typedef double value_type; 
typedef int size_type; 
static const size_type INITIAL_CAPACITY = 20;
// Constructor
Sequence();
// Modification member functions
void start();
void advance();
void insert(const value_type & entry);
void attach(const value_type & entry);
void remove_current();
// Constant member functions
size_type size() const;
bool is_item() const; 
value_type current() const;
// DEBUG
void debug();
private:
value_type *data;
size_type used; 
size_type current_index;
size_type current_capacity;
// Helper functions for moving data
void move_up_by_one(int start_index);
void double_data_size();

};
}
#endif