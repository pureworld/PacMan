#include "GhostHome.h"


CGhostHome::CGhostHome(void)
{
    m_nType |= CItem::GhostHome;
}


CGhostHome::~CGhostHome(void)
{
}

void CGhostHome::Show() {
    cout << "* ";
}
