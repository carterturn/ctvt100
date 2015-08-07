#pragma once

#include <sstream>
#include "unistd.h"

namespace printMode{
	enum mode {BOLD, DIM, UNDERSCORE, BLINK, REVERSE, HIDDEN};
}

class ctvt{
public:
	ctvt();
	~ctvt();
	
	void clear();
	void clearLines(int lines);
	
	void setpos(int x, int y);
	
	void printSpecial(std::string text, printMode::mode mode);
	
	void getWindowSize(int *x, int *y);
	
private:
	int win_x;
	int win_y;
};
