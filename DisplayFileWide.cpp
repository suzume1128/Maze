#include "DisplayFileWide.h"

void DisplayFileWide::put(char c) {
    /* �������������Ă������� */
    stream() << c << c;
}