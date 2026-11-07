#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int matrixChainOrder(const vector<int>& p) {
  int n = p.size() - 1;
  if (n <= 1) return 0;

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int L = 2; L <= n; L++) {
    for (int i = 1; i <= n - L + 1; i++) {
      int j = i + L - 1;
      dp[i][j] = INT_MAX;

      for (int k = i; k < j; k++) {
        int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
        dp[i][j] = min(dp[i][j], cost);
      }
    }
  }
  return dp[1][n];
}

void printOptimalParens(const vector<vector<int>>& s, int i, int j) {
  if (i == j) {
    cout << "A" << i;
  } else {
    cout << "(";
    printOptimalParens(s, i, s[i][j]);
    printOptimalParens(s, s[i][j] + 1, j);
    cout << ")";
  }
}

int matrixChainOrderWithParens(const vector<int>& p) {
  int n = p.size() - 1;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  vector<vector<int>> split(n + 1, vector<int>(n + 1, 0));

  for (int L = 2; L <= n; L++) {
    for (int i = 1; i <= n - L + 1; i++) {
      int j = i + L - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (cost < dp[i][j]) {
          dp[i][j] = cost;
          split[i][j] = k;
        }
      }
    }
  }

  cout << "Optimal Parenthesization: ";
  printOptimalParens(split, 1, n);
  cout << "\nMinimum multiplications: ";
  return dp[1][n];
}

int main() {
  int n;
  cout << "Enter number of matrices: ";
  cin >> n;

  if (n <= 1) {
    cout << "At least 2 matrices required\n";
    return 0;
  }

  vector<int> p(n + 1);
  cout << "Enter " << n + 1 << " dimensions: ";
  for (int i = 0; i <= n; i++) {
    cin >> p[i];
  }

  cout << "\nMatrix dimensions: ";
  for (int i = 0; i < n; i++) {
    cout << "A" << i + 1 << "(" << p[i] << "x" << p[i + 1] << ") ";
  }
  cout << "\n\n";

  int minCost = matrixChainOrderWithParens(p);
  cout << minCost << "\n";

  return 0;
}
