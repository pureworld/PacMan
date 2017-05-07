#include "Clyde.h"


CClyde::CClyde(int nRow, int nCol)
{
    m_nRowPos = nRow;
    m_nColPos = nCol;
}


CClyde::~CClyde(void)
{
}

void CClyde::Show() {
    m_pPdc->PrintCharAt(m_nRowPos, m_nColPos,
        ACS_LANTERN|COLOR_PAIR(3)|A_BOLD);
}

void CClyde::AutoTrace() {
    int nDistance = sqrt((double)((m_nRowPos - m_pPlayer->GetRow())
        * (m_nRowPos - m_pPlayer->GetRow())
        + (m_nColPos - m_pPlayer->GetCol())
        * (m_nColPos - m_pPlayer->GetCol())));
    node temp;
    if (nDistance >= 8) {//以玩家为目标
        temp = GetPath(m_nRowPos, m_nColPos,
            m_pPlayer->GetRow(), m_pPlayer->GetCol());
    } else {//nDistance < 8 以角落为目标
        if (m_nRowPos < ROW / 2 && m_nColPos < COL / 2) {
            temp = GetPath(m_nRowPos, m_nColPos, 1, 1);
        } else if (m_nRowPos < ROW / 2 && m_nColPos >= COL / 2) {
            temp = GetPath(m_nRowPos, m_nColPos, 1, COL - 2);
        } else if (m_nRowPos >= ROW / 2 && m_nColPos < COL / 2) {
            temp = GetPath(m_nRowPos, m_nColPos, ROW - 2, 1);
        } else {//m_nRowPos >= ROW / 2 && m_nColPos >= COL / 2
            temp = GetPath(m_nRowPos, m_nColPos, ROW - 2, COL - 2);
        }
    }
    int nRowCh = temp.x - m_nRowPos;
    int nColCh = temp.y - m_nColPos;
    if (nRowCh > 0) {
        nRowCh = 1;
    }
    if (nRowCh < 0) {
        nRowCh = -1;
    }
    if (nColCh > 0) {
        nColCh = 1;
    }
    if (nColCh < 0) {
        nColCh = -1;
    }

    Move(nRowCh, nColCh);
}
