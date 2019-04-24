#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;

#define min(a, b) (a < b ? a : b)

int main(void) {
  int n, m;
  while (cin >> n >> m) {
    int odd[2] = {0, 0}, even[2] = {0, 0};
    for (int i = 0 ; i < n ; i++) {
      int p;
      cin >> p;
      if (p % 2 == 1) odd[0]++; else even[0]++;
    }
    for (int i = 0 ; i < m ; i++) {
      int p;
      cin >> p;
      if (p % 2 == 1) odd[1]++; else even[1]++;
    }
    cout << min(odd[0], even[1]) + min(odd[1], even[0]) << endl;
  }
  return 0;
}
