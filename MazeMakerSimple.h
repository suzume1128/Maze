#ifndef MAZEMAKERSIMPLE_H
#define MAZEMAKERSIMPLE_H

#include <cstdlib>
#include "MazeMap.h"

class MazeMakerSimple {
public:
    /**
     * コンストラクタ
     * @param mazeMap MazeMapインスタンス
     */
    MazeMakerSimple(MazeMap* mazeMap);
    /**
     * 迷路生成
     */
    void generate();
private:
    /** MazeMapインスタンス */
    MazeMap* mazeMap;
    /**
     * 座標(x,y)において dで指定された方向をチェック
     * @param x x座標
     * @param y y座標
     * @param d 方向を示すインデックス
     */
    void checkDirection(int x, int y, int d);
    /**
     * 座標(x,y)において全方向をチェック
     * @param x x座標
     * @param y y座標
     */
    void checkPoint(int x, int y);
};

#endif /* MAZEMAKERSIMPLE_H */
