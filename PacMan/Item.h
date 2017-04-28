#pragma once
#include <iostream>
using namespace std;

const int ROW = 31;
const int COL = 28;

class CItem
{
public:
    enum {
        StillItem = 0x01,
        ActiveItem = 0x02,

        Road = 0x10,
        Pean = 0x20,
        Wall = 0x40,
        GhostHome = 0x80,
    };

    CItem(void);
    virtual ~CItem(void);
    virtual void Show() = 0;

};

