#include <iostream>

using namespace std

int main(){
  int t, n;
  string t_str, n_str;
  string temp;
  size_type sz;
  getline(cin, t_str);
  t = stoi(t_str);
  if (t<1 || t>20)
    cout<<"invalid t"<<endl;
  for (int i = 0; i < t; i++){
    getline(cin, n_str);
    n = stoi(n_str);
    if (n<2 || n>1000)
      cout<<"invalid n"<<endl;
    int s[n][5];
    for (int j = 0; j < n; j ++){
      getline(cin, temp);
      for (int k = 0; k < 5; k ++){
        s[j][k] = stoi(temp, &sz);
        temp = temp.substr(sz+1);
      }
    }
  }
}
