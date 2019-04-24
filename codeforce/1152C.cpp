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

void swap(ll &a, ll &b) {
  ll t = a;
  a = b;
  b = t;
}


int main(void) {
  ll a, b;
  while (cin >> a >> b) {
    if (a < b) {
      swap(a, b);
    }
    if (a % b == 0) {
      cout << "0" << endl;
      continue;
    }
    vector<ll> v;
    for (int i = 1; i * i <= a - b; i++) {
      if ((a - b) % i == 0) {
	v.push_back(i);
	if (i != (a - b) / i)
	  v.push_back((a-b)/i);
      }
    }
    ll lcm = 1e18 + 4;
    ll ans = -1;
    for (int i = 0 ; i < v.size(); i++) {
      ll k = (v[i] - b % v[i]) % v[i];
      ll x = a + k, y = b + k;
      if (x * y / v[i] < lcm) {
	lcm = x * y / v[i];
	ans = k;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
