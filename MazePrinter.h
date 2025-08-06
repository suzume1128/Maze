#ifndef MAZEPRINTER_H
#define MAZEPRINTER_H

#include "Display.h"
#include "MazeMap.h"

class MazePrinter {
public:
    /**
     * コンストラクタ
     * @param display Displayインスタンスのポインタ
     */
    MazePrinter(Display* display);
    /**
     * 出力
     * @param mazeMap MazeMapインスタンスのポインタ
     */
    virtual void output(MazeMap* mazeMap);
private:
    /** Displayインスタンスのポインタ*/
    Display* display;
};

#endif /* MAZEPRINTER_H */
