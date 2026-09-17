#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxCrossingSum(const vector<int>& arr, int low, int mid, int high) {
  int sum = 0;
  int leftSum = INT_MIN;
  for (int i = mid; i >= low; i--) {
    sum += arr[i];
    if (sum > leftSum) leftSum = sum;
  }

  sum = 0;
  int rightSum = INT_MIN;
  for (int i = mid + 1; i <= high; i++) {
    sum += arr[i];
    if (sum > rightSum) rightSum = sum;
  }

  return leftSum + rightSum;
}

int maxSubarraySum(const vector<int>& arr, int low, int high) {
  if (low == high) return arr[low];

  int mid = low + (high - low) / 2;

  int leftMax = maxSubarraySum(arr, low, mid);
  int rightMax = maxSubarraySum(arr, mid + 1, high);
  int crossMax = maxCrossingSum(arr, low, mid, high);

  return max({leftMax, rightMax, crossMax});
}

int main() {
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter " << n << " elements (can include negative numbers): ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int max_sum = maxSubarraySum(arr, 0, n - 1);

  cout << "Maximum Subarray Sum: " << max_sum << "\n";
  return 0;
}