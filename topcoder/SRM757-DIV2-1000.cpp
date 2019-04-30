#include <bits/stdc++.h>

using namespace std;

class CentipedeSocks {
public:
  int fewestSocks(int C, int F, vector <int> sockCounts) {
    int sum = 0;
    for (int i = 0; i < C; i++) {
      if (i == 0) {
	for (int j = 0 ; j < sockCounts.size(); j++) {
	  if (sockCounts[j] < F - 1) {
	    int v = min(sockCounts[j], F - 1);
	    sum += v;
	    sockCounts[j] -= v;
	  } else {
	    sockCounts[j] -= F - 1;
	    sum += F - 1;
	  }
	}

	sort(sockCounts.begin(), sockCounts.end());
	int n = sockCounts.size() - 1;
	if (sockCounts[n] > 0) {
	  sockCounts[n] -= 1;
	  sum += 1;
	} else {
	  return -1;
	}
      } else {
	int n = sockCounts.size() - 1;
	int v = min(sockCounts[n], F - 1);
	sum += v;
	sockCounts[n] -= v;
	sort(sockCounts.begin(), sockCounts.end());
	if (sockCounts[n] > 0) {
	  sockCounts[n] -= 1;
	  sum += 1;
	} else return -1;
      }
    }
    return sum;
  }
};


