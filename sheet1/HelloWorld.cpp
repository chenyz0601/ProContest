//============================================================================
// Name        : ProblemA.cpp
// Author      : YuanzeChen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
//	cin>>t;
  string t_str;
  getline(cin, t_str);
  t = stoi(t_str);
	if (t<1 || t>20)
		cout<<"wrong number!\n";
	string name[t];
	for (int i = 0; i < t; i++){
		getline(cin, name[i]);
	}
	for (int i = 0; i < t; i++)
		cout<<"Case #"<<i+1<<": Hello "<<name[i]<<"!"<<endl;
	return 0;
}
