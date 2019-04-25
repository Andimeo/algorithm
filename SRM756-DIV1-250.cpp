#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <limits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <iomanip>

using namespace std;

typedef long long ll;

#define SZ(v) (int)(v.size())
#define min(a, b) (a < b ? a : b)

int a[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000,
		50000 };
int b[15];

int calc(int mm) {
	memset(b, 0, sizeof(b));
	int sum1 = 0;
	for (int i = 14; i >= 0; i--) {
		b[i] = mm / a[i];
		mm = mm % a[i];
		sum1 += b[i];
	}
	return sum1;
}

class NewBanknote {
public:
	vector<int> fewestPieces(int ne, vector<int> am) {
		vector<int> result;
		for (int i = 0; i < SZ(am); i++) {
			int sum1 = calc(am[i]);
			for (int j = 1; j < sum1; j++) {
				if (am[i] < (ll)j * ne)
					break;
				int sum2 = calc(am[i] - (ll)j * ne) + j;
				sum1 = min(sum1, sum2);
			}
			result.push_back(sum1);
		}
		return result;
	}
};
