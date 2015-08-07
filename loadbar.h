#pragma once

#include "ctvt.h"

class loadbar{
public:
	loadbar(bool twoline);
	~loadbar();
	
	void draw(float percentage);
	
	int getX();
private:
	ctvt terminal;
	bool multiline;
	
	void drawone(float percentage);
	void drawtwo(float percentage);
	
	int win_x, win_y;
};
