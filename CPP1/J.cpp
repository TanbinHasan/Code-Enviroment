#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<pair<int, int>> si;
  for (int mask = 0; mask < (1LL << n); ++mask) {
    bool ok = true;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
      int cur = ((mask >> i) & 1LL);
      // if (cur == 1) 
    }
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