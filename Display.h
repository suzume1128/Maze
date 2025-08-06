#ifndef DISPLAY_H
#define DISPLAY_H

#include <ostream>

class Display {
public:
    /**
     * �f�X�g���N�^
     */
    virtual ~Display();
    /**
     * �\���O�����i�������z�֐��j
     */
    virtual void start() = 0;
    /**
     * �\���㏈���i�������z�֐��j
     */
    virtual void end() = 0;
    /**
     * �P�����o�͏��� (�������z�֐�)
     * @param c �o�͕���
     */
    virtual void put(char c) = 0;
    /**
     * ���s�����i�������z�֐��j
     */
    virtual void newLine() = 0;
protected:
    /**
     * �o�͐�̎Q�Ɓi�������z�֐��j
     * @return �o�͐�̎Q��
     */
    virtual std::ostream& stream() = 0;
};

#endif /* DISPLAY_H*/
