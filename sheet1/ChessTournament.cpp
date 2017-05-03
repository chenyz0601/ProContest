#include <iostream> 
#include <algorithm>
#include <functional>
#include <vector>
#include <array>

struct MyRows{

  //array<int, 5> const rows;
  //MyRows(array<int, 5> const& ini):rows(ini) {}
  //MyRows(initializer_list<int> r){
  //  copy(r.begin(),r.end(),rows);
  //}
  
  int rows[5];
  MyRows(initializer_list<int> ini){
    copy(ini.begin(), ini.end(), rows);
  }
  bool operator > (const MyRows& row) const{
    for (int i = 0; i < 5; i ++){
      if (rows[i] > row.rows[i])
        return true;
      else if (i == 4)
        return false;
    }
  }
};

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
  int s[t][1000][5]; // store arrays for all cases
  int N[t]; // store n for each case

  // loop over cases
  for (int i = 0; i < t; i++){
    getline(cin, n_str);
    n = stoi(n_str); // get n
    if (n<2 || n>1000)
      cout<<"invalid n"<<endl;
    N[i] = n;

    // loop over current case
    for (int j = 0; j < n; j ++){
      getline(cin, temp);

      // get a row and sort it
      for (int k = 0; k < 5; k ++){
        s[i][j][k] = stoi(temp, &sz);
        if (k<4)
          temp = temp.substr(sz+1); // skip a space
      }
      sort(s[i][j], s[i][j]+5, greater<int>());
    }

    // int temp_s[n]; // temp array for columns

    // sort by column
/*
    for (int k = 0; k < 5; k ++){
      for (int j = 0; j < n; j ++)
        temp_s[j] = s[i][j][k];
      sort(temp_s, temp_s+n, greater<int>());
      for (int j = 0; j < n; j ++)
        s[i][j][k] = temp_s[j];
    }
*/

    vector <MyRows> vec;
    for (int j = 0; j < n; j ++)
      vec.push_back(MyRows(s[i][j]));
    sort(vec.begin(), vec.end(), greater<MyRows>());
    for (vector<MyRows>::iterator it = vec.begin(); it != vec.end(); ++it)
      s[i][j] = *it;
    // skip blank lines
    if (i < t-1)
      getline(cin, blanks);
  }

  // print result
  for (int i = 0; i < t; i ++)
    print (s[i], i, N[i]);

  return 0;
}
