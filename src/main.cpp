#include "list.hpp"
#include <string>

using namespace std;

int main()
{
    List<string> listOfNames;

    //listOfNames.show();
    auto  Adrianna = make_shared<Node<string>>("Arianna");
    auto  Dorothy = make_shared<Node<string>>("Dorothy");
    auto  Edwin = make_shared<Node<string>>("Edwin");
    auto  Elizabeth = make_shared<Node<string>>("Elizabeth");
    auto  Enrico = make_shared<Node<string>>("Enrico");
    auto  Jane = make_shared<Node<string>>("Jane");
    auto  Lene = make_shared<Node<string>>("Lene");
    auto  Maria = make_shared<Node<string>>("Maria");
    auto  Melissa = make_shared<Node<string>>("Melissa");
    auto  Patty = make_shared<Node<string>>("Patty");
    listOfNames.push_back(Adrianna);
    listOfNames.push_back(Dorothy);
    listOfNames.push_back(Edwin);
    listOfNames.push_back(Elizabeth);
    listOfNames.push_back(Enrico);
    listOfNames.push_back(Jane);
    listOfNames.push_back(Lene);
    listOfNames.push_back(Maria);
    listOfNames.push_back(Melissa);
    listOfNames.push_back(Patty);
    listOfNames.show();


    auto  Rita = make_shared<Node<string>>("Rita");
    auto  Patricia = make_shared<Node<string>>("Patricia");
    auto  Sarah = make_shared<Node<string>>("Sarah");
    auto  Shirley = make_shared<Node<string>>("Shirley");
    auto  Wilhelm = make_shared<Node<string>>("Wilhelm");
    listOfNames.push_front(Rita);
    listOfNames.push_front(Patricia);
    listOfNames.push_front(Sarah);
    listOfNames.push_front(Shirley);
    listOfNames.push_front(Wilhelm);
    listOfNames.show();

  //  listOfNames.insert("Wolfgang", 3);
   // listOfNames.insert("Isaac", 5);
    listOfNames.show();

 //   listOfNames.erase_pos(2);
    listOfNames.show();

    listOfNames.pop_front();
    listOfNames.pop_front();
    listOfNames.pop_back();
    listOfNames.pop_back();
    listOfNames.show();

    listOfNames.show();
    auto name = listOfNames.getNode(2);
    cout << "Found name: " << name->value << endl;
   // listOfNames.clear();
   // listOfNames.show();

    return 0;
}
