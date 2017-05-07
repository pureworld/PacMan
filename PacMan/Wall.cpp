#include "Wall.h"


CWall::CWall(int nRow, int nCol) {
    m_pPdc = CPdcCurses::GetCurses();
    m_nRowPos = nRow;
    m_nColPos = nCol;
    m_nCollisionLv = 1;
}


CWall::~CWall(void)
{
}

void CWall::Show() {
    m_pPdc->PrintCharAt(m_nRowPos, m_nColPos,
        ACS_BLOCK|COLOR_PAIR(1)|A_BOLD);
}
