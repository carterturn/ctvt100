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
