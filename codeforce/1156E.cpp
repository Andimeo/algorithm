#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200004;

int n;
int num[maxn];
int pos[maxn];
pair<int, int> st[4 * maxn];

void build(int b, int e, int ind) {
  if (b == e) {
    st[ind] = make_pair(num[b], b);
    return;
  }
  int mid = (b + e) / 2;
  build(b, mid, ind * 2);
  build(mid + 1, e, ind * 2 + 1);
  if (st[ind*2].first > st[ind*2+1].first)
    st[ind] = st[ind*2];
  else
    st[ind] = st[ind*2+1];
}

pair<int, int> query(int b, int e, int ind, int l, int r) {
  if (b == l && e == r)
    return st[ind];
  int mid = (l + r) / 2;
  if ( e <= mid ) return query(b, e, ind * 2, l, mid);
  if ( b > mid) return query(b, e, ind * 2 + 1, mid + 1, r);
  pair<int, int> c = query(b, mid, ind * 2, l, mid);
  pair<int, int> d = query(mid + 1, e, ind * 2 + 1, mid + 1, r);
  if (c.first < d.first)
    return d;
  else
    return c;
}

int dfs(int b, int e) {
  if (b >= e) return 0;
  pair<int, int> a = query(b, e, 1, 1, n);
  int maxv = a.first, maxi = a.second;
  int ret = 0;
  if (maxi <= (b + e) / 2) {
    for (int i = b ; i < maxi; i++) {
      int d = pos[maxv - num[i]];
      if (d > maxi && d <= e) ret++;
    }
  } else {
    for (int i = maxi + 1; i <= e; i++) {
      int d = pos[maxv - num[i]];
      if (d < maxi && d >= b) ret++;
    }
  }
  return ret + dfs(b, maxi - 1) + dfs(maxi + 1, e);
}
int main(void) {
  while (cin >> n) {
    for (int i = 1 ; i <= n ; i++)
      cin >> num[i];
    for (int i = 1; i <= n ; i++)
      pos[num[i]] = i;
    build(1, n, 1);
    cout << dfs(1, n) << endl;
  }
  return 0;
}
