#include <bits/stdc++.h>

using namespace std;

const int MAX = 100004;
char s[MAX];
int SA[MAX], tempSA[MAX], RA[MAX], tempRA[MAX], n;
int c[MAX];
int phi[MAX], PLCP[MAX], LCP[MAX];

void countingSort(int k) {
  int sum = 0, maxi = max(300, n);
  memset(c, 0, sizeof(c));
  for (int i = 0 ; i < n ; i++) c[i + k < n ? RA[i + k] : 0]++;
  for (int i = 0; i < maxi; i++) {
    int t = c[i];
    c[i] = sum;
    sum += t;
  }
  for (int i = 0; i < n; i++)
    tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
  for (int i = 0 ; i < n ; i++)
    SA[i] = tempSA[i];
}

void constructSA() {
  for (int i = 0 ; i < n ; i++) RA[i] = s[i];
  for (int i = 0 ; i < n ; i++) SA[i] = i;
  for (int k = 1; k < n ; k <<= 1) {
    countingSort(k);
    countingSort(0);
    tempRA[SA[0]] = 0;
    int r = 1;
    for (int i = 1; i < n ; i++) {
      if (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k])
	tempRA[SA[i]] = r - 1;
      else
	tempRA[SA[i]] = r++;
    }
    for (int i = 0 ; i < n ; i++)
      RA[i] = tempRA[i];
    if (r == n) break;
  }
}

void computeLCP() {
  phi[SA[0]] = -1;
  for (int i = 1; i < n ; i++)
    phi[SA[i]] = SA[i-1];
  int L = 0;
  for (int i = 0; i < n ; i++) {
    if(phi[i] == -1) {PLCP[i] = 0; continue;}
    while (s[i + L] == s[phi[i] + L]) L++;
    PLCP[i] = L;
    L = max(L-1, 0);
  }
  for (int i = 0 ; i < n; i++)
    LCP[i] = PLCP[SA[i]];
}

int main(void) {
  strncpy(s, "abab", 4);
  n = strlen(s);
  s[n++] = '$';
  constructSA();
  for (int i = 0 ; i < n; i++)
    cout << SA[i] << " ";
  cout << endl;
  computeLCP();
  for (int i = 0 ; i < n ; i++)
    cout << PLCP[i] << " " ;
  cout << endl;
  for (int i = 0 ; i < n ; i++)
    cout << LCP[i] << " " ;
  cout << endl;

  return 0;
}
