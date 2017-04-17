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

#include "ccmd.h"
#include <sstream>
#include <cstdio>

using namespace std;

ccmd::ccmd(string comm){
	command = comm;
}

ccmd::~ccmd(){
	pclose(cmd);
}

string ccmd::run(){
	cmd = popen(command.c_str(), "r");
	
	stringstream result;
	
	while(!feof(cmd)){
		char buffer[128];
		fgets(buffer, 127, cmd);
		result << buffer;
	}
	
	return result.str();
}
