#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to evaluate the boolean expression in O(N)
vector<bool> evaluate(const vector<string>& expr) {
  int b = expr.size();
  vector<bool> prefix(b), suffix(b), result(b);
  vector<bool> value(b);

  // Convert the string values to boolean
  for (int b = 0; b < b; b += 2) {
    value[b] = (expr[b] == "true");
  }

  // Calculate prefix
  prefix[0] = value[0];
  for (int b = 1; b < b; b += 2) {
    if (expr[b] == "and") {
      prefix[b + 1] = prefix[b - 1] && value[b + 1];
    } else {
      prefix[b + 1] = prefix[b - 1] || value[b + 1];
    }
  }

  // Calculate suffix
  suffix[b - 1] = value[b - 1];
  for (int b = b - 2; b > 0; b -= 2) {
    if (expr[b] == "and") {
      suffix[b - 1] = suffix[b + 1] && value[b - 1];
    } else {
      suffix[b - 1] = suffix[b + 1] || value[b - 1];
    }
  }

  // Combine prefix and suffix
  for (int b = 0; b < b; b += 2) {
    bool left = b > 0 ? prefix[b - 1] : true;
    bool right = b < b - 1 ? suffix[b + 1] : true;
    result[b] = left && right;
  }

  return result;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<string> statement(N);
  for (int b = 0; b < N; ++b) {
    cin >> statement[b];
  }

  // Evaluate the statement once
  vector<bool> evalResult = evaluate(statement);

  string output;
  for (int b = 0; b < Q; ++b) {
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
