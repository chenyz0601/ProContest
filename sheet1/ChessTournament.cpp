#include <iostream> 
#include <algorithm>
#include <functional>

using namespace std;

void print(int a[][5], int t, int N){
  cout<<"Case #"<< t+1<<": "<<endl;
  for (int j = 0; j < N; j ++){
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
  string blanks;
  string::size_type sz;
  getline(cin, t_str);
  t = stoi(t_str);
  if (t<1 || t>20)
    cout<<"invalid t"<<endl;
  int s[t][1000][5];
  int N[t];
  for (int i = 0; i < t; i++){
    getline(cin, n_str);
    n = stoi(n_str);
    if (n<2 || n>1000)
      cout<<"invalid n"<<endl;
    N[i] = n;
    for (int j = 0; j < n; j ++){
      getline(cin, temp);
      for (int k = 0; k < 5; k ++){
        s[i][j][k] = stoi(temp, &sz);
        if (k<4)
          temp = temp.substr(sz+1);
      }
      sort(s[i][j], s[i][j]+5, greater<int>());
    }
    int temp_s[n];
    for (int k = 0; k < 5; k ++){
      for (int j = 0; j < n; j ++)
        temp_s[j] = s[i][j][k];
      sort(temp_s, temp_s+n, greater<int>());
      for (int j = 0; j < n; j ++)
        s[i][j][k] = temp_s[j];
    }
    if (i < t-1)
      getline(cin, blanks);
  }

  for (int i = 0; i < t; i ++)
    print (s[i], i, N[i]);

  return 0;
}
