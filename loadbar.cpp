/*
  Copyright 2017 Carter Turnbaugh

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

#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "loadbar.h"

using namespace std;

loadbar::loadbar(bool two_line) : two_line(two_line), ctvt() {}


void loadbar::draw(float percentage){
	if(two_line) draw_two_line(percentage);
	else draw_one_line(percentage);
}

int loadbar::getX(){
	return win_x;
}

void loadbar::draw_one_line(float percentage){
	string line_start = "<[";
	string line_end = "| ";
	stringstream percentage_string;
	percentage_string.width(3);
	percentage_string.fill(' ');
	percentage_string << (int) (percentage * 100.0f) + 1;
	percentage_string << "%";
	line_end += percentage_string.str();

	int dist = percentage*(win_x - (line_start.length() + line_end.length()));
	clearLines(1);
	cout << line_start;
	for(int j = 0; j < dist; j++) cout << "=";
	for(int j = max(dist, 0); j < win_x-9; j++) cout << " ";
	cout << line_end;
	cout << "\n";
}

void loadbar::draw_two_line(float percentage){
	int dist = percentage*win_x;
	
	clearLines(1);
	cout << (int) (percentage*100 + 1) << "%\n";
	cout << "<[";
	for(int j = 0; j < dist-3; j++) cout << "=";
	for(int j = max(dist-3, 0); j < win_x-4; j++) cout << " ";
	cout << "| ";
	cout << "\n";
}
