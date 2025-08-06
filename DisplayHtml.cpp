#include "DisplayHtml.h"

DisplayHtml::DisplayHtml(const char* fileName) : DisplayFile(fileName) {
}

void DisplayHtml::start() {
    stream() << "<html><body>\n<table>\n<tr>\n";
}

void DisplayHtml::end() {
    stream() << "</tr>\n</table>\n</body>\n</html>\n" << std::endl;
}

void DisplayHtml::put(char c) {
    stream() << "<td>" << c << "</td>";
}

void DisplayHtml::newLine() {
    stream() << "</tr>\n<tr>\n";
}