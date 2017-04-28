#pragma once
#include "activeitem.h"
class CGhost :
    public CActiveItem
{
public:
    CGhost(void);
    ~CGhost(void);

    void Show();
    void Move(int, int);

    void AutoTrace();
};

