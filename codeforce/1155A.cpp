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
    int pos[26];
    memset(pos, -1, sizeof(pos));
    cin >> s;
    bool flag = false;
    for (int i = 0 ; i < s.length(); i++) {
      int m = s[i] - 'a';
      for(int j = m + 1 ; j < 26; j++) {
	if (pos[j] != -1) {
	  flag = true;
	  cout << "YES" << endl;
	  cout << pos[j] + 1 << " " << i + 1 << endl;
	  break;
	}
      }
      if (flag) break;
      else pos[m] = i;
    }
    if (!flag) cout << "NO" << endl;
  }
  
  return 0;
}
