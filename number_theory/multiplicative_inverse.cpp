#include <iostream>

using namespace std;

int extended_gcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int x1, y1;
  int g = extended_gcd(b, a%b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

int mod_inverse(int a, int m) {
  int x, y;
  int g = extended_gcd(a, m, x, y);
  if (g != 1) return -1;
  return (x % m + m) % m;
}

int main() {
  int x, y;
  cout << extended_gcd(30, 20, x, y) << " " << x << " " << y << endl;
  cout << extended_gcd(35, 15, x, y) << " " << x << " " << y << endl;
  cout << mod_inverse(3, 11) << endl;
  cout << mod_inverse(10, 17) << endl;
  return 0;
}
