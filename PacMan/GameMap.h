#pragma once
#include "Wall.h"
#include "Road.h"
#include "Pean.h"
#include "GHome.h"
#include "Player.h"
#include "Blinky.h"
#include "Pinky.h"
#include "Inky.h"
#include "Clyde.h"

class CGameMap
{
public:
    CGameMap(void);
    ~CGameMap(void);
    int InitMap();
    int ShowMap();
    //int Flush(CActiveItem*);

    void SetItem(int nIndex, CItem* obj) {
        if (m_pItem[nIndex != NULL]) {
            delete m_pItem[nIndex];
        }
        m_pItem[nIndex] = obj;
    }
// 
    CItem* GetItem(int n) {
        return m_pItem[n];
    }
   CItem* operator[](int);
private:
    CItem* m_pItem[ROW * COL + 4 + 1];
    CPdcCurses* m_pPdc;
public:
    static int g_Map[ROW][COL];
};

