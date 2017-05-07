#pragma once
#include "ghost.h"
/*
ºìÉ«
×·É±Íæ¼Ò
*/
class CBlinky :
    public CGhost
{
public:
    CBlinky(int nRow, int nCol);
    ~CBlinky(void);

    void Show();
    void AutoTrace();
};

