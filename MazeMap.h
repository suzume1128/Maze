#ifndef MAZEMAP_H
#define MAZEMAP_H

/**
 * @class MazeMap
 * @breif 迷路情報保持用クラス
 */
class MazeMap {
public:
    /** 「壁」の表示 */
    static const char wall = 'O';
    /** 「通路」の表示 */
    static const char passage = ' ';
    /** 「スタート地点」の表示 */
    static const char start = 'S';
    /** 「ゴール地点」の表示 */
    static const char goal = 'G';

    /**
     * コンストラクタ
     * @param w 迷路幅の基底
     * @param h 迷路高の基底
     * @attention 実際の迷路幅は2w+1，迷路高は2h+1
     */
    MazeMap(int w, int h);

    /**
     *  デストラクタ
     */
    virtual ~MazeMap();

    /**
     * 迷路幅用ゲッタ
     * @return 迷路幅
     */
    int getWidth();

    /**
     * 迷路高用ゲッタ
     * @return 迷路高
     */
    int getHeight();

    /**
     * 指定座標が迷路の範囲内に存在するかをチェック
     * @param x x座標
     * @param y y座標
     * @retval true 迷路の範囲内
     * @retval false 迷路の範囲外
     */
    bool isInside(int x, int y);

    /**
     * 指定座標が壁かどうかをチェック
     * @param x x座標
     * @param y y座標
     * @retval true 壁
     * @retval false 壁でない
     * @attention 指定座標が迷路範囲外であればfalseを返す
     */
    bool isWall(int x, int y);

    /**
     * 指定座標のマップ情報のセッタ
     * @param x x座標
     * @param y y座標
     * @param c 要素
     * @retval true 指定座標が迷路の範囲内
     * @retval false 指定座標が迷路の範囲外
     * @attention 要素を指定しない場合，通路とする
     */
    bool set(int x, int y, char c = passage);

    /**
     * 指定座標のマップ情報のゲッタ
     * @param x x座標
     * @param y y座標
     * @return マップ情報
     * @attention 迷路範囲外の座標を指定した場合，'\0'を返す
     */
    char get(int x, int y);

    /**
     * マップ情報の初期化
     * @attention 全ての要素を「壁」にする
     */
    void clear();
private:
    /** 迷路幅 */
    int width;
    /** 迷路高 */
    int height;
    /** 迷路情報 */
    char** data;
};

#endif /* MAZEMAP_H */
