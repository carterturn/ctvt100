#include "ctvt.h"
#include "ccmd.h"
#include "its.h"
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
ctvt::~ctvt(){}

void ctvt::clear(){
	printf("%c[H", 27, 27);
	
	for(int i = 0; i < win_y; i++){
		for(int j = 0; j < win_x; j++){
			cout << " ";
		}
	}
	
	printf("%c[H", 27, 27);
}

void ctvt::clearLines(int lines){
	string vtcmd = "\033["+its(lines)+"A";
	printf(vtcmd.c_str());
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < win_x; j++){
			cout << " ";
		}
	}
	
	printf(vtcmd.c_str());
}

void ctvt::printSpecial(string text, printMode::mode mode){
	switch(mode){
		case printMode::BOLD:
			printf("%c[1m", 27);
			break;
		case printMode::DIM:
			printf("%c[2m", 27);
			break;
		case printMode::UNDERSCORE:
			printf("%c[4m", 27);
			break;
		case printMode::BLINK:
			printf("%c[5m", 27);
			break;
		case printMode::REVERSE:
			printf("%c[7m", 27);
			break;
		case printMode::HIDDEN:
			printf("%c[8m", 27);
			break;
	}
	
	printf(text.c_str());
	printf("%c[0m", 27);
}

void ctvt::getWindowSize(int *x, int *y){
	*x = win_x;
	*y = win_y;
}
