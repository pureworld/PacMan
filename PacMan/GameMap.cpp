#include "GameMap.h"


int  CGameMap::g_Map[ROW][COL] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,
    1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,
    1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,
    1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,
    1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,
    1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,
    1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,
    1,1,1,1,1,1,0,1,1,0,1,1,1,2,2,1,1,1,0,1,1,0,1,1,1,1,1,1,
    1,1,1,1,1,1,0,1,1,0,1,2,2,2,2,2,2,1,0,1,1,0,1,1,1,1,1,1,
    0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,
    1,1,1,1,1,1,0,1,1,0,1,2,2,2,2,2,2,1,0,1,1,0,1,1,1,1,1,1,
    1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,
    1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,
    1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,
    1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,3,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,
    1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,
    1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,
    1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,
    1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,
    1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,
    1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
    1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

CGameMap::CGameMap(void)
{
    m_pPdc = CPdcCurses::GetCurses();
    for (int i = 0; i < ROW * COL + 5; i++) {
        m_pItem[i] = NULL;
    }
    InitMap();
}


CGameMap::~CGameMap(void)
{
    for (int i = 0; i < ROW * COL; i++) {
            if (m_pItem[i] != NULL) {
                delete m_pItem[i];
                m_pItem[i] = NULL;
            }
    }
    for (int i = ROW * COL; i < ROW * COL + 5; i++) {
        if (m_pItem[i] != NULL) {
            m_pItem[i] = NULL;
        }
    }
}

int CGameMap::InitMap() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == 0 && j ==0) {
                m_pItem[0] = new CRoad(i, j);
            } else if (CGameMap::g_Map[i][j] == CItem::ITEM_PEAN) {
                m_pItem[i * COL +j] = new CPean(i, j);
            } else if (CGameMap::g_Map[i][j] == CItem::ITEM_WALL) {
                m_pItem[i * COL +j] = new CWall(i, j);
            } else if (CGameMap::g_Map[i][j] == CItem::ITEM_GHOME) {
                m_pItem[i * COL +j] = new CGHome(i, j);
            } else if (CGameMap::g_Map[i][j] == CItem::ITEM_ROAD) {
                m_pItem[i * COL + j] = new CRoad(i, j);
            }
        }
    }
    m_pItem[ROW * COL] = NULL;
    m_pItem[ROW * COL + 1] = NULL;
    m_pItem[ROW * COL + 2] = NULL;
    m_pItem[ROW * COL + 3] = NULL;
    m_pItem[ROW * COL + 4] = NULL;
    return 1;
}

int CGameMap::ShowMap() {
    for (int i = 0; i < ROW * COL + 5; i++) {
        if (m_pItem[i] != NULL) {
            m_pItem[i]->Show();
        }
    }
    m_pPdc->PrintfAt(ROW + 1, 0, "press \'l\' to replay");
    m_pPdc->Refresh();
    return 1;
}

// int CGameMap::Flush(CActiveItem* obj) {
//     if (m_pItem[obj->GetRow()][obj->GetCol()] == obj) {
//         return 1;
//    }
 //   if (m_pItem[obj->GetRow()][obj->GetCol()] != NULL) {
 //       delete m_pItem[obj->GetRow()][obj->GetCol()];
 //   }
  //  m_pItem[obj->GetRow()][obj->GetCol()] = obj;
  //  m_pItem[obj->GetLastRow()][obj->GetLastCol()] =
  //      new CRoad(obj->GetLastRow(), obj->GetLastCol());
  //  return 1;
//}

CItem* CGameMap::operator[](int nIndex) {
    return m_pItem[nIndex];
}
