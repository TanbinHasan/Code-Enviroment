#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  ll n;
  cin>>n;
  ll a[n][n];
  for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
      cin>>a[i][j];
    }
  }
  cout<<a[0][0]*a[0][n-1]*a[n-1][0]*a[n-1][n-1]<<'\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalculation();
  int tt = 1;
#ifdef MultipleCase
  cin >> tt;
#endif
  for (int tc = 1; tc <= tt; ++tc) {
    Solve(tc);
  }
  return 0;
}