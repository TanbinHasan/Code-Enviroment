#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to evaluate the boolean expression in O(N)
vector<bool> evaluate(const vector<string>& expr) {
  int n = expr.size();
  vector<bool> prefix(n), suffix(n), result(n);
  vector<bool> value(n);

  // Convert the string values to boolean
  for (int i = 0; i < n; i += 2) {
    value[i] = (expr[i] == "true");
  }

  // Calculate prefix
  prefix[0] = value[0];
  for (int i = 1; i < n; i += 2) {
    if (expr[i] == "and") {
      prefix[i + 1] = prefix[i - 1] && value[i + 1];
    } else {
      prefix[i + 1] = prefix[i - 1] || value[i + 1];
    }
  }

  // Calculate suffix
  suffix[n - 1] = value[n - 1];
  for (int i = n - 2; i > 0; i -= 2) {
    if (expr[i] == "and") {
      suffix[i - 1] = suffix[i + 1] && value[i - 1];
    } else {
      suffix[i - 1] = suffix[i + 1] || value[i - 1];
    }
  }

  // Combine prefix and suffix
  for (int i = 0; i < n; i += 2) {
    bool left = i > 0 ? prefix[i - 1] : true;
    bool right = i < n - 1 ? suffix[i + 1] : true;
    result[i] = left && right;
  }

  return result;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<string> statement(N);
  for (int i = 0; i < N; ++i) {
    cin >> statement[i];
  }

  // Evaluate the statement once
  vector<bool> evalResult = evaluate(statement);

  string output;
  for (int i = 0; i < Q; ++i) {
    int l, r;
    string value;
    cin >> l >> r >> value;
    bool queryResult = (value == "true");

    // Check if the query is possible
    bool possible = (l == 1 || evalResult[l - 2] == queryResult) &&
                    (r == N - 1 || evalResult[r] == queryResult);

    output += (possible ? 'Y' : 'N');
  }

  cout << output << endl;
  return 0;
}
