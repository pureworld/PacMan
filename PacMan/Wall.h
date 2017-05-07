#pragma once
#include "stillitem.h"
class CWall :
    public CStillItem
{
public:
    CWall(int nRow, int nCol);
    ~CWall();
    void Show();

};

