// C:\Compilers\mingw64\include\c++\12.2.0\x86_64-w64-mingw32\bits
// C:\Compilers\mingw64\include\c++\12.2.0\ext\pb_ds
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace __gnu_pbds;
template <class T, class C = less<T>>
using iset = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class C = less_equal<T>>
using imultiset = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
/* Index of lower bound & upper bound for "indexed set / multiset":
  int lb = s.order_of_key(x);
  int ub = s.order_of_key(x + 1);
*/

// #define MultipleCase
void Solve(__attribute__((unused)) int tc) {
  
}

int32_t main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int tt = 1, tc = 0;
#ifdef MultipleCase
  cin >> tt;
#endif
  while (tt--) Solve(++tc);
  return 0;
}