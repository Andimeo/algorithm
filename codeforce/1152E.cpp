#include <bits/stdc++.h>

using namespace std;

const int maxn = 100000 + 4;

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

int b[maxn], c[maxn];
int ind = 0;
map<int, int> indexer;
map<int, int> revert_indexer;

void do_index(int n) {
  if (indexer.find(n) == indexer.end()) {
    indexer[n] = ind;
    revert_indexer[ind++] = n;
  }
}

int main(void) {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> b[i];
    do_index(b[i]);
  }
  for (int i = 1; i < n; i++) {
    cin >> c[i];
    do_index(c[i]);
  }

  for (int i = 1; i < n ; i++) {
    if (b[i] > c[i]) {
      cout << "-1" << endl;
      return 0;
    }
  }
  Graph g(ind);
  for (int i = 1; i < n ; i++) {
    g.add_edge(indexer[b[i]], indexer[c[i]]);
  }

  g.run();
  if (!g.exist()) {
    cout << "-1" << endl;
  } else {
    for (int v : g.path)
      cout << revert_indexer[v] << " ";
    cout << endl;
  }
  return 0;
}
