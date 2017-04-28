#include "Road.h"


CRoad::CRoad(void)
{
    m_nType |= CItem::Road;
}


CRoad::~CRoad(void)
{
}

void CRoad::Show() {
    cout << "  ";
}
