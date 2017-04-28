#include "Ghost.h"


CGhost::CGhost(void) : CActiveItem(13, 14, 2)
{
}


CGhost::~CGhost(void)
{
}

void CGhost::Show() {
    cout << "¹í";
}

void CGhost::Move(int, int) {

}

void CGhost::AutoTrace() {

}
