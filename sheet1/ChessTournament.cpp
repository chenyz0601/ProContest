#include <iostream>

using namespace std

void print(int& a, int t, int& N){
  for (int i = 0; i < t; i ++){
    cout<<"Case #"<<i+1<<": "<<endl;
    for (int j = 0; j < N[i]; j ++)
      for (int k = 0; k < 5; k ++){
        if (k == 4)
          cout<<a[j][k]<<endl;
        else
          cout<<a[j][k]<<" ";
      }
  }
}

int main(){
  int t, n;
  string t_str, n_str;
  string temp;
  size_type sz;
  getline(cin, t_str);
  t = stoi(t_str);
  if (t<1 || t>20)
    cout<<"invalid t"<<endl;
  int N[t];
  for (int i = 0; i < t; i++){
    getline(cin, n_str);
    n = stoi(n_str);
    if (n<2 || n>1000)
      cout<<"invalid n"<<endl;
    N[i] = n;
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
