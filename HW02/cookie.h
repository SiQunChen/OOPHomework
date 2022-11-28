#ifndef COOKIE_H
#define COOKIE_H
using namespace std;

int check_x(bool** grid){
    /* Return the x-coordinate of the lastest of cookie. */
     for(int x=0;x<10;x++)
     {
        for(int y=9;y>=0;y--)
        {
            if(grid[x][y]==true)return x;//printf("%d%d",x,y);
        }
     }
     return 0;
}

int check_y(bool** grid){
    /* Return the y-coordinate of the lastest of cookie. */
    for(int x=0;x<10;x++)
     {
        for(int y=9;y>=0;y--)
        {
            if(grid[x][y]==true)return y;
        }
     }
     return 0;
}

int print_grid(bool** grid){
    /* Print the grid you input. */
    /* Implement this function if necessary, it can help you to check your grid is correct or not. */
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void placeTop(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    /* You can implement check_x(), check_y() above to get the x, y of the lastest cookie you place. */
    int x = check_x(grid);
    int y = check_y(grid);
    x-=1;
    /* Check when you place cookie, it will out of bound or not. */
    if(x<0){ throw string("out of range");}
    /* ... */

    /* Place cookie from the top of current cookie. */
    grid[x][y]=true;
}

void placeRight(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    int x = check_x(grid);
    int y = check_y(grid);
    y+=1;
    /* Check when you place cookie, it will out of bound or not. */
    if(y>9){ throw string("out of range");}

    /* Place cookie from the right of current cookie. */
    grid[x][y]=true;
}

int calcRow(bool** grid, int row){
    /* Calculate the count of cookie on the specific row */
    if(row>9 || row<0){return -1;}
    int total=0;
    for(int x=0;x<10;x++)
    {
        if(grid[row][x]==true){total+=1;}
    }
    return total;
}

int calcColumn(bool** grid, int column){
    /* Calculate the count of cookie on the specific column */
    if(column>9 || column<0){return -1;}
    int total=0;
    for(int y=0;y<10;y++)
    {
        if(grid[y][column]==true){total+=1;}
    }
    return total;
}

#endif
