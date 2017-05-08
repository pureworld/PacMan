#pragma once
#include "GameMap.h"
#include <ctime>

#include <cstdlib>
#include "MyList.h"
class CGame
{
public:
    CGame(void);
    ~CGame(void);
    void StartGame();
    void MainLoop();
    void Replay();
    void SaveFile();
    void Update();
    bool CanMove(int, int, CActiveItem*);
private:
    CPdcCurses* m_pPdc;
    CGameMap* m_pMap;
    CPlayer* m_pPlayer;
    CBlinky* m_pBlinky;
    CPinky* m_pPinky;
    CInky* m_pInky;
    CClyde* m_pClyde;

    CMyList<CPlayer> m_PlayerList;
    CMyList<CBlinky> m_BlinkyList;
    CMyList<CPinky> m_PinkyList;
    CMyList<CInky> m_InkyList;
    CMyList<CClyde> m_ClydeList;
};

