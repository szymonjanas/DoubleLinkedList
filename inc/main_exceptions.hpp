
#include <exception>

using namespace std;

class WrongPositionGiven : public runtime_error
{
    public:
    WrongPositionGiven() : runtime_error("Wrong position given!")
    {}
} pos_error;
