#include "DisplayScreen.h"

void DisplayScreen::start() {
}

void DisplayScreen::end() {
}

void DisplayScreen::put(char c) {
    stream() << c;
}

void DisplayScreen::newLine() {
    stream() << std::endl;
}

std::ostream& DisplayScreen::stream() {
    return std::cout;
}