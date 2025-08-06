#include "MazeMap.h"

MazeMap::MazeMap(int w, int h) {
    width = 2 * w + 1;//迷路幅
    height = 2 * h + 1;//迷路高
    data = new char* [width];//動的領域確保
    for (int i = 0; i < width; ++i) {
        data[i] = new char[height];
    }
}

MazeMap::~MazeMap() {
    for (int i = 0; i < width; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

//ここから実装
int MazeMap::getWidth() //迷路幅をゲットする
{
    return width;
}

int MazeMap::getHeight() //迷路高をゲットする
{
    return height;
}

bool MazeMap::isInside(int x, int y) //座標(x,y)が迷路の範囲内かどうかをチェックする
{
    if (0 <= x && x < width && 0 <= y && y < height)//迷路の範囲外であったらfalse
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool MazeMap::isWall(int x, int y) //座標(x,y)が「壁」であるかどうかをチェックする
{
    if (0 <= x && x < width && 0 <= y && y < height)//迷路の範囲外であったらfalse
    {
        if (data[x][y] == wall)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    else
    {
        return false;
    }
   
}

bool MazeMap::set(int x, int y, char c)//座標(x,y)のマップ情報をセットする
{
    if (0 <= x && x < width && 0 <= y && y <  height)//迷路の範囲外であったらfalse
    {
        data[x][y] = c;
        return true;
    }
    else 
        return false;
}

char MazeMap::get(int x, int y)//座標(x,y)のマップ情報をゲットする
{
    return data[x][y];
}

void MazeMap::clear()//すべての要素を壁にする
{
    for ( int i = 0; i < width;  ++i)
    {
        for ( int j = 0; j < height; ++j)
        {
            data[i][j] = wall;
        }
    }
}