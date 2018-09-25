#include "listService.hpp"
#include <string>

using namespace std;

int main()
{
    List<string> listOfNames;

    listOfNames.show();

    listOfNames.push_back("Adriana");
    listOfNames.push_back("Dorothy");
    listOfNames.push_back("Edwin");
    listOfNames.push_back("Elizabeth");
    listOfNames.push_back("Enrico");
    listOfNames.push_back("Jane");
    listOfNames.push_back("Lene");
    listOfNames.push_back("Maria");
    listOfNames.push_back("Melissa");
    listOfNames.push_back("Patty");
    listOfNames.show();

    listOfNames.push_front("Rita");
    listOfNames.push_front("Patricia");
    listOfNames.push_front("Sarah");
    listOfNames.push_front("Shirley");
    listOfNames.push_front("Wilhelm");
    listOfNames.show();

    listOfNames.insert("Wolfgang", 3);
    listOfNames.insert("Isaac", 5);
    listOfNames.show();

    listOfNames.erase_pos(6);
    listOfNames.show();

    listOfNames.pop_front();
    listOfNames.pop_front();
    listOfNames.pop_back();
    listOfNames.pop_back();
    listOfNames.show();

    listOfNames.clear();
    listOfNames.show();

    return 0;
}
