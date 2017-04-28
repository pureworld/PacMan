#include "Wall.h"


CWall::CWall(void)
{
    m_nType |= CItem::Wall;
}


CWall::~CWall(void)
{
}

void CWall::Show() {
    cout << "¨~";
}
