#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 204;

struct HopcroftKarp {
  int n, m;
  bool L[MAX], R[MAX];
  int left[MAX];
  vector<int> g[MAX];

  HopcroftKarp(int _n, int _m): n(_n), m(_m) {
    memset(left, 0, sizeof(left));
    for (int i = 1; i <= n; i++)
      g[i].clear();
  }
  
  void AddEdge(int u, int v) {
    g[u].push_back(v);
  }

  bool match(int i) {
    L[i] = true;
    for (int j = 0; j < g[i].size(); j++) {
      int v = g[i][j];
      if (R[v]) continue;
      R[v] = true;
      if (!left[v] || match(left[v])) {
	left[v] = i;
	return true;
      }
    }
    return false;
  }

  int MaxMatching() {
    int result = 0;
    for (int i = 1 ; i <= n ; i++) {
      memset(L, 0, sizeof(L));
      memset(R, 0, sizeof(R));
      if (match(i))
	result++;
    }
    return result;
  }
};

int main() {
  int n, m;
  while (cin >> n >> m) {
    HopcroftKarp hk(n, m);
    for (int i = 1 ; i <= n ; i++) {
      int x;
      cin >> x;
      for (int j = 0 ; j < x; j++) {
	int y;
	cin >> y;
	hk.AddEdge(i, y);
      }
    }
    cout << hk.MaxMatching() << endl;
  }
  return 0;
}
