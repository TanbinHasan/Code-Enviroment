#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

template <int MOD>
class Modular {
 public:
  static const int mod = MOD;
  int v;
  explicit operator int() const { return v; }
  Modular() : v(0) {}
  Modular(i64 _v) : v(int(_v % MOD)) { v += (v < 0) * MOD; }
  Modular& operator+=(Modular o) {
    if ((v += o.v) >= MOD) v -= MOD;
    return *this;
  }
  Modular& operator-=(Modular o) {
    if ((v -= o.v) < 0) v += MOD;
    return *this;
  }
  Modular& operator*=(Modular o) {
    v = int(1LL * v * o.v % MOD);
    return *this;
  }
  friend Modular power(Modular b, i64 p) {
    Modular res = 1;
    while (p > 0) {
      if (p & 1) res *= b;
      b *= b;
      p >>= 1;
    }
    return res;
  }
  friend Modular inv(Modular b) {
    assert(b.v != 0);
    return power(b, MOD - 2);
  }
  friend Modular operator+(Modular a, Modular b) { return a += b; }
  friend Modular operator-(Modular a, Modular b) { return a -= b; }
  friend Modular operator*(Modular a, Modular b) { return a *= b; }
};

using mi = Modular<998244353>;

void PreCalculation(void) {}

#define MultipleCase
void Solve(int tc) {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<i64> f1(n + 1), f2(n + 1);
  vector<mi> dp1(n + 1), dp2(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  f1[1] = max((i64)a[1], llabs(a[1]));
  f2[1] = min((i64)a[1], llabs(a[1]));
  if (a[1] >= 0) dp1[1] = dp2[1] = 2;
  else dp1[1] = dp2[1] = 1;
  for (int i = 2; i <= n; ++i) {
    f1[i] = max({f1[i - 1] + a[i], llabs(f1[i - 1] + a[i]), f2[i - 1] + a[i], llabs(f2[i - 1] + a[i])});
    if (f1[i - 1] != f2[i - 1]) {
      if (f1[i] == f2[i - 1] + a[i]) dp1[i] += dp2[i - 1];
      if (f1[i] == llabs(f2[i - 1] + a[i])) dp1[i] += dp2[i - 1];
    }
    if (f1[i] == llabs(f1[i - 1] + a[i])) dp1[i] += dp1[i - 1];
    if (f1[i] == f1[i - 1] + a[i]) dp1[i] += dp1[i - 1];

    f2[i] = min({f1[i - 1] + a[i], llabs(f1[i - 1] + a[i]), f2[i - 1] + a[i], llabs(f2[i - 1] + a[i])});
    if (f1[i - 1] != f2[i - 1]) {
      if (f2[i] == f2[i - 1] + a[i]) dp2[i] += dp2[i - 1];
      if (f2[i] == llabs(f2[i - 1] + a[i])) dp2[i] += dp2[i - 1];
    }
    if (f2[i] == llabs(f1[i - 1] + a[i])) dp2[i] += dp1[i - 1];
    if (f2[i] == f1[i - 1] + a[i]) dp2[i] += dp1[i - 1];
  }
  cout << (int) dp1[n] << '\n';
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