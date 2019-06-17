#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
  int v[MAX];
  int n;

  int lb(int index) { return index & (-index); }
  
  void init(int n) {
    this->n = n;
    memset(v, 0, sizeof(v));
  }

  void update(int pos) {
    update(pos, 1);
  }
  
  void update(int pos, int value) {
    for (int i = pos; i <= n; i += lb(i)) {
      v[i] += value;
    }
  }
  
  int get(int pos) {
    int res = 0;
    while (pos) {
      res += v[pos];
      pos -= lb(pos);
    }
    return res;
  }
  
  int kth(int k) {
    int left = 1, right = n + 1;
    int res = -1;
    while (left < right) {
      int mid = (left + right) / 2;
      if (get(mid) >= k) {
	res = mid;
	right = mid;
      } else {
	left = mid + 1;
      }
    }
    return res;
  }
};

