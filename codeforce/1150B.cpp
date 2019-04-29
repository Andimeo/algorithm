#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string g[50];

int main(void) {
  int n;
  while (cin >> n) {
    for (int i = 0 ; i < n ; i++)
      cin >> g[i];
    for (int i = 1 ; i + 1 < n ; i++) {
      for (int j = 1; j + 1 < n ; j++) {
	if (g[i][j] == '.' && g[i-1][j]=='.' && g[i][j-1] == '.' && g[i+1][j] == '.' && g[i][j+1] == '.') {
	  g[i][j] = g[i-1][j] = g[i][j-1] = g[i+1][j] = g[i][j+1] = '#';
	}
      }
    }
    bool ok = true;
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < n ; j++) {
	if (g[i][j] == '.') {
	  ok = false;
	  break;
	}
      }
      if (!ok) break;
    }
    cout << (ok ? "YES" : "NO") << endl;
      
  }
  return 0;
}
