#ifndef DISPLAYSCREEN_H
#define DISPLAYSCREEN_H

#include <iostream>
#include "Display.h"

class DisplayScreen : public Display {
public:
    virtual void start();
    virtual void end();
    virtual void put(char c);
    virtual void newLine();
protected:
    virtual std::ostream& stream();
};

#endif /* DISPLAYSCREEN_H */
