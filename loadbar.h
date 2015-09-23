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
