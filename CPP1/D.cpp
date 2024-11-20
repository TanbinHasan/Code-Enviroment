#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  i64 n;
  cin >> n;
  cout << n * 4000LL << '\n';
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