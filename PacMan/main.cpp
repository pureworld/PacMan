/*
�Զ��ӵ���
*/
#include <iostream>
#include "curses.h"

using namespace std;

int main() {
    initscr();
    start_color();
    printw("hello world!");

    system("pause");
    return 0;
}
