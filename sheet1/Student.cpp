#include <iostream>
#include <string>
using namespace std;

int main() {
	int t;
	int n;
  string t_str;
  string n_str;
  getline(cin, t_str);
  getline(cin, n_str);
  t = stoi(t_str);
  n = stoi(n_str);
	if (n<1 || n>1000)
		cout<<"too many number of lines"<<endl;
	string lines[n];
	string temp;
	string replace1("ent");
	string replace2("entin");
	string replace3("enten");
	for (int i = 0; i < n; i ++){
		getline(cin, temp);
		lines[i] = temp;
	}
	for (int c = 0; c < t; c++){
		cout<<"Case #"<<c+1<<":"<<endl;
		for (int i = 0; i < n; i ++){
			while (lines[i].find(replace2)<10000)
				lines[i].replace(lines[i].find(replace2),replace2.length(),"ierende");
			while (lines[i].find(replace3)<10000)
				lines[i].replace(lines[i].find(replace3),replace3.length(),"ierende");
			while (lines[i].find(replace1)<10000)
				lines[i].replace(lines[i].find(replace1),replace1.length(),"ierender");
			cout << lines[i] << endl;
		}
	}
	return 0;
}
