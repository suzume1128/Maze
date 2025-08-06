#include "DisplayFile.h"

DisplayFile::DisplayFile(const char* fileName) {
    /* ‚±‚±‚ðŽÀ‘•‚µ‚Ä‚­‚¾‚³‚¢ */
    ofs.open(fileName);
}

DisplayFile::~DisplayFile() {
    /* ‚±‚±‚ðŽÀ‘•‚µ‚Ä‚­‚¾‚³‚¢ */
    ofs.close();
}

std::ostream& DisplayFile::stream() {
    return ofs;
}