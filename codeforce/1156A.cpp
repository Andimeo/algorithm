#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(void) {
  int n;
  while (cin >> n) {
    int a[100];
    for (int i = 0 ; i < n; i++) {
      cin >> a[i];
    }
    int ret = 0;
    bool ok = true;
    for (int i = 1; i < n; i++) {
      if (i >= 2 && a[i-2] == 3 && a[i-1] == 1 && a[i] == 2) {
	ret += 2;
      }
      else if (a[i-1] == 1 && a[i] == 2) {
	ret += 3;
      }
      else if (a[i-1] == 1 && a[i] == 3) {
	ret += 4;
      }
      else if (a[i-1] == 2 && a[i] == 1) {
	ret += 3;
      }
      else if (a[i-1] == 2 && a[i] == 3) {
	ok = false;
      }
      else if (a[i-1] == 3 && a[i] == 1) {
	ret += 4;
      }
      else if (a[i-1] == 3 && a[i] == 2) {
	ok = false;
      }
      if (!ok) break;
    }
    if (!ok) cout << "Infinite" << endl;
    else {
      cout << "Finite" << endl << ret << endl;
    }
  }
  return 0;
}
