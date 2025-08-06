#include "MazeMakerSimple.h"

MazeMakerSimple::MazeMakerSimple(MazeMap* mazeMap) {
    this->mazeMap = mazeMap;
}

void MazeMakerSimple::generate() {
    // ���H�}�b�v�����N���A
    mazeMap->clear();

    // �����_���ɖ��H�쐬�J�n�n�_��I���i�������C����W�j
    int x = rand() % (mazeMap->getWidth() / 2) * 2 + 1;
    int y = rand() % (mazeMap->getHeight() / 2) * 2 + 1;

    // �����_���ɑI�� (x,y)�̍��W������H�̍쐬�J�n
    checkPoint(x, y);

    // �Ō�ɍ���ɃX�^�[�g�n�_�A�E���ɃS�[���n�_��u���ďI��
    mazeMap->set(0, 1, mazeMap->start);
    mazeMap->set(mazeMap->getWidth() - 1, mazeMap->getHeight() - 2, mazeMap->goal);
}

void MazeMakerSimple::checkDirection(int x, int y, int d) {
    // �S�̕����������\����    

    static const struct pos {
        int x, y;
    } steps[] = {
        {0, +1}, // ��
        {+1, 0}, // �E
        {0, -1}, // ��    
        {-1, 0} // ��
    };

    // ����d�̒l�ɂ��Csteps[]�Ŏ����������̂P������
    int dx = steps[d & 3].x;
    int dy = steps[d & 3].y;

    if (mazeMap->isWall(x + 2 * dx, y + 2 * dy)) { // �w�肳�ꂽ�����̂Q�}�X�悪�ǂł����
        mazeMap->set(x + dx, y + dy); // ���̕����̂P�}�X���ʘH�ɃZ�b�g
        mazeMap->set(x + 2 * dx, y + 2 * dy); // ���̕����̂Q�}�X���ʘH�ɃZ�b�g
        // ���ړ_���Q�}�X��Ɉڂ��āC�`�F�b�N���p��
        checkPoint(x + 2 * dx, y + 2 * dy);
    }
}

void MazeMakerSimple::checkPoint(int x, int y) {
    if (!mazeMap->isInside(x, y)) { // ���H�͈̔͊O�Ȃ�
        return;
    }
    // �w����W��ʘH�ɃZ�b�g
    mazeMap->set(x, y);

    // �T����������𗐐��Őݒ�
    int d = rand();
    // �ĒT���̏��Ԃ�ݒ�i���v��� or �����v���j
    int dd = (rand() & 1) * 2 - 1; // -1 or +1 

    // �S�����ɒʘH�����΂��邩���ԂɃ`�F�b�N
    for (int i = 0; i < 4; ++i) {
        checkDirection(x, y, d);
        d += dd;
    }
}