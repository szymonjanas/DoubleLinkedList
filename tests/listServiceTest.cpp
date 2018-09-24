#include <gtest/gtest.h>
#include "listService.hpp"

struct ListTest : public ::testing::Test
{
    //GIVEN
    List<int> ls;
};
typedef ::testing::Types<int, float> MyTypes ;
TEST_F(ListTest, push_back_when_list_is_empty)
{
    
    //WHEN
    ls.push_back(5);
    //THEN
    ASSERT_EQ(1, ls.getListSize());
    ASSERT_EQ(5, ls.getHead()->value);
    ASSERT_EQ(5, ls.getTail()->value);
}
