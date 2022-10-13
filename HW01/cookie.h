#include "../src/cookie.h"

TEST(cookie, Array1)
{
    int cookie = 4;
    int array[4] = {1,3,5,6};
    int output = max_dv(cookie, array);
    ASSERT_EQ(output, 9);
}
TEST(cookie, Array2)
{
    int cookie = 2;
    int array[2] = {6,9};
    int output = max_dv(cookie, array);
    ASSERT_EQ(output, 9);
}
TEST(cookie, Array3)
{
    int cookie = 3;
    int array[3] = {3,6,9};
    int output = max_dv(cookie, array);
    ASSERT_EQ(output, 12);
}
TEST(cookie, Array4)
{
    int cookie = 5;
    int array[5] = {1,3,5,6,7};
    int output = max_dv(cookie, array);
    ASSERT_EQ(output, 13);
}
TEST(cookie, Array5)
{
    int cookie = 4;
    int array[4] = {1,-3,5,6};
    int output = max_dv(cookie, array);
    ASSERT_EQ(output, -1);
}
TEST(cookie, Array6)
{
    int cookie = 2;
    int array[2] = {-5,6};
    int output = max_dv(cookie, array);
    ASSERT_EQ(output, -1);
}
TEST(cookie, Array7)
{
    int cookie = -4;
    int array[4] = {1,3,5,6};
    int output = max_dv(cookie, array);
    ASSERT_EQ(output, -1);
}
TEST(cookie, Array8)
{
    int cookie = -2;
    int array[2] = {5,7};
    int output = max_dv(cookie, array);
    ASSERT_EQ(output, -1);
}
// A single test case has the following form:
//
// TEST(TestSuiteName, TestName) {
//   ... test body ...
// }
