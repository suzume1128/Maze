#include "MazeMap.h"

MazeMap::MazeMap(int w, int h) {
    width = 2 * w + 1;//���H��
    height = 2 * h + 1;//���H��
    data = new char* [width];//���I�̈�m��
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

//�����������
int MazeMap::getWidth() //���H�����Q�b�g����
{
    return width;
}

int MazeMap::getHeight() //���H�����Q�b�g����
{
    return height;
}

bool MazeMap::isInside(int x, int y) //���W(x,y)�����H�͈͓̔����ǂ������`�F�b�N����
{
    if (0 <= x && x < width && 0 <= y && y < height)//���H�͈̔͊O�ł�������false
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool MazeMap::isWall(int x, int y) //���W(x,y)���u�ǁv�ł��邩�ǂ������`�F�b�N����
{
    if (0 <= x && x < width && 0 <= y && y < height)//���H�͈̔͊O�ł�������false
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

bool MazeMap::set(int x, int y, char c)//���W(x,y)�̃}�b�v�����Z�b�g����
{
    if (0 <= x && x < width && 0 <= y && y <  height)//���H�͈̔͊O�ł�������false
    {
        data[x][y] = c;
        return true;
    }
    else 
        return false;
}

char MazeMap::get(int x, int y)//���W(x,y)�̃}�b�v�����Q�b�g����
{
    return data[x][y];
}

void MazeMap::clear()//���ׂĂ̗v�f��ǂɂ���
{
    for ( int i = 0; i < width;  ++i)
    {
        for ( int j = 0; j < height; ++j)
        {
            data[i][j] = wall;
        }
    }
}