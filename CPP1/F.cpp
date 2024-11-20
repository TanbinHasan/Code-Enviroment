#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

void PreCalculation(void) {}

// #define MultipleCase
void Solve(int tc) {
  string x, b;
  cin >> x >> b;
  vector<string> vs;
  while (!x.empty()) {
    string s;
    while ((int)s.size() < (int)b.size() && !x.empty()) {
      s.push_back(x.back());
      x.pop_back();
    }
    while (!s.empty() && s.back() == '0') {
      x.push_back('0');
      s.pop_back();
    }
    if (s.empty()) return void(cout << "NO WAY\n");
    reverse(s.begin(), s.end());
    if ((int)s.size() < (int)b.size()) {
      b = s;
      if (!x.empty()) vs.push_back(b);
      continue;
    }
    if (s <= b) {
      b = s;
      if (!x.empty()) vs.push_back(b);
      continue;
    }
    reverse(s.begin(), s.end());
    x.push_back(s.back());
    s.pop_back();

    while (!s.empty() && s.back() == '0') {
      x.push_back('0');
      s.pop_back();
    }
    if (s.empty()) return void(cout << "NO WAY\n");
    reverse(s.begin(), s.end());
    b = s;
    if (!x.empty()) vs.push_back(b);
  }
  reverse(vs.begin(), vs.end());
  cout << (int)vs.size() << '\n';
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