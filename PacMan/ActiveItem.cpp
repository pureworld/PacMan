#include "ActiveItem.h"


CActiveItem::CActiveItem(int nRow, int nCol, int nLevel) :
    m_nRow(nRow), m_nCol(nCol), m_nLevel(nLevel),
    m_nLastRow(-1), m_nLastCol(-1) {
        m_nType |= CItem::ActiveItem;
}


CActiveItem::~CActiveItem(void)
{
}

