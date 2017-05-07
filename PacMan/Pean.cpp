#include "Pean.h"


CPean::CPean(int nRow, int nCol) {
    m_pPdc = CPdcCurses::GetCurses();
    m_nRowPos = nRow;
    m_nColPos = nCol;
    m_nCollisionLv = 0;
}


CPean::~CPean(void)
{
}


void CPean::Show(void)
{
    m_pPdc->PrintCharAt(m_nRowPos, m_nColPos,
        0xb0|COLOR_PAIR(1)|A_BOLD);
}
