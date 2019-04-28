#include <bits/stdc++.h>

using namespace std;

struct Edge {
  Edge(int u, int v, bool vis) {
    this->u = u;
    this->v = v;
    this->vis = vis;
  }
  int u, v;
  bool vis;
};

struct Graph {
  Graph(int n) : n(n), pos(n, 0), edges(), g(n, vector<int>()) {}

  void add_edge(int u, int v) {
    int k = edges.size();
    g[u].push_back(k);
    g[v].push_back(k);
    edges.push_back(Edge(u, v, false));
  }

  int get_start_point() {
    int num = 0;
    int ans = -1;
    for (int i = 0 ; i < n ; i++) {
      if (g[i].size() % 2) {
    	ans = i;
	    num++;  
      }
    }
    if (num == 0) return 0;
    if (num == 2) return ans;
    return -1;
  }

  void eular_path(list<int>::iterator it, int u) {
    for (; pos[u] < g[u].size(); pos[u]++) {
      int index = g[u][pos[u]];
      if (!edges[index].vis) {
	edges[index].vis = true;
	int v = edges[index].u + edges[index].v - u;
	eular_path(path.insert(it, v), v);
      }
    }
  }

  void run() {
    int u = get_start_point();
    if (u == -1)
      return;
    path.insert(path.begin(), u);
    eular_path(path.begin(), u);
  }
  
  bool exist() {
    return edges.size() + 1== path.size();
  }
  
  int n;
  int num_edge;
  vector<int> pos;
  vector<Edge> edges;
  vector<vector<int> > g;
  list<int> path;
};

int main(void) {
  Graph g(5);
  g.add_edge(0, 1);
  g.add_edge(0, 3);
  g.add_edge(1, 2);
  g.add_edge(1, 4);
  g.add_edge(2, 3);
  g.add_edge(2, 3);
  g.add_edge(3, 4);

  g.run();

  if (!g.exist()) {
    cout << "-1" << endl;
  } else {
    for (int v : g.path) 
      cout << v << " ";
    cout << endl;
  }
  return 0;
}
