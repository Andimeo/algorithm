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

bool is_2n_1(int x) {
  return (x & (x + 1)) == 0;
}

int main(void) {
  int x;
  while (cin >> x) {
    int ret[40];
    int index = 0;
    int result = -1;
    while (!is_2n_1(x)) {
      int p;
      for (p = 1; p <= 20; p++) {
	if ((1 << p) > x)
	  break;
      }
      ret[index++] = p;
      x = x ^ ((1 << p) - 1);
      if (is_2n_1(x)) {
	result = 2 * index - 1;
	break;
      }
      x += 1;
    }
    cout << (result == -1 ? 2 * index : result) << endl;
    if (index) {
      cout << ret[0];
      for (int i = 1 ; i < index; i++)
	cout << " " << ret[i];
      cout << endl;
    }
  }
  return 0;
}
