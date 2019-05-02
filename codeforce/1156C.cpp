#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200004;

int num[maxn];

int main(void) {
  int n, z;
  while (cin >> n >> z) {
    for (int i = 0 ; i < n ; i++)
      cin >> num[i];
    sort(num, num + n);
    int l = 0, r = n / 2;
    int ret = 0;
    while (l < n / 2 && r < n) {
      if (num[r] - num[l] >= z) {
	ret++;
	l++;
	r++;
      }
      else
	r++;
    }
    cout << ret << endl;
  }
  return 0;
}
