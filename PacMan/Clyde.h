#pragma once
#include "ghost.h"
/*
�ȹ� ��
����8�����ϣ������ΪĿ�꣬
���ڳ��Ž���ǰ��
*/
class CClyde :
    public CGhost
{
public:
    CClyde(int nRow, int nCol);
    ~CClyde(void);

    void Show();
    void AutoTrace();
};

