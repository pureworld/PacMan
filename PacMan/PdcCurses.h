#pragma once
#include "curses.h"

class CPdcCurses {
public:
    static CPdcCurses* GetCurses();
    bool Init();
    bool CreateNewWin();
    bool ReleaseWin();
    int ClearWin();

    int Printf(const char* pfmt, ...);
    int MoveCursorTo(int nRow, int nCol);
    int PrintfAt(int nRow, int nCol, const char* pfmt, ...);
    int PrintCharAt(chtype chValue);
    int PrintCharAt(int nRow, int nCol, chtype chValue);
    int Refresh();

    int ColorOn(chtype attrType);
    int ColorOff(chtype attrType);

    inline int GetHeight() { return m_nHeight; }
    inline int GetWidth() { return m_nWidth; }
    inline WINDOW* GetWin() { return m_pWin; }

    friend CPdcCurses& operator<<(CPdcCurses&, int);
private:
    CPdcCurses();
    CPdcCurses(CPdcCurses&);
    ~CPdcCurses();
    CPdcCurses& operator=(CPdcCurses&);
    
    static CPdcCurses* m_pInstance;
    WINDOW* m_pWin;
    int m_nHeight;
    int m_nWidth;
};

