#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;

#define min(a, b) (a < b ? a : b)

int main(void) {
  int n;
  int f[10];
  string s;
  while (cin >> n) {
    cin >> s;
    for (int i = 1 ; i < 10 ; i++)
      cin >> f[i];
    string result;
    int pos = 0;
    for (;pos < s.length(); pos++) {
      int v = s[pos] - '0';
      if (v < f[v]) break;
      result += s[pos];
    }
    for (;pos < s.length(); pos++) {
      int v = s[pos] - '0';
      if (v > f[v]) break;
      result += f[v] + '0';
    }
    for (;pos < s.length(); pos++) {
      result += s[pos];
    }
    cout << result << endl;
  }
  
  return 0;
}
