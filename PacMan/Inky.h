#pragma once
#include "ghost.h"
/*
��ɫ
�ͺ��������е������ǰ����λ
*/
class CInky :
    public CGhost
{
public:
    CInky(int nRow, int nCol);
    ~CInky(void);

    void Show();
    void AutoTrace();
};

