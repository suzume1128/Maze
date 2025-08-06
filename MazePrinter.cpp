#include "MazePrinter.h"

MazePrinter::MazePrinter(Display* display) {
    this->display = display;
}

void MazePrinter::output(MazeMap* mazeMap) {
    display->start(); // �\���O����
    for (int y = 0; y < mazeMap->getHeight(); ++y) {
        for (int x = 0; x < mazeMap->getWidth(); ++x) {
            display->put(mazeMap->get(x, y)); // �P�����\������
        }
        display->newLine(); // ���s����
    }
    display->end(); //  �\���㏈��
}