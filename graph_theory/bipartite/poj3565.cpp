#include <stdio.h>
#include <math.h>

#define max(a, b) (a < b ? b : a)
#define min(a, b) (a < b ? a : b)

const int maxn = 104;
const double INF = 1e20;
const double eps = 1e-8;

double W[maxn][maxn];
int n;
double Lx[maxn], Ly[maxn];
int left[maxn];
bool S[maxn], T[maxn];
double slack[maxn];

bool eqs(double d) {
  return fabs(d) < eps;
}

bool match(int i) {
  S[i] = true;
  for (int j = 1; j <= n; j++) {
    if (T[j]) continue;
    if (eqs(Lx[i] + Ly[j] - W[i][j])) {
      T[j] = true;
      if (!left[j] || match(left[j])) {
	left[j] = i;
	return true;
      }
    } else {
      slack[j] = min(slack[j], Lx[i] + Ly[j] - W[i][j]);
    }
  }
  return false;
}

void update() {
  double d = INF;
  for (int i = 1; i <= n; i++)
    if (!T[i])
      d = min(d, slack[i]);
  for (int i = 1; i <= n; i++) {
    if (S[i]) Lx[i] -= d;
    if (T[i]) Ly[i] += d;
    else slack[i] -= d;
  }
}

void KM() {
  for (int i = 1; i <= n; i++) {
    left[i] = 0;
    Lx[i] = -INF;
    Ly[i] = 0;
    for (int j = 1; j <= n; j++) {
      Lx[i] = max(Lx[i], W[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      slack[j] = INF;
    while (true) {
      for (int j = 1; j <= n; j++) {
	S[j] = T[j] = false;
      }
      if (match(i)) break;
      else update();
    }
  }
}

double xa[maxn], ya[maxn], xp[maxn], yp[maxn];

double dist(int x1, int y1, int x2, int y2) {
  return sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
}

int main(void) {
  
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++) {
      scanf("%lf%lf", xa + i, ya + i);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%lf%lf", xp + i, yp + i);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
	W[i][j] = -dist(xa[i], ya[i], xp[j], yp[j]);
      }
    }
    KM();
    int result[maxn];
    for (int i = 1; i <= n; i++) {
      result[left[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
      printf("%d\n", result[i]);
    }
  }
  return 0;
}
