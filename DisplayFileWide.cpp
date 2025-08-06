#include "DisplayFileWide.h"

void DisplayFileWide::put(char c) {
    /* ‚±‚±‚ðŽÀ‘•‚µ‚Ä‚­‚¾‚³‚¢ */
    stream() << c << c;
}