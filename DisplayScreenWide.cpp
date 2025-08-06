#include "DisplayScreenWide.h"

void DisplayScreenWide::put(char c) {
    stream() << c << c;
}