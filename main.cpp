#include <bits/stdc++.h>
using namespace std;
#include "template.cpp"
#include "sudokuGUI.h"
int counter;
/*
    ::NOTE THAT:: whe set prototype of (findFirstUnchekedLocation - isSafe) function because we used it
    in SolveSudoku &^&
*/
bool findFirstUnchekedLocation(int grid[N][N], int &row, int &col);// this function first position not checked work by referance
bool isSafe(int grid[N][N], int row, int col, int num); // this function group your logic function like inRow , in column  ...... and return true if is true
void printGrid(int grid[N][N]);// print grid 3adeeee

bool SolveSudoku(int grid[N][N]){
    int row, col;// this in first call 0 0 "by default"

    if (!findFirstUnchekedLocation(grid, row, col))// base case condition if all positions set by numbers (not 0 "UNCHECKED VALUE")
        return true; // if we arrive for this step all gird is set by isSafe logic
    for (int i = 1; i <= 9; i++){
        if (isSafe(grid, row, col, i)){
            grid[row][col] = i;
            /*system("cls");
                printBox(grid);
                getchar();
*/
            if (SolveSudoku(grid)){
                return true;
            }//end of if (SolveSudoku(grid))
            grid[row][col] = UNCHECKED;
        }// end of if (isSafe(grid, row, col, i))
    }//end of for
    return false;
}
bool findFirstUnchekedLocation(int grid[N][N], int &row, int &col){
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNCHECKED)
                return true;
    return false;
}
bool UsedInRow(int grid[N][N], int row, int num){
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool UsedInCol(int grid[N][N], int col, int num){
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}


bool isSafe(int grid[N][N], int row, int col, int num){
    return  !UsedInRow(grid, row, num) &&
            !UsedInCol(grid, col, num) &&
            !UsedInBox(grid, row - row%3 , col - col%3, num);
}
void printGrid(int grid[N][N]){
    printf("  ");
    for(int i=1;i<10;i++){
        printf("%2d", i);
    }

    printf("\n---------------------------------\n");
    for (int row = 0; row < N; row++){
        printf("%d|",row+1);
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}

int main(){
    system("color 0a");
    int grid[N][N] =                 {
        {0,0,0,0,0,5,0,2,0},
        {0,8,0,0,0,0,0,1,0},
        {0,0,0,0,0,1,0,0,0},
        {0,0,0,8,0,0,5,9,0},
        {0,0,0,0,0,0,0,0,0},
        {0,9,0,0,0,0,0,0,0},
        {0,0,0,0,0,8,0,0,0},
        {0,1,0,0,0,0,3,0,0},
        {0,0,0,0,3,0,6,0,1}
    };
    //printBox(grid);
    if (SolveSudoku(grid))
        {
            printBox(grid);
            //printGrid(grid);
        }
    else
        printf("No solution exists");
    return 0;
}
/*
{
                        {3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};


                        {
        {0,0,0,0,0,5,0,2,0},
        {0,8,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0},
        {0,0,0,8,0,0,5,9,0},
        {0,0,0,0,0,0,0,4,0},
        {0,9,0,0,0,0,0,0,0},
        {0,0,0,0,0,8,0,0,0},
        {0,1,0,0,0,0,3,0,0},
        {0,0,0,0,3,0,6,0,0}
    };


*/

