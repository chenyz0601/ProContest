//============================================================================
// Name        : ProblemB.cpp
// Author      : YuanzeChen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	long long int c = 299792458;
	int t;
	cin>>t;
	if (t<1 || t>1000)
		cout<<"wrong number!\n";
	int m[t];
	int temp;
	for (int i = 0; i < t; i++){
		cin>>temp;
		if (temp < 1 || temp > 100){
			cout<<"mass is out of range!\n";
			break;
		}
		m[i] = temp;
	}
	for (int i = 0; i < t; i++){
		long long int out = m[i]*c*c;
		cout<<"Case #"<<i+1<<": "<<out<<"\n";
	}
	return 0;
}
