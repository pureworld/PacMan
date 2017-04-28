#pragma once
#include "activeitem.h"
class CPlayer :
    public CActiveItem
{
public:
    CPlayer(void);
    ~CPlayer(void);

    void Show();
    void Move(int, int);
};

