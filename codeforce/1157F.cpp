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

const int maxn = 200000 + 4;
int a[maxn];

int main(void) {
  int n;
  while (cin >> n) {
    memset(a, 0, sizeof(a));
    for (int i = 0 ; i < n; i++) {
      int v;
      cin >> v;
      a[v] += 1;
    }
    vector<pair<int, int> > b;
    for(int i = 0 ; i < maxn ; i++) {
      if (a[i]) {
	b.push_back(make_pair(i, a[i]));
      }
    }
    int m = b.size();
    int pos = m - 1;
    int result = 0;
    vector<int> ans;
    while (pos >= 0) {
      int v = b[pos].second;
      bool flag = true;
      int new_pos = 0;
      int end = 0;
      for (int i = pos - 1; i >= 0; i--) {
	if (b[i].first + 1 == b[i + 1].first && b[i].second > 1) {
	  v += b[i].second;
	} else if(b[i].first + 1 == b[i + 1].first && b[i].second == 1) {
	  v += 1;
	  new_pos = i;
	  end = i;
	  flag = false;
	  break;
	} else {
	  new_pos = i;
	  end = i + 1;
	  flag = false;
	  break;
	}
      }
      if (v > result) {
	result = v;
	ans.clear();
	ans.assign(v, 0);
	int left = 0, right = 1;
	int index = 0;
	for (int j = pos; j >= end; j--) {
	  for (int k = 0; k < b[j].second; k++) {
	    if (index % 2 == 0) {
	      ans[left] = b[j].first;
	      left = (left - 1 + v) % v;
	    } else {
	      ans[right] = b[j].first;
	      right = (right + 1) % v;
	    }
	    index ^= 1;
	  }
	}
      }
      pos = new_pos;
      if (flag) pos -= 1;
    }
    cout << result << endl;
    for (int i = 0 ; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
