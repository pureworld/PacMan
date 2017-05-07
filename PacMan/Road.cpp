#include "Road.h"


CRoad::CRoad(int nRow, int nCol) {
    m_pPdc = CPdcCurses::GetCurses();
    m_nRowPos = nRow;
    m_nColPos = nCol;
    m_nCollisionLv = 0;
}


CRoad::~CRoad(void)
{
}


void CRoad::Show(void)
{
    m_pPdc->PrintCharAt(m_nRowPos, m_nColPos,
        ACS_BLOCK|COLOR_PAIR(0)|A_BOLD);
}
