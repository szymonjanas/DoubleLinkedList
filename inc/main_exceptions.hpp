
#include <exception>

using namespace std;

class WrongPositionGiven : public runtime_error
{
    public:
    WrongPositionGiven() : runtime_error("Wrong position given!")
    {}
} pos_error;

class EmptyList : public runtime_error
{
    public:
    EmptyList() : runtime_error("List is empty!")
    {}
} empty_error;