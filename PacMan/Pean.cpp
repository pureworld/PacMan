#include "Pean.h"


CPean::CPean(void)
{
    m_nType |= CItem::Pean;
}


CPean::~CPean(void)
{
}

void CPean::Show() {
    cout << ". ";
}