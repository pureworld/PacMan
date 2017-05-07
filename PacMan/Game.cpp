#include "Game.h"


CGame::CGame(void)
{
    m_pPdc = CPdcCurses::GetCurses();
    m_pMap = new CGameMap();
    m_pPlayer = new CPlayer(20, 12);
    m_pBlinky = new CBlinky(13, 11);
    m_pPinky = new CPinky(13, 16);
    m_pInky = new CInky(15, 11);
    m_pClyde = new CClyde(15, 16);

    m_pMap->SetItem(ROW * COL, m_pPlayer);
    m_pMap->SetItem(ROW * COL + 1, m_pBlinky);
    m_pMap->SetItem(ROW * COL + 2, m_pPinky);
    m_pMap->SetItem(ROW * COL + 3, m_pInky);
    m_pMap->SetItem(ROW * COL + 4, m_pClyde);

    m_pBlinky->SetCPlayer(m_pPlayer);
    m_pPinky->SetCPlayer(m_pPlayer);
    m_pInky->SetCPlayer(m_pPlayer);
    m_pClyde->SetCPlayer(m_pPlayer);
    StartGame();
}


CGame::~CGame(void)
{
    if (m_pPlayer != NULL) {
        delete m_pPlayer;
        m_pPlayer = NULL;
    }
    if (m_pBlinky != NULL) {
        delete m_pBlinky;
        m_pBlinky = NULL;
    }
    if (m_pInky != NULL) {
        delete m_pInky;
        m_pInky = NULL;
    }
    if (m_pClyde != NULL) {
        delete m_pClyde;
        m_pClyde = NULL;
    }
    if (m_pPinky != NULL) {
        delete m_pPinky;
        m_pPinky = NULL;
    }

    if (m_pMap != NULL) {
        delete m_pMap;
        m_pMap = NULL;
    }
}

void CGame::StartGame() {
    m_pMap->ShowMap();
    m_pPdc->PrintfAt(ROW / 2, 0, 
        "1.New Game\n2.RePlay\ninput number to choose function");
    m_pPdc->Refresh();
    char ch;
    ch = _getch();
    if (ch == '1') {
        MainLoop();
    } else {
        Replay();
    }
}

void CGame::MainLoop() {
    char chCmd = '\0';
    clock_t clkStart = clock();
    clock_t clkStart2 = clock();
    clock_t clkStart3 = clock();
    clock_t clkCurtime = 0;

    while(1) {
        clkCurtime = clock();

        if (clkCurtime - clkStart > 1000) {
            m_pBlinky->AutoTrace();
            m_pPinky->AutoTrace();
            m_pInky->AutoTrace();
            m_pClyde->AutoTrace();
            Update();
            clkStart = clkCurtime;
        }

        if (clkCurtime - clkStart2 > 1000) {
            switch(m_pPlayer->GetDir()) {
            case CActiveItem::DIR_LEFT:
                if (CanMove(0, -1, m_pPlayer)) {
                    m_pPlayer->Move(0, -1);
                }
                break;
            case CActiveItem::DIR_UP:
                if (CanMove(-1, 0, m_pPlayer)) {
                    m_pPlayer->Move(-1, 0);
                }
                break;
            case CActiveItem::DIR_DOWN:
                if (CanMove(1, 0, m_pPlayer)) {
                    m_pPlayer->Move(1, 0);
                }
                break;
            case CActiveItem::DIR_RIGHT:
                if (CanMove(0, 1, m_pPlayer)) {
                    m_pPlayer->Move(0, 1);
                }
                break;
            }            
            if (CGameMap::g_Map[m_pPlayer->GetRow()][m_pPlayer->GetCol()] == CItem::ITEM_PEAN) {
                m_pPlayer->EatBean();
                m_pMap->SetItem(m_pPlayer->GetRow() * COL + m_pPlayer->GetCol(),
                    new CRoad(m_pPlayer->GetRow(), m_pPlayer->GetCol()));
                CGameMap::g_Map[m_pPlayer->GetRow()][m_pPlayer->GetCol()] = CItem::ITEM_ROAD;
            }
            Update();
            clkStart2 = clkCurtime;
        }

        if (clkCurtime - clkStart3 > 10) {
            if ((m_pPlayer->GetRow() == m_pBlinky->GetRow() 
                && m_pPlayer->GetCol() == m_pBlinky->GetCol()) 
                || (m_pPlayer->GetRow() == m_pPinky->GetRow() 
                && m_pPlayer->GetCol() == m_pPinky->GetCol()) 
                || (m_pPlayer->GetRow() == m_pInky->GetRow() 
                && m_pPlayer->GetCol() == m_pInky->GetCol()) 
                || (m_pPlayer->GetRow() == m_pClyde->GetRow() 
                && m_pPlayer->GetCol() == m_pClyde->GetCol())) {
                m_pPdc->PrintfAt(m_pPdc->GetWidth() / 2,
                    m_pPdc->GetHeight() / 2, "-----YOU LOSE!!!!-----");
                m_pPdc->Refresh();
                break;
            }
            clkStart3 = clkCurtime;
        }

        if (_kbhit() != 0) {
            chCmd = _getch();
            switch(chCmd) {
            case 'a':
                m_pPlayer->SetDir(CActiveItem::DIR_LEFT);
                break;
            case 'w':
                m_pPlayer->SetDir(CActiveItem::DIR_UP);
                break;
            case 's':
                m_pPlayer->SetDir(CActiveItem::DIR_DOWN);
                break;
            case 'd':
                m_pPlayer->SetDir(CActiveItem::DIR_RIGHT);
                break;
            }
        }
    }
}

void CGame::Replay() {
    
}

void CGame::Update() {
    m_pPdc->ClearWin();
    //m_pMap->Flush(obj);
    m_pMap->ShowMap();
}

bool CGame::CanMove(int nRowChange, int nColChange, CActiveItem* pObj) {
    int nTmpRow = (pObj->GetRow() + nRowChange) % ROW;
    int nTmpCol = (pObj->GetCol() + nColChange) % COL;
    if (nTmpRow < 0) {
        nTmpRow += ROW;
    }
    if (nTmpCol < 0) {
        nTmpCol += COL;
    }

    if (CGameMap::g_Map[nTmpRow][nTmpCol] == 1 ||
        CGameMap::g_Map[nTmpRow][nTmpCol] == 2) {
            return false;
    }
    return true;
}