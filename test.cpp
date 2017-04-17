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

#include <iostream>
#include "ctvt.h"
#include "loadbar.h"

using namespace std;

int main(int argc, char* argv[]){
	
	ctvt terminal;
	
	terminal.clear();
	
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::RED, ctvt::COLOR_NONE);
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::YELLOW, ctvt::COLOR_NONE);
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::GREEN, ctvt::COLOR_NONE);
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::CYAN, ctvt::COLOR_NONE);
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::BLUE, ctvt::COLOR_NONE);
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::PURPLE, ctvt::COLOR_NONE);
	
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::BLACK, ctvt::PURPLE);
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::BLACK, ctvt::BLUE);
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::BLACK, ctvt::CYAN);
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::BLACK, ctvt::GREEN);
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::BLACK, ctvt::YELLOW);
	terminal.printSpecial("Hello Carter\n", ctvt::MODE_NONE, ctvt::BLACK, ctvt::RED);

	terminal.printSpecial("Hello Carter\n", ctvt::BOLD, ctvt::COLOR_NONE, ctvt::COLOR_NONE);
	terminal.printSpecial("Hello Carter\n", ctvt::DIM, ctvt::COLOR_NONE, ctvt::COLOR_NONE);
	terminal.printSpecial("Hello Carter\n", ctvt::UNDERSCORE, ctvt::COLOR_NONE, ctvt::COLOR_NONE);
	terminal.printSpecial("Hello Carter\n", ctvt::BLINK, ctvt::COLOR_NONE, ctvt::COLOR_NONE);
	terminal.printSpecial("Hello Carter\n", ctvt::REVERSE, ctvt::COLOR_NONE, ctvt::COLOR_NONE);
	terminal.printSpecial("Hello Carter\n", ctvt::HIDDEN, ctvt::COLOR_NONE, ctvt::COLOR_NONE);

	usleep(1000000);
	
	terminal.clear();
	
       	usleep(1000000);
	
	loadbar bar(false);

	for(int i = 0; i < bar.getX(); i++){
		bar.draw((float) i/(float) bar.getX());
		usleep(10000);
	}
	
	return 0;
}
