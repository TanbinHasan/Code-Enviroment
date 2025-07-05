#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void precalc(void) {}

// #define testcase
void solve(int tc) {
  int n;
  cin >> n;
  cout << n * n << '\n';
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