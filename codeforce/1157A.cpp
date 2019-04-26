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

int num(int n) {
  int ans = 0;
  while (n) {
    ans ++;
    n /= 10;
  }
  return ans;
}

int main(void) {
  int n;
  while (cin >> n) {
    int result = 0;
    while (num(n) > 1) {
      result += 10 - n % 10;
      n += 10 - n % 10;
      while (n % 10 == 0)
	n /= 10;
    }
    result += 9;
    cout << result << endl;
  }
  
  return 0;
}
