#pragma once
#include "stillitem.h"
class CGHome :
    public CStillItem
{
public:

    CGHome(int nRow, int nCol)
    {
        m_pPdc = CPdcCurses::GetCurses();
        m_nRowPos = nRow;
        m_nColPos = nCol;
        m_nCollisionLv = 1;
    }

    ~CGHome(void)
    {
    }

    void Show(void)
    {
        m_pPdc->PrintCharAt(m_nRowPos, m_nColPos,
            ACS_BLOCK|COLOR_PAIR(5)|A_BOLD);
    }
};

