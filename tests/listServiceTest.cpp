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

TEST_F( testList, push_back_and_increment_list_size )
{
    //PUSH BACK TO EMPTY LIST
    ls.push_back(make_ptr(111));
    ASSERT_EQ(ls.getHead()->value, 111);
    ASSERT_EQ(ls.getTail()->value, 111);
    ASSERT_EQ(ls.getListSize(), 1);

    //PUSH BACK TO LIST WITH ONE ELEMENT
    ls.push_back(make_ptr(222));
    ASSERT_EQ(ls.getHead()->value, 111);
    ASSERT_EQ(ls.getTail()->value, 222);
    ASSERT_EQ(ls.getListSize(), 2);

    //PUSH BACK TO LIST WITH ELEMENTS
    ls.push_back(make_ptr(333));
    ASSERT_EQ(ls.getTail()->value, 333);
    ls.push_back(make_ptr(444));
    ASSERT_EQ(ls.getTail()->value, 444);
    ls.push_back(make_ptr(555));
    ASSERT_EQ(ls.getHead()->value, 111);
    ASSERT_EQ(ls.getTail()->value, 555);

    ASSERT_EQ(ls.getListSize(), 5);

}

TEST_F( testList, push_front_and_increment_list_size )
{
    //PUSH FRONT TO EMPTY LIST
    ls.push_front(make_ptr(555));
    ASSERT_EQ(ls.getHead()->value, 555);
    ASSERT_EQ(ls.getTail()->value, 555);
    ASSERT_EQ(ls.getListSize(), 1);

    //PUSH FRONT TO LIST WITH ONE ELEMENT
    ls.push_front(make_ptr(444));
    ASSERT_EQ(ls.getHead()->value, 444);
    ASSERT_EQ(ls.getTail()->value, 555);
    ASSERT_EQ(ls.getListSize(), 2);

    //PUSH FRONT TO LIST WITH ELEMENTS
    ls.push_front(make_ptr(333));
    ASSERT_EQ(ls.getHead()->value, 333);
    ls.push_front(make_ptr(222));
    ASSERT_EQ(ls.getHead()->value, 222);
    ls.push_front(make_ptr(111));
    ASSERT_EQ(ls.getHead()->value, 111);
    ASSERT_EQ(ls.getTail()->value, 555);
    ASSERT_EQ(ls.getListSize(), 5);

}
