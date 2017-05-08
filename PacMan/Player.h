#pragma once
#include "activeitem.h"
class CPlayer :
    public CActiveItem
{
public:
    CPlayer() { }
    CPlayer(int nRow, int nCol);
    virtual ~CPlayer();

    void Show();
    void EatBean();

private:
    int m_nScore;
};

