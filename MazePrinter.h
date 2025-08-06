#ifndef MAZEPRINTER_H
#define MAZEPRINTER_H

#include "Display.h"
#include "MazeMap.h"

class MazePrinter {
public:
    /**
     * �R���X�g���N�^
     * @param display Display�C���X�^���X�̃|�C���^
     */
    MazePrinter(Display* display);
    /**
     * �o��
     * @param mazeMap MazeMap�C���X�^���X�̃|�C���^
     */
    virtual void output(MazeMap* mazeMap);
private:
    /** Display�C���X�^���X�̃|�C���^*/
    Display* display;
};

#endif /* MAZEPRINTER_H */
