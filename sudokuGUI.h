#ifndef SUDOKUGUI_H_INCLUDED
#define SUDOKUGUI_H_INCLUDED
#define SCREEN_WIDTH 80
#define UNCHECKED 0 // this refere to unassigned value in matrex
#define N 9 // this length and heigh of matrix
const char gridCH[] = {218, 196, 191, 179, 192, 217, 195, 194, 180, 193, 197};
const char spc      = ' ';
void printCh(int cnt, char ch);
void printUp(int cnt);
void responsive(int size);
void printBox(int grid[N][N]);
void lineByLine(int ln, int grid[N][N]);

#endif // SUDOKUGUI_H_INCLUDED
