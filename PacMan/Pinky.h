#pragma once
#include "ghost.h"
/*
��ɫ
����ҵ�ǰ����ǰ4��λ��ΪĿ��
*/
class CPinky :
    public CGhost
{
public:
    CPinky(int nRow, int nCol);
    ~CPinky(void);

    void Show();
    void AutoTrace();
};

