#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T, class C = less<T>>
using iset = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long i64;

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  iset<int> si;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    si.insert(i);
  }
  int prv = 1;
  while ((int)si.size() > 1) {
    int ind = si.order_of_key(prv);
    
    int rem = (a[prv] + ind) % (int)si.size();
    rem = (rem - 1 + (int)si.size()) % (int)si.size();

    prv = (rem + 1) % (int)si.size();
    prv = *si.find_by_order(prv);
    si.erase(si.find_by_order(rem));
    // cout << prv << "\n";
  }
  cout << *(si).begin() << '\n';
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
/*
1 3 4 5 6 7 8 9 10 
1 4 5 6 7 8 9 10 
1 5 6 7 8 9 10 
1 6 7 8 9 10 
1 7 8 9 10 
1 8 9 10 
1 9 10 
1 10 
10 
10  
*/