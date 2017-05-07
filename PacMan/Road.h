#pragma once
#include "stillitem.h"
class CRoad :
    public CStillItem
{
public:
    CRoad(int nRow, int nCol);
    ~CRoad(void);
    void Show(void);
};

