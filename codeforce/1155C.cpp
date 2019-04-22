#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a%b);
}

int main(void) {
  int n, m;
  long long events[300000 + 4];
  long long interval[300000 + 4];
  while(cin >> n >> m) {
    for (int i = 0 ; i < n ; i++)
      cin >> events[i];
    for (int i = 0 ; i < m ; i++)
      cin >> interval[i];

    long long g = -1;
    for (int i = 1; i < n ; i++) {
      if (g == -1) g = events[i] - events[i - 1];
      else g = gcd(events[i] - events[i - 1], g);
    }

    int pos = -1;
    for (int i = 0; i < m; i++) {
      if (g % interval[i] == 0) {
	if (pos == -1 || interval[pos] > interval[i])
	  pos = i;
      }
    }
    if (pos == -1) cout << "NO" << endl;
    else cout << "YES" << endl << events[0] << " " << pos + 1 << endl;
    
  }
  
  return 0;
}
