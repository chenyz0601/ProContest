#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int compute(string str){
	// ptr to store rest of strings
	string::size_type sz;

	string op1("plus");
	string op2("minus");
	string op3("times");
	string op4("tothepowerof");

	// number1 the first number to be calculated
	long long int number1 = stoi(str, &sz);
	long long int number2;
	string str_temp = "";
	// store the rest string to str_new
	string str_new = str.substr(sz);
	int length = str_new.length();
	while (length>0){
		if (str_new.find(op1)==0){
			str_temp = str_new.substr(op1.length());
			number2 = stoi(str_temp, &sz);
			number1 = number1+number2;
			str_new = str_temp.substr(sz);
			length = str_new.length();
		} else if (str_new.find(op2)==0){
			str_temp = str_new.substr(op2.length());
			number2 = stoi(str_temp, &sz);
			number1 = number1-number2;
			str_new = str_temp.substr(sz);
			length = str_new.length();
		} else if (str_new.find(op3)==0){
			str_temp = str_new.substr(op3.length());
			number2 = stoi(str_temp, &sz);
			number1 = number1*number2;
			str_new = str_temp.substr(sz);
			length = str_new.length();
		} else if (str_new.find(op4)==0){
			str_temp = str_new.substr(op4.length());
			number2 = stoi(str_temp, &sz);
      number1 = pow(number1, number2);
			str_new = str_temp.substr(sz);
			length = str_new.length();
		}
	}
	return number1;
}

int main() {
	int t;
  string t_str;
  getline(cin, t_str);
  t = stoi(t_str);
	if (t<1 || t>20)
		cout<<"too many cases!"<<endl;
	string str;
	long long int out[t];
	for (int i = 0; i < t; i ++){
		getline(cin, str);
		out[i] = compute(str);
	}
	for (int i = 0; i < t; i++)
  cout << "Case #"<<i+1<<": " << out[i] << endl;
	return 0;
}
