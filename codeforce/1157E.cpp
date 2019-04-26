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

int a[maxn], b[maxn];
int pa[maxn];

int findset(int x) {
  return pa[x] != x ? pa[x] = findset(pa[x]) : x;
}

int main(void) {
  int n;
  while (cin >> n) {
    memset(b, 0, sizeof(b));
    for(int i = 0 ; i < n ; i++)
      cin >> a[i];
    for (int i = 0 ; i < n ; i++) {
      int v;
      cin >> v;
      b[v]++;
    }
    for (int i = 0 ; i < n ; i++)
      pa[i] = i;
    for(int i = 0 ; i < n ; i++) {
      if (b[i]) {
	for (int j = (i - 1 + n) % n; j != i; j = (j - 1 + n) % n) {
	  if (!b[j]) pa[j] = i;
	  else break;
	}
      }
    }
    vector<int> c;
    for (int i = 0 ; i < n ; i++) {
      int start = (n - a[i]) % n;
      int p = findset(start);
      b[p] -= 1;
      c.push_back((a[i] + p) % n);
      if (!b[p]) {
	pa[p] = pa[(p + 1) % n];
      }
    }
    for (int i = 0 ; i < n; i++) {
      cout << c[i] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
