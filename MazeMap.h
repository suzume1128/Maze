#ifndef MAZEMAP_H
#define MAZEMAP_H

/**
 * @class MazeMap
 * @breif ���H���ێ��p�N���X
 */
class MazeMap {
public:
    /** �u�ǁv�̕\�� */
    static const char wall = 'O';
    /** �u�ʘH�v�̕\�� */
    static const char passage = ' ';
    /** �u�X�^�[�g�n�_�v�̕\�� */
    static const char start = 'S';
    /** �u�S�[���n�_�v�̕\�� */
    static const char goal = 'G';

    /**
     * �R���X�g���N�^
     * @param w ���H���̊��
     * @param h ���H���̊��
     * @attention ���ۂ̖��H����2w+1�C���H����2h+1
     */
    MazeMap(int w, int h);

    /**
     *  �f�X�g���N�^
     */
    virtual ~MazeMap();

    /**
     * ���H���p�Q�b�^
     * @return ���H��
     */
    int getWidth();

    /**
     * ���H���p�Q�b�^
     * @return ���H��
     */
    int getHeight();

    /**
     * �w����W�����H�͈͓̔��ɑ��݂��邩���`�F�b�N
     * @param x x���W
     * @param y y���W
     * @retval true ���H�͈͓̔�
     * @retval false ���H�͈̔͊O
     */
    bool isInside(int x, int y);

    /**
     * �w����W���ǂ��ǂ������`�F�b�N
     * @param x x���W
     * @param y y���W
     * @retval true ��
     * @retval false �ǂłȂ�
     * @attention �w����W�����H�͈͊O�ł����false��Ԃ�
     */
    bool isWall(int x, int y);

    /**
     * �w����W�̃}�b�v���̃Z�b�^
     * @param x x���W
     * @param y y���W
     * @param c �v�f
     * @retval true �w����W�����H�͈͓̔�
     * @retval false �w����W�����H�͈̔͊O
     * @attention �v�f���w�肵�Ȃ��ꍇ�C�ʘH�Ƃ���
     */
    bool set(int x, int y, char c = passage);

    /**
     * �w����W�̃}�b�v���̃Q�b�^
     * @param x x���W
     * @param y y���W
     * @return �}�b�v���
     * @attention ���H�͈͊O�̍��W���w�肵���ꍇ�C'\0'��Ԃ�
     */
    char get(int x, int y);

    /**
     * �}�b�v���̏�����
     * @attention �S�Ă̗v�f���u�ǁv�ɂ���
     */
    void clear();
private:
    /** ���H�� */
    int width;
    /** ���H�� */
    int height;
    /** ���H��� */
    char** data;
};

#endif /* MAZEMAP_H */
