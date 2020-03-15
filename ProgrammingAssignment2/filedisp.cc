#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "version.h"

using namespace std;
static double brother = 1.2;

int main(int argc, char** argv) {
	version Ver;
	string input;
	vector<string> inputV;
	Ver.displayVersion();
	cout<< brother << endl;
	while(getline(cin,input)) {
		inputV.push_back(input);
	}
	
	
	string argumentv = argv[1];
	
	if(argumentv.compare("-d") == 0) 
		cout << inputV[0] << endl;
	else if(argumentv.compare("-f") == 0)                	
        	cout << inputV[1] << endl;
	else if(argumentv.compare("-b")==0) 
		cout << inputV[2] << endl;
	else
	cout <<"Wrong option entered, please enter either -d, -f, or -b."<<endl;



	



}
