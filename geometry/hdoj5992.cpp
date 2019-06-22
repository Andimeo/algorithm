#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 200004;
const int K = 2;

int dim;

struct Point {
  int e[K];
  int c;
  int id;
  bool operator<(const Point& an) const {
    return e[dim] < an.e[dim];
  }
}pts[MAX];

typedef pair<ll, Point*> PDP;

struct KDTree {
  int sz[MAX << 2];
  Point *split[MAX << 2];
  PDP ans = {-1, NULL};

  void init() {
    ans = {-1.0, NULL};
  }
  
  void build(int i, int l, int r, int dep) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    dim = dep % K;
    sz[i] = r - l;
    sz[i * 2 + 1] = sz[i * 2 + 2] = -1;
    nth_element(pts + l, pts + mid, pts + r + 1);
    split[i] = &pts[mid];
    build(i * 2 + 1, l, mid - 1, dep + 1);
    build(i * 2 + 2, mid + 1, r, dep + 1);
  }

  ll dis(Point& a, Point& b) const {
    ll res = 0;
    for (int i = 0 ; i < K ; i++)
      res += 1LL * (a.e[i] - b.e[i]) * (a.e[i] - b.e[i]);
    return res;
  }

  Point* nn(Point& q) {
    query(0, 0, q);
    return ans.second;
  }
  
  void query(int i, int dep, Point& q) {
    if (sz[i] == -1) return;
    ll d = dis(*split[i], q);
    int lc = i * 2 + 1, rc = i * 2 + 2;
    int dim = dep % K, flag = 0;
    if (q.e[dim] >= split[i]->e[dim]) swap(lc, rc);
    query(lc, dep + 1, q);
    if ((!ans.second|| d < ans.first || d == ans.first && ans.second->id > split[i]->id) && split[i]->c <= q.c) ans = {d, split[i]};
    if (!ans.second || (q.e[dim] - split[i]->e[dim]) * (q.e[dim] - split[i]->e[dim]) < dis(*ans.second, q)) {
      query(rc, dep + 1, q);
    }
  }
} tree;

int main(void) {
  ios_base::sync_with_stdio(0);  cin.tie(NULL);  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < K; j++) {
	cin >> pts[i].e[j];
      }
      cin >> pts[i].c;
      pts[i].id = i;
    }
    tree.build(0, 0, n - 1, 0);
    Point q;
    for (int i = 0 ; i < m ; i++) {
      tree.init();
      for (int j = 0 ; j < K; j++)
	cin >> q.e[j];
      cin >> q.c;
      Point* res = tree.nn(q);
      cout << res->e[0];
      for (int i = 1; i < K; i++)
	cout << " " << res->e[i];
      cout << " " << res->c << "\n";
    }
  }
  return 0;
}
