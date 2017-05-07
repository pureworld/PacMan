#pragma once
#include "ghost.h"
/*
橙鬼 黄
距离8或以上，以玩家为目标，
以内朝着角落前进
*/
class CClyde :
    public CGhost
{
public:
    CClyde(int nRow, int nCol);
    ~CClyde(void);

    void Show();
    void AutoTrace();
};

