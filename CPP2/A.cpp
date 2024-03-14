#include <bits/stdc++.h>

#define int long long
#define ll __int128_t

using namespace std;

template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1);
  template <typename... Args>
  Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void PreCalc(void) {}

#define MultipleCase       
void Solve(__attribute__((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  int ans = (n * (n + 1)) / 2LL;
  int cnt = 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1]) {
      ++cnt;
    } else {
      // cout << cnt << " ";
      int x = (cnt * (cnt + 1)) / 2LL;
      ans -= x;
      cnt = 1;
    }
  }
  ans -= (cnt * (cnt + 1)) / 2LL;
  cout << ans << '\n';
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  PreCalc();
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}
/* 
Case 1: 6
Case 2: 19 
*/