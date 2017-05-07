#include "Blinky.h"


CBlinky::CBlinky(int nRow, int nCol)
{
    m_nRowPos = nRow;
    m_nColPos = nCol;
}


CBlinky::~CBlinky(void)
{
}

void CBlinky::Show() {
    m_pPdc->PrintCharAt(m_nRowPos, m_nColPos,
        ACS_LANTERN|COLOR_PAIR(2));
}

void CBlinky::AutoTrace() {
    node temp = GetPath(m_nRowPos, m_nColPos,
        m_pPlayer->GetRow(), m_pPlayer->GetCol());
    int nRowCh = temp.x - m_nRowPos;
    int nColCh = temp.y - m_nColPos;

    Move(nRowCh, nColCh);
}

