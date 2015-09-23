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

#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include "loadbar.h"

using namespace std;

loadbar::loadbar(bool twoline){
	multiline = twoline;
	terminal.getWindowSize(&win_x, &win_y);
}


loadbar::~loadbar(){}

void loadbar::draw(float percentage){
	if(multiline) drawtwo(percentage);
	else drawone(percentage);
}

int loadbar::getX(){
	return win_x;
}

void loadbar::drawone(float percentage){
	int dist = percentage*win_x - 7;
	
	terminal.clearLines(2 );
	cout << "<[";
	for(int j = 0; j < dist; j++) cout << "=";
	for(int j = max(dist, 0); j < win_x-8; j++) cout << " ";
	cout << "| ";
	string perstr = to_string((int) (percentage*100 + 1));
	if(perstr.length() == 1) perstr = "  "+perstr;
	else if(perstr.length() == 2) perstr = " "+perstr;
	cout << perstr << "%";
	cout << "\n";
}

void loadbar::drawtwo(float percentage){
	int dist = percentage*win_x;
	
	terminal.clearLines(2);
	cout << (int) (percentage*100 + 1) << "%\n";
	cout << "<[";
	for(int j = 0; j < dist-3; j++) cout << "=";
	for(int j = max(dist-3, 0); j < win_x-4; j++) cout << " ";
	cout << "| ";
	cout << "\n";
}
