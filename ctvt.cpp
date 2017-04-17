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

#include "ctvt.h"
#include "ccmd.h"
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

ctvt::ctvt(){
	ccmd cmd("stty size");
	string sizedata = cmd.run();
	
	string win_ys = "";
	string win_xs = "";
	
	bool ydata = true;
	for(int i = 0; i < sizedata.length(); i++){
		if(sizedata[i] == ' ') ydata = false;
		else{
			if(ydata) win_ys += sizedata[i];
			else win_xs += sizedata[i];
		}
	}
	
	win_x = atoi(win_xs.c_str());
	win_y = atoi(win_ys.c_str());
}

void ctvt::clear(){
	printf("%c[H", 27);
	printf("%c[J", 27);
}

void ctvt::clearLines(int lines){
	for(int i = 0; i < lines; i++){
		printf("%c[2K", 27);
		printf("%c[A", 27);
	}
}

void ctvt::printSpecial(string text, ctvt::mode mode,
			ctvt::color foreground_color, ctvt::color background_color){
	printf("%c[0m", 27);

	if(mode != ctvt::MODE_NONE){
		printf("%c[%dm", 27, mode);
	}
	if(foreground_color != ctvt::COLOR_NONE){
		printf("%c[%dm", 27, foreground_color + 29);
	}
	if(background_color != ctvt::COLOR_NONE){
		printf("%c[%dm", 27, background_color + 39);
	}
	
	printf(text.c_str());
	printf("%c[0m", 27);
}

void ctvt::getWindowSize(int *x, int *y){
	*x = win_x;
	*y = win_y;
}
