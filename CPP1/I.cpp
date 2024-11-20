#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  ll n;
  cin>>n;
  ll a[n];
  map<ll,ll>mp;
  for(int i=0;i<n;i++){
    cin>>a[i];
    mp[a[i]]++;
  }
  sort(a,a+n);
  mp[a[0]]--;
  if(n<4){
    cout<<"-1\n";
    return;
  }
  ll mx=-1;
  for(int i=1;i<n-1;i++){
    ll d=a[i]-a[0];
    mp[a[i]]--;
    if(mp[a[n-1]-d]){
      mx=max(mx,d);
    }
    mp[a[i]]++;
  }
  cout<<mx<<'\n';
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