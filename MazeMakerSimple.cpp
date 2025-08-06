#include "MazeMakerSimple.h"

MazeMakerSimple::MazeMakerSimple(MazeMap* mazeMap) {
    this->mazeMap = mazeMap;
}

void MazeMakerSimple::generate() {
    // 迷路マップ情報をクリア
    mazeMap->clear();

    // ランダムに迷路作成開始地点を選択（ただし，奇数座標）
    int x = rand() % (mazeMap->getWidth() / 2) * 2 + 1;
    int y = rand() % (mazeMap->getHeight() / 2) * 2 + 1;

    // ランダムに選んだ (x,y)の座標から迷路の作成開始
    checkPoint(x, y);

    // 最後に左上にスタート地点、右下にゴール地点を置いて終了
    mazeMap->set(0, 1, mazeMap->start);
    mazeMap->set(mazeMap->getWidth() - 1, mazeMap->getHeight() - 2, mazeMap->goal);
}

void MazeMakerSimple::checkDirection(int x, int y, int d) {
    // ４つの方向を示す構造体    

    static const struct pos {
        int x, y;
    } steps[] = {
        {0, +1}, // 下
        {+1, 0}, // 右
        {0, -1}, // 上    
        {-1, 0} // 左
    };

    // 引数dの値により，steps[]で示される方向の１つを決定
    int dx = steps[d & 3].x;
    int dy = steps[d & 3].y;

    if (mazeMap->isWall(x + 2 * dx, y + 2 * dy)) { // 指定された方向の２マス先が壁であれば
        mazeMap->set(x + dx, y + dy); // その方向の１マス先を通路にセット
        mazeMap->set(x + 2 * dx, y + 2 * dy); // その方向の２マス先を通路にセット
        // 注目点を２マス先に移して，チェックを継続
        checkPoint(x + 2 * dx, y + 2 * dy);
    }
}

void MazeMakerSimple::checkPoint(int x, int y) {
    if (!mazeMap->isInside(x, y)) { // 迷路の範囲外なら
        return;
    }
    // 指定座標を通路にセット
    mazeMap->set(x, y);

    // 探索する方向を乱数で設定
    int d = rand();
    // 再探索の順番を設定（時計回り or 反時計回り）
    int dd = (rand() & 1) * 2 - 1; // -1 or +1 

    // ４方向に通路が延ばせるか順番にチェック
    for (int i = 0; i < 4; ++i) {
        checkDirection(x, y, d);
        d += dd;
    }
}