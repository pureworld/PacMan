#pragma once
#include "ghost.h"
/*
粉色
以玩家当前方向前4个位置为目标
*/
class CPinky :
    public CGhost
{
public:
    CPinky(int nRow, int nCol);
    ~CPinky(void);

    void Show();
    void AutoTrace();
};

