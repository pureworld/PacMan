#pragma once
#include "item.h"
class CActiveItem :
    public CItem
{
public:
    CActiveItem(int nRow, int nCol, int nLevel);
    virtual ~CActiveItem(void);

    virtual void Show() = 0;
    virtual void Move(int, int) = 0;

    inline int GetRow() { return m_nRow; }
    inline int GetCol() { return m_nCol; }
    inline int GetLevel() { return m_nLevel; }
    inline int GetLastRow() { return m_nLastRow; }
    inline int GetLastCol() { return m_nLastCol; }
protected:
    int m_nRow;
    int m_nCol;
    int m_nLastRow;
    int m_nLastCol;
    int m_nLevel;
};

