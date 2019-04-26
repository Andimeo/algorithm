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
const int maxn = 200000 + 4;

int num[maxn];

int main(void) {
  int n, k;
  while (cin >> n >> k) {
    if (k == 3 && n == 8 || k == 2 && n == 4) {
      cout << "NO" << endl;
      continue;
    }
    double a = (2 * n * 1. / k + 1 - k) / 2;
    if (a < 1) {
      cout << "NO" << endl;
      continue;
    }
    int b = (int)a;
    int sum = n;
    for (int i = 0 ; i < k ; i++) {
      num[i] = b + i;
      sum -= num[i];
    }
    for (int i = k - 1; i >= 0 && sum; i--) {
      int v = 2 * num[i-1] - num[i];
      num[i] += min(sum, v); 
      sum -= min(sum, v);
    }
    cout << "YES" << endl;
    cout << num[0];
    for (int i = 1 ; i < k ; i++)
      cout << " " << num[i];
    cout << endl;
  }
  
  return 0;
}
