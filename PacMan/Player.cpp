#include "Player.h"


CPlayer::CPlayer(int nRow, int nCol) {
    m_pPdc = CPdcCurses::GetCurses();
    m_nRowPos = nRow;
    m_nColPos = nCol;
    m_nCollisionLv = 1;
    m_nScore = 0;
    m_nDir = DIR_LEFT;
}


CPlayer::~CPlayer(void)
{
}

void CPlayer::Show() {
    m_pPdc->PrintCharAt(m_nRowPos, m_nColPos,
        ACS_SBSS|COLOR_PAIR(5)|A_BOLD);
    m_pPdc->PrintfAt(ROW , 0, "Score : %d\n", m_nScore);
}

void CPlayer::EatBean() {
    m_nScore += 10;
}
 