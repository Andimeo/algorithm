#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

vector<ll> factorize(ll n) 
{
  vector<ll> res;
  int count = 0; 
  while (!(n % 2)) { 
    n >>= 1;
    count++; 
  } 
  
  if (count) 
    res.push_back(2);
  
  ll root = (ll)(sqrt(n) + 1);
  for (ll i = 3; i <= root; i += 2) { 
    count = 0; 
    while (n % i == 0) { 
      count++; 
      n = n / i; 
    } 
    if (count) 
      res.push_back(i);
  } 
  
  if (n > 2) 
    res.push_back(n);
  return res;
}
