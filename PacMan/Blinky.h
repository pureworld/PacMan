#pragma once
#include "ghost.h"
/*
��ɫ
׷ɱ���
*/
class CBlinky :
    public CGhost
{
public:
    CBlinky() { }
    CBlinky(int nRow, int nCol);
    ~CBlinky(void);

    void Show();
    void AutoTrace();
};

