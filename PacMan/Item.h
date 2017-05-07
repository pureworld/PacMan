#pragma once
#include <iostream>
#include <conio.h>
#include "PdcCurses.h"
using namespace std;

const int ROW = 31;
const int COL = 28;

class CItem
{
public:
    enum {
        ITEM_PEAN,
        ITEM_WALL,
        ITEM_GHOME,
        ITEM_ROAD
    };
    virtual ~CItem() = 0 { }
    virtual void Show() = 0;
protected:
    CPdcCurses* m_pPdc;
    int m_nRowPos;
    int m_nColPos;
    int m_nCollisionLv;
};

