#pragma once
#include "ghost.h"
/*
蓝色
和红鬼的连线中点是玩家前进两位
*/
class CInky :
    public CGhost
{
public:
    CInky(int nRow, int nCol);
    ~CInky(void);

    void Show();
    void AutoTrace();
};

