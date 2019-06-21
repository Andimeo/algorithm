#include <bits/stdc++.h>

using namespace std;

const int MAX = 1004;
const int INF = 0x7fffffff;

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f): from(u), to(v), cap(c), flow(f) {}
};

struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;
  vector<int> G[MAX];
  int a[MAX];
  int p[MAX];

  void init(int n) {
    for (int i = 0 ; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int u, int v, int cap) {
    edges.push_back(Edge(u, v, cap, 0));
    edges.push_back(Edge(v, u, 0, 0));
    m = edges.size();
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
  }

  int Maxflow(int s, int t) {
    int flow = 0;
    while (true) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while (!Q.empty()) {
	int x = Q.front(); Q.pop();
	//	cout << x << endl;
	for (int i = 0 ; i < G[x].size(); i++) {
	  Edge& e = edges[G[x][i]];
	  if (!a[e.to] && e.flow < e.cap) {
	    p[e.to] = G[x][i];
	    a[e.to] = min(a[x], e.cap - e.flow);
	    Q.push(e.to);
	  }
	}
	// augmenting path found
	if (a[t]) break;
      }
      // augmenting path not found
      if (!a[t]) break;
      for (int u = t; u != s; u = edges[p[u]].from) {
	edges[p[u]].flow += a[t];
	edges[p[u]^1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};

int main() {
  EdmondsKarp ek;
  ek.init(5);
  ek.AddEdge(1, 2, 1);
  ek.AddEdge(3, 2, 2);
  ek.AddEdge(2, 5, 5);
  ek.AddEdge(4, 2, 3);
  cout << ek.Maxflow(1, 5) << endl;
  return 0;
}
