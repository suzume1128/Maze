#ifndef MAZEMAKERSIMPLE_H
#define MAZEMAKERSIMPLE_H

#include <cstdlib>
#include "MazeMap.h"

class MazeMakerSimple {
public:
    /**
     * �R���X�g���N�^
     * @param mazeMap MazeMap�C���X�^���X
     */
    MazeMakerSimple(MazeMap* mazeMap);
    /**
     * ���H����
     */
    void generate();
private:
    /** MazeMap�C���X�^���X */
    MazeMap* mazeMap;
    /**
     * ���W(x,y)�ɂ����� d�Ŏw�肳�ꂽ�������`�F�b�N
     * @param x x���W
     * @param y y���W
     * @param d �����������C���f�b�N�X
     */
    void checkDirection(int x, int y, int d);
    /**
     * ���W(x,y)�ɂ����đS�������`�F�b�N
     * @param x x���W
     * @param y y���W
     */
    void checkPoint(int x, int y);
};

#endif /* MAZEMAKERSIMPLE_H */
