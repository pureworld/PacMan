/*
可动Item，玩家和4个幽灵
*/
#pragma once
#include "item.h"
class CActiveItem :
    public CItem
{
public:
    enum DIR {
        DIR_UP,
        DIR_RIGHT,
        DIR_DOWN,
        DIR_LEFT
    };

    CActiveItem(void);
    virtual ~CActiveItem(void);

    virtual void Show() = 0;
    virtual void Move(int nRowCh, int nColCh) {
        m_nLastRow = m_nRowPos;
        m_nLastCol = m_nColPos;
        m_nRowPos = (m_nRowPos + nRowCh) % ROW;
        m_nColPos = (m_nColPos + nColCh) % COL;
        if (m_nRowPos < 0) {
            m_nRowPos += ROW;
        }
        if (m_nColPos < 0) {
            m_nColPos += COL;
        }
    }

    inline int GetRow() { return m_nRowPos; }
    inline int GetCol() { return m_nColPos; }
    inline int GetLevel() { return m_nCollisionLv; }
    inline int GetDir() { return m_nDir; }
    inline int GetLastRow() { return m_nLastRow; }
    inline int GetLastCol() { return m_nLastCol; }
    inline void SetDir(DIR dir) { m_nDir = dir; }
protected:
    DIR m_nDir;
    int m_nLastRow;
    int m_nLastCol;
};

