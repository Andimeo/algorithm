#include <stdio.h>

#define max(a, b) (a < b ? b : a)
#define min(a, b) (a < b ? a : b)

const int maxn = 504;
const int INF = 1 << 30;

int W[maxn][maxn], n;
int Lx[maxn], Ly[maxn];
int left[maxn];
bool S[maxn], T[maxn];
int slack[maxn];

bool match(int i) {
  S[i] = true;
  for (int j = 1; j <= n; j++) {
    if (T[j]) continue;
    if (Lx[i] + Ly[j] == W[i][j]) {
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
  int d = INF;
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
    left[i] = Lx[i] = Ly[i] = 0;
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

int main(void) {
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
	scanf("%d", &W[i][j]);
    KM();
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      printf("%d", Lx[i]);
      if (i == n) printf("\n");
      else printf(" ");
      sum += Lx[i];
    }
    for (int i = 1; i <= n; i++) {
      printf("%d", Ly[i]);
      if (i == n) printf("\n");
      else printf(" ");
      sum += Ly[i];
    }
    printf("%d\n", sum);
  }
  return 0;
}
