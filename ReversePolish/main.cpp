#include "ReversePolish.h"
#include <iostream>
#include <string>
using namespace std;


int main(){

	string infix = "a+b*c+(d*e+f)*g";
	ReversePolish rp;
	cout << rp.RP(infix)<<endl;

	return 0;
}
