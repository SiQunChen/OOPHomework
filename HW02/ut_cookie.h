#include "../src/cookie.h"
using namespace std;
/* The function help you to create the empty grid. */
/* You can use this function or create by yourself. */
bool** create_grid(){
    bool** array = new bool*[10];
    for(int i = 0; i < 10; i++){
        array[i] = new bool[10];
        for(int j = 0; j < 10; j++){
            array[i][j] = false;
        }
    }
    array[9][0]=true;
    return array;
}

/* The function help you to delete the grid. */
/* You should implement this by yourself. */
void delete_grid(bool** array){
    for(int i=9;i>=0;i--)
    {
        delete[]array[i];
    }
    delete[]array;
}

/* Add some test in here. */

/* 
TEST(Cookie, SomeTest){
    ...
}
*/
TEST(Cookie1,set1)
{
    bool** grid=create_grid();
    //print_grid(grid);
    placeTop(grid);
    //print_grid(grid);
    placeRight(grid);
    //print_grid(grid);
    placeTop(grid);
    //print_grid(grid);
    placeRight(grid);
    calcRow(grid, 8); // The first output
    calcColumn(grid, 1); // The second output
    //print_grid(grid);
    ASSERT_EQ(calcRow(grid, 8),2);
    ASSERT_EQ(calcColumn(grid, 1),2);
    delete_grid(grid);
}

TEST(Cookie2,set2)
{
    bool** grid=create_grid();
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    calcRow(grid, 0); // The first output
    calcRow(grid, 8); // The second output
    calcColumn(grid, 0); // The third output
    ASSERT_EQ(calcRow(grid, 0),0);
    ASSERT_EQ(calcRow(grid, 8),1);
    ASSERT_EQ(calcColumn(grid, 0),4);
    delete_grid(grid);
}

TEST(Cookie3,set3)
{
    bool** grid=create_grid();
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);    
    ASSERT_THROW(placeTop(grid),std::string);
    delete_grid(grid);
}

TEST(Cookie4,set4)
{
    bool** grid=create_grid();
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);    
    ASSERT_THROW(placeRight(grid),std::string);
    delete_grid(grid);
}


TEST(Cookie5,set5)
{
    bool** grid=create_grid();
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    calcRow(grid, 0); // The first output
    calcRow(grid, 8); // The second output
    calcColumn(grid, 0); // The third output
    ASSERT_EQ(calcRow(grid, 100),-1);
    delete_grid(grid);
}

TEST(Cookie6,set6)
{
    bool** grid=create_grid();
    placeTop(grid);
    placeTop(grid);
    placeTop(grid);
    calcRow(grid, 0); // The first output
    calcRow(grid, 8); // The second output
    calcColumn(grid, 0); // The third output
    ASSERT_EQ(calcColumn(grid, 100),-1);
    delete_grid(grid);
}

TEST(Cookie7,set7)
{
    bool** grid=create_grid();
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    calcRow(grid, 8); // The first output
    calcColumn(grid, 1); // The second output
    //print_grid(grid);
    ASSERT_EQ(calcRow(grid, 3),2);
    ASSERT_EQ(calcColumn(grid, 2),2);
    delete_grid(grid);
}


