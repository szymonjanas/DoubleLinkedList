#include <gtest/gtest.h>

/*
struct ListTest : public ::testing::Test
{
    //GIVEN
    List<int> ls;
    void insert_data()
    {
        ls.push_back(9);
        ls.push_back(4);
        ls.push_back(5);
        ls.push_back(7);
    }
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
    insert_data();
    //THEN
    ASSERT_EQ(4, ls.getListSize());
    ASSERT_EQ(7, ls.getTail()->value);
    ASSERT_EQ(9, ls.getHead()->value);
}

TEST_F(ListTest, push_front_one_elements)
{
    //WHEN
    ls.push_front(9);
    ls.push_front(4);
    ls.push_front(1);
    ls.push_front(8);

    //THEN
    ASSERT_EQ(4, ls.getListSize());
    ASSERT_EQ(8, ls.getHead()->value);
    ASSERT_EQ(9, ls.getTail()->value);
}

TEST_F(ListTest, pop_back_element_from_list)
{
    //WHEN
    insert_data();

    ls.pop_back();
    //THEN
    ASSERT_EQ(5, ls.getTail()->value);
}

TEST_F(ListTest, pop_front_element_from_list)
{
    //WHEN
    insert_data();

    ls.pop_front();
    //THEN
    ASSERT_EQ(4, ls.getHead()->value);
}

TEST_F(ListTest, getBackward_test)
{
    //WHEN
    insert_data();

    //THEN
    ASSERT_EQ(4, ls.getBackward(4)->value);
}

TEST_F(ListTest, clear_test)
{
    //WHEN
    insert_data();
    ASSERT_EQ(4, ls.getListSize());

    //THEN
    ls.clear();
    ASSERT_EQ(0, ls.getListSize());
}
*/