#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

const int MAX = 204;

map<double, int> v2i;
map<int, double> i2v;
double all[MAX << 1];

struct Seg{
  int l, r, d;
  double y;
  bool operator<(const Seg& s) const {
    return y < s.y;
  }
}segs[MAX << 1];

double sum[MAX << 2];
int v[MAX << 2];

void push_up(int index, int L, int R) {
  if(v[index]) sum[index] = i2v[R+1] - i2v[L];
  else if(L == R) sum[index] = 0;
  else sum[index] = sum[index*2+1] + sum[index*2+2];
  //cout << index << " " << L << " " << R << " " << sum[index] << endl;
}

void update(int index, int L, int R, int l, int r, int d) {
  //cout << index << " " << L << " " << R << " " << l << " " << r << " " << d << endl;
  if (l <= L && r >= R) {
    v[index] += d;
    push_up(index, L, R);
    return;
  }
  int m = (L + R) >> 1;
  if (l <= m) update(index*2+1, L, m, l, min(r, m), d);
  if (r > m) update(index*2+2, m+1, R, max(l, m+1), r, d);
  push_up(index, L, R);
}

double x1[MAX], Y1[MAX], x2[MAX], y2[MAX];

int main(void) {
  int n, tcase = 1;
  while (cin >> n && n) {
    for (int i = 0 ; i < n ; i++) {
      cin >> x1[i] >> Y1[i] >> x2[i] >> y2[i];
      all[i] = x1[i];
      all[i+n] = x2[i];
    }
    sort(all, all + 2 * n);
    int index = 0;
    v2i.clear(); i2v.clear();
    memset(v, 0, sizeof(v));
    memset(sum, 0, sizeof(sum));
    v2i[all[0]] = index; i2v[index] = all[0]; index++;
    for (int i = 1; i < 2 * n; i++)
      if (all[i] != all[i-1]) {
	v2i[all[i]] = index;
	i2v[index++] = all[i];
      }
    for (int i = 0 ; i < n ; i++) {
      segs[i] = {v2i[x1[i]], v2i[x2[i]], 1, Y1[i]};
      segs[i+n] = {v2i[x1[i]], v2i[x2[i]], -1, y2[i]};
    }
    sort(segs, segs + 2 * n);
    double result = 0.0;
    for (int i = 0; i < 2 * n; i++) {
      result += sum[0] * (segs[i].y - segs[i-1].y);
      //cout << "result: ";
      //cout << i << " " << sum[0] << " " << result << endl;
      //cout << "seg: ";
      //cout << segs[i].l << " " << segs[i].r << " " << segs[i].d << endl;
      update(0, 0, v2i.size(), segs[i].l, segs[i].r - 1, segs[i].d);
    }
    if (tcase > 1)
      printf("\n");
    printf("Test case #%d\nTotal explored area: %.2f\n", tcase++, result);
  }
  return 0;
}
