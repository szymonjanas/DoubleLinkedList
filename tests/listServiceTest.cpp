#include <gtest/gtest.h>
#include "list.hpp"

struct testList : public ::testing::Test
{
    List<int> ls;

};

auto make_ptr(int value)
{
    auto val = make_shared<Node<int>>(value);
    return val;
}

TEST_F( testList, push_back )
{
    //PUSH BACK TO EMPTY LIST
    ls.push_back(make_ptr(111));
    ASSERT_EQ(ls.getHead()->value, 111);
    ASSERT_EQ(ls.getTail()->value, 111);

    //PUSH BACK TO LIST WITH ONE ELEMENT
    ls.push_back(make_ptr(222));
    ASSERT_EQ(ls.getHead()->value, 111);
    ASSERT_EQ(ls.getTail()->value, 222);

    //PUSH BACK TO LIST WITH ELEMENTS
    ls.push_back(make_ptr(333));
    ASSERT_EQ(ls.getTail()->value, 333);
    ls.push_back(make_ptr(444));
    ASSERT_EQ(ls.getTail()->value, 444);
    ls.push_back(make_ptr(555));
    ASSERT_EQ(ls.getHead()->value, 111);
    ASSERT_EQ(ls.getTail()->value, 555);

}
