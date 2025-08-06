#include <cstdlib>
#include "MazeMap.h"
#include "MazeMakerSimple.h"
#include "MazePrinter.h"
#include "Display.h"
#include "DisplayScreen.h"
#include "DisplayScreenWide.h"
#include "DisplayFile.h"
#include "DisplayFileWide.h"
#include "DisplayHtml.h"
#include "DisplayHtmlWide.h"

/**
 * 表示方法の選択
 * @return Displayインスタンスのポインタ
 * @attention Displayインスタンスを生成しているので，不要になった時点でdeleteすること
 */
Display* selectDisplay() {
    int outputMode;
    Display* display = NULL;
    do {
        std::cout << "output mode [1-6] ? ";
        std::cin >> outputMode;
        switch (outputMode) {
        case 1: display = new DisplayScreen; // 画面に出力
            break;
        case 2: display = new DisplayFile; // ファイルに出力
            break;
        case 3: display = new DisplayHtml; // HTMLファイルに出力
            break;
        case 4: display = new DisplayScreenWide; // 画面に横長に出力
            break;
        case 5: display = new DisplayFileWide; // ファイルに横長に出力
            break;
        case 6: display = new DisplayHtmlWide; // HTMLファイルに横長に出力
            break;
        default:
            std::cout << "illegal output mode " << outputMode << std::endl;
            break;
        }
    } while (display == NULL);
    return display;
}

int main(int argc, char** argv) {
    // 乱数の初期化設定
    // 本来は実行する度に変化する時刻情報などを用いたほうが良いが，開発を容易に（実行の度に結果が変わらないように）するために，乱数の初期値を手動で設定し固定する
    int seed;
    std::cout << "seed ? ";
    std::cin >> seed;
    srand(seed); // 乱数種の設定

    // 迷路幅，迷路高の基底の設定
    int w, h;
    std::cout << "size (w, h) ? ";
    std::cin >> w >> h;

    // 迷路マップ情報生成
    MazeMap mazeMap(w, h);

    // 迷路作成
    MazeMakerSimple mazeMaker(&mazeMap);
    mazeMaker.generate();

    // 迷路出力
    Display* display = selectDisplay();
    MazePrinter mazePrinter(display);
    mazePrinter.output(&mazeMap);

    // selectDisplay()内で生成したインスタンスを解放
    delete display;

    return 0;
}