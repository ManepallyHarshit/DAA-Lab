#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cout << "Enter the number of elements: ";
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Enter Kth element: ";
  cin >> k;

  if (k < 1 || k > n) {
    cout << "Invalid K value!" << endl;
    return 1;
  }

  std::nth_element(arr.begin(), arr.begin() + (k - 1), arr.end());
  cout << "The " << k << "th smallest element is: " << arr[k - 1] << endl;

  return 0;
}