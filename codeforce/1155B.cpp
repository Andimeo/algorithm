#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void) {
  int n;
  while(cin >> n) {
    string s;
    cin >> s;
    int num = 0;
    for (int i = 0 ; i < n - 10; i++) {
      num += s[i] == '8';
    }
    if (num * 2 > n - 10) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  
  return 0;
}
