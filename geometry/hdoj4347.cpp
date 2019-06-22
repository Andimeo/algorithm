#include <bits/stdc++.h>

using namespace std;


const int MAX = 50004;
int K;

int dim;

struct Point {
  int e[5];
  bool operator<(const Point& an) const {
    return e[dim] < an.e[dim];
  }
}pts[MAX];

typedef pair<double, Point*> PDP;
priority_queue<PDP> pq;

struct KDTree {
  int sz[MAX << 2];
  Point *split[MAX << 2];

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

  double dis(Point& a, Point& b) const {
    double res = 0;
    for (int i = 0 ; i < K ; i++)
      res += (a.e[i] - b.e[i]) * (a.e[i] - b.e[i]);
    return res;
  }
  
  void query(int i, int m, int dep, Point& q) {
    if (sz[i] == -1) return;
    PDP tmp = {dis(*split[i], q), split[i]};
    // cout << tmp.first << endl;
    int lc = i * 2 + 1, rc = i * 2 + 2;
    int dim = dep % K, flag = 0;
    if (q.e[dim] >= split[i]->e[dim]) swap(lc, rc);
    query(lc, m, dep + 1, q);
    if (pq.size() < m) pq.push(tmp), flag = 1;
    else {
      if (tmp.first < pq.top().first) pq.pop(), pq.push(tmp);
      if ((q.e[dim] - split[i]->e[dim]) * (q.e[dim] - split[i]->e[dim]) < pq.top().first) flag = 1;
    }
    if (flag) query(rc, m, dep + 1, q);
  }
} tree;

int main(void) {
  int n;
  while (cin >> n >> K) {
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < K ; j++) {
	cin >> pts[i].e[j];
      }
    }
    tree.build(0, 0, n - 1, 0);
    int q;
    cin >> q;
    while (q--) {
      Point q;
      for (int i = 0 ; i < K; i++)
	cin >> q.e[i];
      int m;
      cin >> m;
      tree.query(0, m, 0, q);
      int t = 0;
      Point *res[10];
      while (!pq.empty()) {
	res[t++] = pq.top().second;
	pq.pop();
      }
      cout << "the closest " << t << " points are:\n";
      for (int i = m - 1; i >= 0; i--) {
	cout << res[i]->e[0];
	for (int j = 1; j < K; j++)
	  cout << " " << res[i]->e[j];
	cout << "\n";
      }
    }
  }
  return 0;
}
