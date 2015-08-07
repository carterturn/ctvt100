#include <sstream>
#include <iostream>
#include <cmath>
#include "loadbar.h"
#include "its.h"

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
	string perstr = its(percentage*100 + 1);
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
