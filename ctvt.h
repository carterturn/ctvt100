/*
  Copyright 2015 Carter Turnbaugh

  This file is part of Terca C++ VT100 Interface.

  Terca C++ VT100 Interface is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Terca C++ VT100 Interface is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Terca C++ VT100 Interface.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <sstream>
#include "unistd.h"

class ctvt{
public:
	enum mode {MODE_NONE, BOLD, DIM, UNDERSCORE, BLINK, REVERSE, HIDDEN};
	enum color {COLOR_NONE, BLACK, RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, WHITE};
	ctvt();
	
	void clear();
	void clearLines(int lines);
	
	void setpos(int x, int y);
	
	void printSpecial(std::string text, ctvt::mode mode, ctvt::color foreground_color,
			  ctvt::color background_color);
	
	void getWindowSize(int *x, int *y);
	
protected:
	int win_x;
	int win_y;
};
