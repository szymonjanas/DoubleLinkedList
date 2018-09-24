#include <gtest/gtest.h>
#include "listService.hpp"

struct ListTest : public ::testing::Test
{
    //GIVEN
    List<int> ls;
};

TEST_F(ListTest, push_back_when_list_is_empty)
{
    
    //WHEN
    ls.push_back(5);
    //THEN
    ASSERT_EQ(1, ls.getListSize());
    ASSERT_EQ(5, ls.getHead()->value);
    ASSERT_EQ(5, ls.getTail()->value);
}

TEST_F(ListTest, push_back_few_elements)
{
    //WHEN
    ls.push_back(9);
    ls.push_back(4);
    ls.push_back(5);
    ls.push_back(7);
    //THEN
    ASSERT_EQ(4, ls.getListSize());
    ASSERT_EQ(7, ls.getTail()->value);
    ASSERT_EQ(9, ls.getHead()->value);
}

TEST_F(ListTest, push_front_one_elements)
{
    //WHEN
    ls.push_front(6);
    ls.push_front(9);
    ls.push_front(3);
    ls.push_front(5);

    //THEN
    ASSERT_EQ(4, ls.getListSize());
    ASSERT_EQ(5, ls.getHead()->value);
    ASSERT_EQ(6, ls.getTail()->value);
}
