#include "DisplayFile.h"

DisplayFile::DisplayFile(const char* fileName) {
    /* �������������Ă������� */
    ofs.open(fileName);
}

DisplayFile::~DisplayFile() {
    /* �������������Ă������� */
    ofs.close();
}

std::ostream& DisplayFile::stream() {
    return ofs;
}