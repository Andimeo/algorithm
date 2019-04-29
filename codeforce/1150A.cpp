#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  int n, m, r;
  while (cin >> n >> m >> r) {
    int buy = 1001;
    int sell = -1;
    for (int i = 0 ; i < n ; i++) {
      int v;
      cin >> v;
      buy = buy > v ? v : buy;
    }
    for (int i = 0 ; i < m ; i++) {
      int v;
      cin >> v;
      sell = sell < v ? v : sell;
    }
    int result = r / buy * sell + r % buy;
    cout << max(result, r) << endl;
      
  }
  return 0;
}
