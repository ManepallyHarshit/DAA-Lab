#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {
  int min, max;
};

Pair getMinMax(const vector<int>& arr, int low, int high) {
  Pair result, leftResult, rightResult;

  if (low == high) {
    result.min = arr[low];
    result.max = arr[low];
    return result;
  }

  if (high == low + 1) {
    if (arr[low] < arr[high]) {
      result.min = arr[low];
      result.max = arr[high];
    } else {
      result.min = arr[high];
      result.max = arr[low];
    }
    return result;
  }

  int mid = low + (high - low) / 2;
  leftResult = getMinMax(arr, low, mid);
  rightResult = getMinMax(arr, mid + 1, high);

  result.min = min(leftResult.min, rightResult.min);
  result.max = max(leftResult.max, rightResult.max);

  return result;
}

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter " << n << " elements separated by spaces: ";
  for (int i = 0; i < n; i++) cin >> arr[i];

  Pair minmax = getMinMax(arr, 0, n - 1);

  cout << "Min: " << minmax.min << "\n";
  cout << "Max: " << minmax.max << "\n";
  return 0;
}