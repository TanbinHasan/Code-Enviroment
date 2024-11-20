#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  int rt, rj, stx, sty, sjx, sjy;
  char ch;
  cin >> rt >> rj >> stx >> ch >> sty >> sjx >> ch >> sjy;
  int st = stx * 100 + sty;
  int sj = sjx * 100 + sjy;
  // cout << rt << " " << rj << " " << st << " " << sj << '\n';
  i64 x = 1LL * (rt - 1) * sj;
  i64 y = 1LL * (rj - 1) * st;
  if (x < y) cout << "TAOYUAN\n";
  else if (y < x) cout << "JAKARTA\n";
  else cout << "SAME\n";
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