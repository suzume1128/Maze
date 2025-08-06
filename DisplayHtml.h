#ifndef DISPLAYHTML_H
#define DISPLAYHTML_H

#include "DisplayFile.h"

class DisplayHtml : public DisplayFile {
public:
    /**
     * �R���X�g���N�^
     * @param fileName �o�̓t�@�C�����i�w�肵�Ȃ��ꍇ"output.html"�j
     */
    DisplayHtml(const char* fileName = "output.html");

    virtual void start();
    virtual void end();
    virtual void put(char c);
    virtual void newLine();
};

#endif /* DISPLAYHTML_H */