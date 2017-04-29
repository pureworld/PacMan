/*
³Ô¶¹×ÓµÄÈË
*/
#include <iostream>
#include "PdcCurses.h"

using namespace std;

int main() {
//     initscr();
//     //raw();
//     echo();
//     start_color();
//     printw("hello world!\n");
//     refresh();
//     getch();
//     endwin();
    CPdcCurses* obj = CPdcCurses::GetCurses();
    obj->CreateNewWin();
    obj->ColorOn(COLOR_PAIR(1));
    obj->Printf("Hello World!");
    obj->PrintfAt(10, 10, "Hello World!");
    obj->Refresh();
    obj->ColorOff(COLOR_PAIR(1));
    obj->ClearWin();
    for (int i = 0; i < 128; i++) {
        obj->PrintCharAt(i);
    }
    obj->Refresh();
    //getch();
    //*obj << 3;

    system("pause");
    return 0;
}
