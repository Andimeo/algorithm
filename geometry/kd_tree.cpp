#include <bits/stdc++.h>

using namespace std;


const int MAX = 50004;
int K = 2;

int dim;

struct Point {
  int e[5];
  bool operator<(const Point& an) const {
    return e[dim] < an.e[dim];
  }
}pts[MAX];

typedef pair<double, Point*> PDP;

struct KDTree {
  int sz[MAX << 2];
  Point *split[MAX << 2];
  PDP ans = {-1.0, NULL};
  
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

  Point* nn(Point& q) {
    query(0, 0, q);
    return ans.second;
  }
  
  void query(int i, int dep, Point& q) {
    if (sz[i] == -1) return;
    double d = dis(*split[i], q);
    int lc = i * 2 + 1, rc = i * 2 + 2;
    int dim = dep % K, flag = 0;
    if (q.e[dim] >= split[i]->e[dim]) swap(lc, rc);
    query(lc, dep + 1, q);
    if (ans.second == NULL || ans.first > d) ans = {d, split[i]};
    if ((q.e[dim] - split[i]->e[dim]) * (q.e[dim] - split[i]->e[dim]) < dis(*ans.second, q)) {
      query(rc, dep + 1, q);
    }
  }
} tree;

int main(void) {
  int n = 3;
  pts[0].e[0] = 1;
  pts[0].e[1] = 1;
  pts[1].e[0] = 1;
  pts[1].e[1] = 3;
  pts[2].e[0] = 3;
  pts[2].e[1] = 4;

  tree.build(0, 0, n - 1, 0);
  Point q = {10, 10};
  Point *p = tree.nn(q);
  cout << p->e[0] << " " << p->e[1] << endl;
  return 0;
}
