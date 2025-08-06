#ifndef DISPLAY_H
#define DISPLAY_H

#include <ostream>

class Display {
public:
    /**
     * デストラクタ
     */
    virtual ~Display();
    /**
     * 表示前処理（純粋仮想関数）
     */
    virtual void start() = 0;
    /**
     * 表示後処理（純粋仮想関数）
     */
    virtual void end() = 0;
    /**
     * １文字出力処理 (純粋仮想関数)
     * @param c 出力文字
     */
    virtual void put(char c) = 0;
    /**
     * 改行処理（純粋仮想関数）
     */
    virtual void newLine() = 0;
protected:
    /**
     * 出力先の参照（純粋仮想関数）
     * @return 出力先の参照
     */
    virtual std::ostream& stream() = 0;
};

#endif /* DISPLAY_H*/
