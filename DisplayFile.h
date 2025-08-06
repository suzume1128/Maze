#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <fstream>
#include "DisplayScreen.h"

class DisplayFile : public DisplayScreen {
public:
    /**
     * �R���X�g���N�^
     * @param fileName �o�̓t�@�C�����i�w�肵�Ȃ��ꍇ"output.txt"�j
     */
    DisplayFile(const char* fileName = "output.txt");

    virtual ~DisplayFile();
protected:
    virtual std::ostream& stream();
private:
    std::ofstream ofs;
};

#endif /* DISPLAYFILE_H */