#include "Ghost.h"
#include "GameMap.h"

int map[ROW][COL];
int dir[4][2]={0,1,1,0,0,-1,-1,0};  
struct node a[500];
struct node1  
{  
    int px;  
    int py;  
}prev1[ROW][COL];  

double CGhost::Distance(int nRow, int nCol) {
    return sqrt((double)((nRow - m_pPlayer->GetRow()) *
        (nRow - m_pPlayer->GetRow())
        + (nCol - m_pPlayer->GetCol()) * (nCol - m_pPlayer->GetCol())));
}



int bfs(int nStartRow, int nStartCol, int nEndRow, int nEndCol)  
{   
    a[0].x=nStartRow;  
    a[0].y=nStartCol;  
    a[0].step=0;  
    node cur,change;  
    int start=0,end=1;  
    while(start<end)  
    {  
        cur=a[start++];  
        if(cur.x==nEndRow && cur.y==nEndCol)  
            return cur.step;  
        for(int i=0;i<4;i++)  
        {  
            int tx=cur.x+dir[i][0];  
            int ty=cur.y+dir[i][1];  
            if(tx>=0 && tx< ROW && ty>=0 && ty<COL && map[tx][ty]==0)  
            {  
                map[tx][ty]=1;  
                change.x=tx;  
                change.y=ty;  
                change.step=cur.step+1;  
                a[end++]=change;  
                prev1[tx][ty].px=cur.x;  
                prev1[tx][ty].py=cur.y;  
            }  
        }  
    }  
}  

node GetPath(int nStartRow, int nStartCol, int nEndRow, int nEndCol) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (CGameMap::g_Map[i][j] == CItem::ITEM_WALL) {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }

    int sum=bfs(nStartRow, nStartCol, nEndRow, nEndCol);  
    //printf("*%d\n",sum);  
    node ans[500];  
    int ex=nEndRow,ey=nEndCol;  
    for(int i=0;i<sum;i++)  
    {  
        ans[i].x=prev1[ex][ey].px;  
        ans[i].y=prev1[ex][ey].py;  
        ex=ans[i].x;  
        ey=ans[i].y;  
    } 

    return ans[sum-2];
}