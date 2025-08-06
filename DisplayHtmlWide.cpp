#include "DisplayHtmlWide.h"

void DisplayHtmlWide::put(char c) {
	stream() << "<td>" << c << c << "</td>";
}