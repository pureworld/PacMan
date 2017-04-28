#include "Player.h"


CPlayer::CPlayer(void) : CActiveItem(20, 12, 1)
{
}


CPlayer::~CPlayer(void)
{
}

void CPlayer::Show() {
    cout << "人";
}

void CPlayer::Move(int nRowCh, int nColCh) {
    m_nLastRow = m_nRow;
    m_nLastCol = m_nCol;
    m_nRow = (m_nRow + nRowCh) % ROW;
	m_nCol = (m_nCol + nColCh) % COL;
	if (m_nRow < 0) {
	     m_nRow += ROW;
	}
	if (m_nCol < 0) {
	     m_nCol += COL;
	}
}
