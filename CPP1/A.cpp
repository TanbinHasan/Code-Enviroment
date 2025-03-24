#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void precalc(void) {}

// #define testcase
void solve(int tc) {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, vector<int>> ind;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ind[a[i]].push_back(i);
  }
  int ans = numeric_limits<int>::max();
  for (auto& [k, v] : ind) {
    for (int i = 0; i + 1 < (int)v.size(); ++i) {
      ans = min(ans, v[i + 1] - v[i] + 1);
    }
  }
  if (ans == numeric_limits<int>::max()) ans = -1;
  cout << ans << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  precalc();
  int tt = 1;
#ifdef testcase
  cin >> tt;
#endif
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
  }
  return 0;
}