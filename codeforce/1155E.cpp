#include <iostream>
#include <cassert>

using namespace std;

typedef long long LL;

const LL MOD = 1000000 + 3;
const int NUM = 11;
LL x[NUM][NUM + 1], a[NUM];

LL pow(LL a, LL b) {
  if (!b) return 1;
  if (b == 1) return (a + MOD) % MOD;
  LL r = pow(a, b / 2);
  r = (r * r) % MOD;
  if (b % 2) r = r * a % MOD;
  return r;
}

LL extended_gcd(LL a, LL b, LL& x, LL& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  LL x1, y1;
  LL g = extended_gcd(b, a%b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

LL mod_inverse(LL a, LL m) {
  LL x, y;
  LL g = extended_gcd(a, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}

LL calc(LL x) {
  LL result = 0;
  for (int i = 0 ; i < NUM; i++) {
    result = (result + a[i] * pow(x, i) % MOD) % MOD;
  }
  return result;
}

int main(){
  for (int i = 0; i < NUM; i++) {
    for (int j = 0; j < NUM; j++) {
      x[i][j] = pow(i, j);
    }
  }
  
  for (int i = 0; i < NUM; i++) {
    cout << "? " << i << endl;
    cin >> x[i][NUM];
  }

  for (int i = 0 ; i + 1 < NUM; i++) {
    assert(x[i][i] != 0);
    LL inverse = mod_inverse(x[i][i], MOD);
    for (int j = i + 1; j < NUM; j++) {
      LL coef = inverse * x[j][i] % MOD;
      for (int k = i; k < NUM + 1; k++) {
	x[j][k] = (x[j][k] - x[i][k] * coef % MOD + MOD) % MOD;
      }
    }
  }

  for (int i = NUM - 1; i >= 0; i--) {
    LL right = 0;
    for (int j = i + 1; j < NUM; j++) {
      right = (right + a[j] * x[i][j] % MOD) % MOD;
    }
    right = (x[i][NUM] - right + MOD) % MOD;
    LL inverse = mod_inverse(x[i][i], MOD);
    a[i] = inverse * right % MOD;
  }

  for (int i = 0 ; i < MOD; i++) {
    if (!calc(i)) {
      cout << "! " << i << endl;
      return 0;
    }
  }
  cout << "! " << -1 << endl;
  return 0;
}
