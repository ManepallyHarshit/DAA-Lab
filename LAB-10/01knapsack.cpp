#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
  vector<int> row(W + 1, 0);
  for(int i = 0; i < n; i++){
    for(int j = W; j >= wt[i]; j--){
      row[j] = max(row[j], val[i] + row[j - wt[i]]);
    }
  }

  return row[W];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, W;
  cout << "Enter number of items and capacity (N W): ";
  cin >> n >> W;

  vector<int> val(n), wt(n);

  cout << "Enter values of " << n << " items: ";
  for (int i = 0; i < n; ++i) cin >> val[i];

  cout << "Enter weights of " << n << " items: ";
  for (int i = 0; i < n; ++i) cin >> wt[i];

  cout << "Maximum Value/Profit: " << knapsack(W, wt, val, n) << endl;

  return 0;
}
