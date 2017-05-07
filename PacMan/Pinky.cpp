#include "Pinky.h"
#include "GameMap.h"

CPinky::CPinky(int nRow, int nCol)
{
    m_nRowPos = nRow;
    m_nColPos = nCol;
}


CPinky::~CPinky(void)
{
}

void CPinky::Show() {
    m_pPdc->PrintCharAt(m_nRowPos, m_nColPos,
        ACS_LANTERN|COLOR_PAIR(4)|A_BOLD);
}

void CPinky::AutoTrace() {
    node temp;
    int nTarRow;
    int nTarCol;
    switch (m_pPlayer->GetDir()) {
    case DIR_UP:
        nTarRow = m_pPlayer->GetRow() - 4;
        if (nTarRow < 0) {
            nTarRow += ROW;
        }
        nTarCol = m_pPlayer->GetCol();
        while (CGameMap::g_Map[nTarRow][nTarCol] == CItem::ITEM_WALL) {
            nTarCol--;
            if (nTarCol < 0) {
                nTarCol += COL;
            }
            if (nTarCol == m_pPlayer->GetCol()) {
                nTarRow--;
                if (nTarRow < 0) {
                    nTarRow += ROW;
                }
            }
        }
        temp = GetPath(m_nRowPos, m_nColPos, nTarRow, nTarCol);
        break;
    case DIR_RIGHT:
        nTarRow = m_pPlayer->GetRow();
        nTarCol = (m_pPlayer->GetCol() + 4) % COL;
        while (CGameMap::g_Map[nTarRow][nTarCol] == CItem::ITEM_WALL) {
            nTarRow--;
            if (nTarRow < 0) {
                nTarRow += ROW;
            }
            if (nTarRow == m_pPlayer->GetRow()) {
                nTarCol = (nTarCol + 1) % COL;
            }
        }
        temp = GetPath(m_nRowPos, m_nColPos, nTarRow, nTarCol);
        break;
    case DIR_DOWN:
        nTarRow = (m_pPlayer->GetRow() + 4) % ROW;
        nTarCol = m_pPlayer->GetCol();
        while (CGameMap::g_Map[nTarRow][nTarCol] == CItem::ITEM_WALL) {
            nTarCol = (nTarCol + 1) % COL;
            if (nTarCol == m_pPlayer->GetCol()) {
                nTarRow = (nTarRow + 1) % ROW;
            }
        }
        temp = GetPath(m_nRowPos, m_nColPos, nTarRow, nTarCol);
        break;
    case DIR_LEFT:
        nTarRow = m_pPlayer->GetRow();
        nTarCol = m_pPlayer->GetCol() - 4;
        if (nTarCol < 0) {
            nTarCol += COL;
        }
        while (CGameMap::g_Map[nTarRow][nTarCol] == CItem::ITEM_WALL) {
            nTarRow--;
            if (nTarRow < 0) {
                nTarRow += ROW;
            }
            if (nTarRow == m_pPlayer->GetRow()) {
                nTarCol--;
                if (nTarCol < 0) {
                    nTarCol += COL;
                }
            }
        }
        temp = GetPath(m_nRowPos, m_nColPos, nTarRow, nTarCol);
        break;
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

