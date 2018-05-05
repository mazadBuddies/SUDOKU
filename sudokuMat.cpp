#include "template.cpp"
#include "sudokuGUI.h"
using namespace std;

void printCh(int cnt, char ch){
    lp(i, cnt)
        pfch(ch);
}

void printUp(int cnt){
    printCh(cnt, gridCH[1]);
}

void responsive(int size){
    printCh((int)((SCREEN_WIDTH - size)/2), spc);
}
void lineByLine(int ln, int grid[N]){
responsive(12 * 3);
lp(i, 3){
    switch(ln){
        case 1:
                cout<<gridCH[0];
                printUp(2);
                cout<<gridCH[7];
                printUp(1);
                cout<<gridCH[7];
                printUp(1);
                cout<<gridCH[2];
        break;

        case 2:
            cout<<gridCH[3]<< grid[0+(i*3)]<<spc<<gridCH[3]<<grid[1+(i*3)]<<gridCH[3]<<grid[2+(i*3)]<<gridCH[3];
        break;

        case 3:
            cout<<gridCH[3]<<spc<<gridCH[0]<<gridCH[9];
            printUp(1);
            cout<<gridCH[10];
            printUp(1);///////
            cout<<gridCH[8];
        break;
        case 4:
            cout<<gridCH[3]<<spc<<gridCH[3]<<grid[1+(i*3)]<<spc<<gridCH[3]<<grid[2+(i*3)]<<gridCH[3];
        break;
        case 5:
            cout<<gridCH[6]<<gridCH[1]<<gridCH[8]<<spc<<spc;
            cout<<gridCH[6];
            printUp(1);
            cout<<gridCH[8];
        break;
        case 6:
            cout<<gridCH[3]<<grid[0+(i*3)]<<gridCH[3]<<spc<<spc<<gridCH[3]<<spc<<gridCH[3];
        break;
        case 7:
            cout<<gridCH[6];
            printUp(1);
            cout<<gridCH[10];
            printUp(1);
            cout<<gridCH[7]<<gridCH[5]<<spc<<gridCH[3];
        break;
        case 8:
            cout<<gridCH[3]<<grid[0+(i*3)]<<gridCH[3]<<grid[1+(i*3)]<<gridCH[3]<<spc<<grid[2+(i*3)]<<gridCH[3];
        break;
        case 9:
            cout<<gridCH[4];
            printUp(1);
            cout<<gridCH[9];
            printUp(1);
            cout<<gridCH[9];
            printUp(2);
            cout<<gridCH[5];
        break;
    }
}//end of for
    end;
}
void printBox(int grid[N][N]){
lp(j,3){
        FOR(i, 1, 10){
            if(i<3)
                lineByLine(i, grid[0+(j*3)]);
            else if(i<8)
                lineByLine(i, grid[1+(j*3)]);
            else
                lineByLine(i, grid[2+(j*3)]);
        }
    }
}



