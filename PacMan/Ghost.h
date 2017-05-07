#pragma once
#include "activeitem.h"
#include "Player.h"
struct node  
{  
    int x;  
    int y;  
    int step;  
};
node GetPath(int nStartRow, int nStartCol, int nEndRow, int nEndCol);
class CGhost :
    public CActiveItem
{
public:

    CGhost(void)
    {
        m_pPdc = CPdcCurses::GetCurses();
        m_pPlayer = NULL;
    }

    virtual ~CGhost(void)
    {
    }

    double Distance(int nRow, int nCol);

    inline void SetCPlayer(CPlayer* obj) {
        m_pPlayer = obj;
    }

    virtual void Show() = 0;
    virtual void AutoTrace() = 0;
protected:
    CPlayer* m_pPlayer;
};
