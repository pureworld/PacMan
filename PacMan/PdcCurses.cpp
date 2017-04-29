#include "PdcCurses.h"

CPdcCurses::CPdcCurses(void) {
    initscr();
    start_color();
    Init();
}

CPdcCurses::~CPdcCurses(void) {
    ReleaseWin();
}

CPdcCurses* CPdcCurses::m_pInstance = NULL;

CPdcCurses* CPdcCurses::GetCurses() {
    if (m_pInstance == NULL) {
        m_pInstance = new CPdcCurses();
    }
    return m_pInstance;
}

bool CPdcCurses::Init() {
    m_pWin = NULL;
    
    init_pair(1, COLOR_BLUE, COLOR_WHITE);
    init_pair(2, COLOR_RED, COLOR_WHITE);
    init_pair(3, COLOR_YELLOW, COLOR_WHITE);
    init_pair(4, COLOR_CYAN, COLOR_WHITE);

    return CreateNewWin();
}

bool CPdcCurses::CreateNewWin() {
    ReleaseWin();
    m_pWin = newwin(0, 0, 0, 0);
    if (m_pWin == NULL) {
        return false;
    }
    getmaxyx(m_pWin, m_nHeight, m_nWidth);
    return true;
}

bool CPdcCurses::ReleaseWin() {
    if (m_pWin == NULL) {
        return true;
    }
    delwin(m_pWin);
    m_pWin = NULL;
    return true;
}

int CPdcCurses::ClearWin() {
    if (m_pWin == NULL) {
        return true;
    }
    return wclear(m_pWin);
}

int CPdcCurses::Printf(const char* pfmt, ...) {
    if (m_pWin == NULL) {
        return -1;
    }

    va_list args;
    va_start(args, pfmt);
    int nRet = vwprintw(m_pWin, pfmt, args);
    va_end(args);

    return nRet;
}

int CPdcCurses::MoveCursorTo(int nRow, int nCol) {
    if (m_pWin == NULL) {
        return -1;
    }
    return wmove(m_pWin, nRow, nCol);
}

int CPdcCurses::PrintfAt(int nRow, int nCol, const char* pfmt, ...) {
    if (m_pWin == NULL) {
        return -1;
    }
    MoveCursorTo(nRow, nCol);
    va_list args;
    va_start(args, pfmt);
    int nRet = vwprintw(m_pWin, pfmt, args);
    va_end(args);

    return nRet;
}

int CPdcCurses::PrintCharAt(chtype chValue) {
    if (m_pWin == NULL) {
        return -1;
    }
    return waddch(m_pWin, chValue);
}

int CPdcCurses::PrintCharAt(int nRow, int nCol, chtype chValue) {
    if (m_pWin == NULL) {
        return -1;
    }
    return mvwaddch(m_pWin, nRow, nCol, chValue);
}

int CPdcCurses::Refresh() {
    if (m_pWin == NULL) {
        return false;
    }
    return wrefresh(m_pWin);
}

int CPdcCurses::ColorOn(chtype attrType)
{
    if (m_pWin == NULL) {
        return false;
    }
    return wattron(m_pWin, attrType);
}

int CPdcCurses::ColorOff(chtype attrType) {
    if (m_pWin == NULL) {
        return false;
    }
    return wattroff(m_pWin, attrType);
}

CPdcCurses& operator<<(CPdcCurses& obj, int nInt) {
    obj.Printf("%d", nInt);
    return obj;
}
