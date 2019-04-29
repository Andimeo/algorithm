#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  int n;
  while (cin >> n) {
    int one = 0;
    for (int i = 0 ; i < n ; i++) {
      int v;
      cin >> v;
      one += v == 1;
    }
    int two = n - one;
    if (one > 0 && two > 0) {
      cout << 2 << " " << 1 << " ";
      one--;
      two--;
    }
    for (int i = 0 ; i < two ;i++)
      cout << 2 << " ";
    for (int i = 0 ; i < one; i++)
      cout << 1 << " ";
    cout << endl;
  }
  return 0;
}
