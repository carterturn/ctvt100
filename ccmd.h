#pragma once

#include <iostream>

class ccmd{
public:
	ccmd(std::string comm);
	~ccmd();
	
	std::string run();
	
private:
	std::string command;
	FILE *cmd;
};
