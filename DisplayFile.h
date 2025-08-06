#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <fstream>
#include "DisplayScreen.h"

class DisplayFile : public DisplayScreen {
public:
    /**
     * コンストラクタ
     * @param fileName 出力ファイル名（指定しない場合"output.txt"）
     */
    DisplayFile(const char* fileName = "output.txt");

    virtual ~DisplayFile();
protected:
    virtual std::ostream& stream();
private:
    std::ofstream ofs;
};

#endif /* DISPLAYFILE_H */