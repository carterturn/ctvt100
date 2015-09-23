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
	
	terminal.printSpecial("Hello Carter\n", printMode::BOLD);
	
	usleep(1000000);
	
	terminal.clear();
	
       	usleep(1000000);
	
	loadbar bar(false);
	
	cout << "\n";
	for(int i = 0; i < bar.getX(); i++){
		bar.draw((float) i/(float) bar.getX());
		usleep(100000);
	}
	
	return 0;
}
