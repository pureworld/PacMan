#include "Inky.h"
#include "GameMap.h"

CInky::CInky(int nRow, int nCol)
{
    m_nRowPos = nRow;
    m_nColPos = nCol;
}


CInky::~CInky(void)
{
}

void CInky::Show() {
    m_pPdc->PrintCharAt(m_nRowPos, m_nColPos,
        ACS_LANTERN|COLOR_PAIR(1)|A_BOLD);
}

void CInky::AutoTrace() {
    //先找中间点，然后找到目标点
    int nInterRow;
    int nInterCol;
    int nTarRow;
    int nTarCol;
    node temp;
    switch (m_pPlayer->GetDir()) {
    case DIR_UP:
        //找到中间点
        nInterRow = m_pPlayer->GetRow() - 4;
        if (nInterRow < 0) {
            nInterRow += ROW;
        }
        nInterCol = m_pPlayer->GetCol();
        //中间点为墙的处理
        while (CGameMap::g_Map[nInterRow][nInterCol] == CItem::ITEM_WALL) {
            nInterCol--;
            if (nInterCol < 0) {
                nInterCol += COL;
            }
            if (nInterCol == m_pPlayer->GetCol()) {
                nInterRow--;
                if (nInterRow < 0) {
                    nInterRow += ROW;
                }
            }
        }
        //找到目标点
        nTarRow = (2 * nInterRow - m_nRowPos) % ROW;
        nTarCol = (2 * nInterCol - m_nColPos) % COL;
        if (nTarRow < 0) {
            nTarRow += ROW;
        }
        if (nTarCol < 0) {
            nTarCol += COL;
        }
        //目标点为墙的处理
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
        nInterRow = m_pPlayer->GetRow();
        nInterCol = (m_pPlayer->GetCol() + 4) % COL;
        while (CGameMap::g_Map[nInterRow][nInterCol] == CItem::ITEM_WALL) {
            nInterRow--;
            if (nInterRow < 0) {
                nInterRow += ROW;
            }
            if (nInterRow == m_pPlayer->GetRow()) {
                nInterCol = (nInterCol + 1) % COL;
            }
        }
        nTarRow = (2 * nInterRow - m_nRowPos) % ROW;
        nTarCol = (2 * nInterCol - m_nColPos) % COL;
        if (nTarRow < 0) {
            nTarRow += ROW;
        }
        if (nTarCol < 0) {
            nTarCol += COL;
        }
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
        nInterRow = (m_pPlayer->GetRow() + 4) % ROW;
        nInterCol = m_pPlayer->GetCol();
        while (CGameMap::g_Map[nInterRow][nInterCol] == CItem::ITEM_WALL) {
            nInterCol = (nInterCol + 1) % COL;
            if (nInterCol == m_pPlayer->GetCol()) {
                nInterRow = (nInterRow + 1) % ROW;
            }
        }
        nTarRow = (2 * nInterRow - m_nRowPos) % ROW;
        nTarCol = (2 * nInterCol - m_nColPos) % COL;
        if (nTarRow < 0) {
            nTarRow += ROW;
        }
        if (nTarCol < 0) {
            nTarCol += COL;
        }
        while (CGameMap::g_Map[nTarRow][nTarCol] == CItem::ITEM_WALL) {
            nTarCol = (nTarCol + 1) % COL;
            if (nTarCol == m_pPlayer->GetCol()) {
                nTarRow = (nTarRow + 1) % ROW;
            }
        }
        temp = GetPath(m_nRowPos, m_nColPos, nTarRow, nTarCol);
        break;
    case DIR_LEFT:
        nInterRow = m_pPlayer->GetRow();
        nInterCol = m_pPlayer->GetCol() - 4;
        if (nInterCol < 0) {
            nInterCol += COL;
        }
        while (CGameMap::g_Map[nInterRow][nInterCol] == CItem::ITEM_WALL) {
            nInterRow--;
            if (nInterRow < 0) {
                nInterRow += ROW;
            }
            if (nInterRow == m_pPlayer->GetRow()) {
                nInterCol--;
                if (nInterCol < 0) {
                    nInterCol += COL;
                }
            }
        }
        nTarRow = (2 * nInterRow - m_nRowPos) % ROW;
        nTarCol = (2 * nInterCol - m_nColPos) % COL;
        if (nTarRow < 0) {
            nTarRow += ROW;
        }
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
    //找移动改变量
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
    //移动
    Move(nRowCh, nColCh);
}

