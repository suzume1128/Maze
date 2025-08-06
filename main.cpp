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
 * �\�����@�̑I��
 * @return Display�C���X�^���X�̃|�C���^
 * @attention Display�C���X�^���X�𐶐����Ă���̂ŁC�s�v�ɂȂ������_��delete���邱��
 */
Display* selectDisplay() {
    int outputMode;
    Display* display = NULL;
    do {
        std::cout << "output mode [1-6] ? ";
        std::cin >> outputMode;
        switch (outputMode) {
        case 1: display = new DisplayScreen; // ��ʂɏo��
            break;
        case 2: display = new DisplayFile; // �t�@�C���ɏo��
            break;
        case 3: display = new DisplayHtml; // HTML�t�@�C���ɏo��
            break;
        case 4: display = new DisplayScreenWide; // ��ʂɉ����ɏo��
            break;
        case 5: display = new DisplayFileWide; // �t�@�C���ɉ����ɏo��
            break;
        case 6: display = new DisplayHtmlWide; // HTML�t�@�C���ɉ����ɏo��
            break;
        default:
            std::cout << "illegal output mode " << outputMode << std::endl;
            break;
        }
    } while (display == NULL);
    return display;
}

int main(int argc, char** argv) {
    // �����̏������ݒ�
    // �{���͎��s����x�ɕω����鎞�����Ȃǂ�p�����ق����ǂ����C�J����e�ՂɁi���s�̓x�Ɍ��ʂ��ς��Ȃ��悤�Ɂj���邽�߂ɁC�����̏����l���蓮�Őݒ肵�Œ肷��
    int seed;
    std::cout << "seed ? ";
    std::cin >> seed;
    srand(seed); // ������̐ݒ�

    // ���H���C���H���̊��̐ݒ�
    int w, h;
    std::cout << "size (w, h) ? ";
    std::cin >> w >> h;

    // ���H�}�b�v��񐶐�
    MazeMap mazeMap(w, h);

    // ���H�쐬
    MazeMakerSimple mazeMaker(&mazeMap);
    mazeMaker.generate();

    // ���H�o��
    Display* display = selectDisplay();
    MazePrinter mazePrinter(display);
    mazePrinter.output(&mazeMap);

    // selectDisplay()���Ő��������C���X�^���X�����
    delete display;

    return 0;
}