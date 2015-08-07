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
