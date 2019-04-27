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
      if (num[left] == num[right])
	break;
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
    if (num[left] == num[right] && (!len || num[left] > result[len - 1]) && left <= right) {
      int left_max = 1;
      int right_max = 1;
      for (int i = left + 1; i <= right; i++)
	if (num[i] > num[i-1]) left_max++;
	else break;
      for (int i = right-1; i >= left; i--)
	if (num[i] > num[i+1]) right_max++;
	else break;
      if (left_max >= right_max) {
	len += left_max;
	for (int i = 0 ; i < left_max;i++) op.push_back('L');
	
      }else {
	len += right_max;
	for(int i = 0 ; i < right_max;i++) op.push_back('R');
      }
    }
    
    
    cout << len << endl;
    for (int i = 0 ; i < len; i++) {
      cout << op[i];
    }
    cout << endl;
  }
  
  return 0;
}
