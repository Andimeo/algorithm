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

int num[maxn];

int main(void) {
  int n;
  while (cin >> n) {
    for (int i = 0 ; i < n ; i++)
      cin >> num[i];
    int left = 0, right = n - 1;
    vector<int> result;
    vector<char> op;
    int len = 0;
    while (left <= right) {
      int v = -1;
      char vv;
      if (!len || result[len - 1] < num[left]) {
	v = num[left];
	vv = 'L';
      }
      if (!len || result[len - 1] < num[right]) {
	if (v == -1 || v > num[right]) {
	  v = num[right];
	  vv = 'R';
	}
      }
      if (v == -1) {
	break;
      }

      if (v == num[left])
	left++;
      else
	right--;
      result.push_back(v);
      op.push_back(vv);
      len++;
    }
    cout << len << endl;
    for (int i = 0 ; i < len; i++) {
      cout << op[i];
    }
    cout << endl;
  }
  
  return 0;
}
