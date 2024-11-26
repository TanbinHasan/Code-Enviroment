#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  s = "#" + s;
  vector<int> ind1, ind2, indsl;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '1') ind1.push_back(i);
    if (s[i] == '2') ind2.push_back(i);
    if (s[i] == '/') indsl.push_back(i);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int l1 = lower_bound(ind1.begin(), ind1.end(), l) - (ind1).begin();
    if (l1 == (int)ind1.size() || l1 > r) {
      int cur = lower_bound(indsl.begin(), indsl.end(), l) - (indsl).begin();
      if (cur != (int)indsl.size() && cur <= r) cout << 1 << '\n';
      else cout << 0 << '\n';
      continue;
    }
    int ans = 0;
    int sz = r - l + 1;
    int lo = 1, hi = sz;
    while (lo <= hi) {
      int m = (lo + hi) / 2LL;
      if (2 * m > sz) {
        hi = m - 1;
        continue;
      }
      int r1 = l1 + m - 1;
      if (r1 >= (int)ind1.size()) {
        hi = m - 1;
        continue;
      }
      int pos_sl = lower_bound(indsl.begin(), indsl.end(), r1) - (indsl).begin();
      if (pos_sl == (int)indsl.size() || pos_sl > r) {
        hi = m - 1;
        continue;
      }
      int l2 = lower_bound(ind2.begin(), ind2.end(), pos_sl) - (ind2).begin();
      int r2 = l2 + m - 1;
      if (r2 >= (int)ind2.size()) hi = m - 1;
      else {
        ans = 2 * m + 1;
        lo = m + 1;
      }
    }
    cout << ans << '\n';
  }
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