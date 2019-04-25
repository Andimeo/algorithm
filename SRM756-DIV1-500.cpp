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

class CrazyCrazy {
public:
	string possible(string song) {
		vector<char> l, r;
		map<string, bool> m;
		int n = song.length() / 2;
		for (int i = 0; i < (1 << n); i++) {
			l.clear();
			r.clear();
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j))) {
					l.push_back(song[j]);
				} else {
					r.push_back(song[j]);
				}
			}
			bool flag = true;
			int j;
			for (j = 0; j < SZ(l) && j < SZ(r); j++) {
				if (l[j] != r[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				string s = "";
				vector<char> &h = j < SZ(l) ? l : r;
				for (int k = j; k < SZ(h); k++)
					s = s + h[k];
				m[s] = true;
			}
		}

		for (int i = 0; i < (1 << n); i++) {
			l.clear();
			r.clear();
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j))) {
					l.push_back(song[n + n - j - 1]);
				} else {
					r.push_back(song[n + n - j - 1]);
				}
			}
			bool flag = true;
			int j;
			for (j = 0; j < SZ(l) && j < SZ(r); j++) {
				if (l[j] != r[j]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				string s = "";
				vector<char> &h = j < SZ(l) ? l : r;
				for (int k = j; k < SZ(h); k++)
					s = s + h[k];
				string ss = "";
				for (int i = s.length() - 1; i >= 0; i--)
					ss = ss + s[i];
				if (m.find(ss) != m.end()) {
					return "possible";
				}
			}
		}
		return "impossible";
	}
};

int main() {
	CrazyCrazy c;
	cout << c.possible("aacfcfqqsmksimkoioeertbrtbhphnpnggddjjll") << endl;
}
