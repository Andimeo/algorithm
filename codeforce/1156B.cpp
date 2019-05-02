#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool is_valid(string r) {
  for (int i = 1; i < r.length(); i++)
    if (abs(r[i] - r[i-1]) == 1)
      return false;
  return true;
}

void swap(int& a, int& b) {
  int c = a;
  a = b;
  b = c;
}

int main(void) {
  int t;
  while (cin >> t) {
    while (t--) {
      string q;
      cin >> q;
      int num[26] = {0};
      int sum[2] = {0};
      for (int i = 0 ; i < q.length(); i++) {
	num[q[i]-'a']++;
	sum[(q[i]-'a')%2]++;
      }
      string r = "";
      if (sum[0] == 0 || sum[1] == 0) {
	for (int i = 0 ; i < 26; i+= 2) {
	  for (int j = 0 ; j < num[i] ;j++)
	    r += i + 'a';
	}
	for (int i = 1 ; i < 26; i+= 2) {
	  for (int j = 0 ; j < num[i] ;j++)
	    r += i + 'a';
	}
	cout << r << endl;
	continue;
      }
      bool ok = false;
      int pos1, pos2;
      for (pos1 = 0; pos1 < 26; pos1 += 2) {
	for (pos2 = 1; pos2 < 26; pos2 += 2) {
	  if (abs(pos1 - pos2) == 1) continue;
	  if (num[pos1] > 0 && num[pos2] > 0) {
	    ok = true;
	    break;
	  }
	}
	if (ok) break;
      }
      if (ok) {
	num[pos1]--;
	num[pos2]--;
	for (int i = 0 ; i < 26; i+= 2) {
	  for (int j = 0 ; j < num[i] ;j++)
	    r += i + 'a';
	}
	r += pos1 + 'a';
	r += pos2 + 'a';
	for (int i = 1 ; i < 26; i+= 2) {
	  for (int j = 0 ; j < num[i] ;j++)
	    r += i + 'a';
	}
      }
      cout << (ok ? r : "No answer") << endl;
    }
  }
  return 0;
}
