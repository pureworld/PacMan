#pragma once
#include "item.h"
class CStillItem :
    public CItem
{
public:
    CStillItem(void);
    virtual ~CStillItem(void);
    virtual void Show() = 0;
};

