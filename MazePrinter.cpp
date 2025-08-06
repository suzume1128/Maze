#include "MazePrinter.h"

MazePrinter::MazePrinter(Display* display) {
    this->display = display;
}

void MazePrinter::output(MazeMap* mazeMap) {
    display->start(); // 表示前処理
    for (int y = 0; y < mazeMap->getHeight(); ++y) {
        for (int x = 0; x < mazeMap->getWidth(); ++x) {
            display->put(mazeMap->get(x, y)); // １文字表示処理
        }
        display->newLine(); // 改行処理
    }
    display->end(); //  表示後処理
}