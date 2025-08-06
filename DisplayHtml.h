#ifndef DISPLAYHTML_H
#define DISPLAYHTML_H

#include "DisplayFile.h"

class DisplayHtml : public DisplayFile {
public:
    /**
     * コンストラクタ
     * @param fileName 出力ファイル名（指定しない場合"output.html"）
     */
    DisplayHtml(const char* fileName = "output.html");

    virtual void start();
    virtual void end();
    virtual void put(char c);
    virtual void newLine();
};

#endif /* DISPLAYHTML_H */