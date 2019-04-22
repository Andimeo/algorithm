#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;


long long max(long long a, long long b) {
  return a > b ? a : b;
}

long long max(long long a, long long b, long long c) {
  return max(a, max(b, c));
}

long long num[300000 + 4];
long long dp1[300000 + 4];
long long dp2[300000 + 4];
long long dp3[300000 + 4];

long long max_segment_sum(int n, int x) {
  long long result = 0;
  for (int i = 0 ; i < n ; i++) {
    if (i == 0) {
      dp1[i] = num[i];
      dp2[i] = num[i] * x;
      dp3[i] = 0;
    } else {

      long long a = dp1[i - 1] + num[i];
      long long b = num[i];
      dp1[i] = max(a, b);
      
      a = dp1[i - 1] + x * num[i];
      b = dp2[i - 1] + x * num[i];
      long long c = x * num[i];
      dp2[i] = max(a, b, c);
      
      a = dp3[i - 1] + num[i];
      b = dp2[i - 1] + num[i];
      dp3[i] = max(a, b);
    }
    result = max(result, max(dp1[i], dp2[i], dp3[i]));
  }
  return result;
}

int main(void) {
  int n, x;
  while(cin >> n >> x) {
    for (int i = 0 ; i < n ; i++) {
      cin >> num[i];
    }
    cout << max_segment_sum(n, x) << endl;
  }
  
  return 0;
}
