#include <bits/stdc++.h>

#define int long long
#define ll int128_t

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

int LIS(vector<int>& ar) {
  vector<int> v;
  for (auto& i : ar) {
    auto it = lower_bound(v.begin(), v.end(), i);
    if (it == (v).end())
      v.push_back(i);
    else
      *it = i;
  }
  return (int)v.size();
}

#define MultipleCase
void Solve(__attribute((unused)) int tc) {
  cout << "Case " << tc << ": ";
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }
  vector<int> b(n);
  for (auto& i : b) {
    cin >> i;
  }
  if (a == b) {
    cout << 0 << '\n';
    return;
  }
  vector<bool> vis(n);
  vector<int> ind(n, -1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[j] != b[i]) continue;
      if (vis[j]) continue;
      vis[j] = true;
      ind[i] = j;
      break;
    }
  }
  int l = 0, r = n - 1;
  for (int i = 0; i < n - 1; ++i) {
    if (ind[i + 1] == -1) {
      l = i + 1;
      break;
    }
    if (ind[i] > ind[i + 1]) {
      l = i + 1;
      break;
    }
  }
  for (int i = n - 1; i >= 1; --i) {
    if (ind[i - 1] == -1) {
      r = i - 1;
      break;
    }
    if (ind[i - 1] > ind[i]) {
      r = i - 1;
      break;
    }
  }
  int ans = r - l + 1;
  vector<int> v;
  for (int i = 0; i < l; ++i) {
    v.push_back(ind[i]);
  }
  for (int i = r + 1; i < n; ++i) {
    v.push_back(ind[i]);
  }
  int lis = LIS(v);
  cout << ans + ((int)v.size() - lis) << '\n';
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