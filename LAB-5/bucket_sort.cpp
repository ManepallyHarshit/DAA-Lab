#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

void bucket_sort(vector<int> &a) {
  auto result_pair = minmax_element(a.begin(), a.end());
  int min = *result_pair.first;
  int max = *result_pair.second;
  if (min == max) {
    return;
  }

  vector<vector<int>> b(a.size());
  for(int i = 0; i < a.size(); i++){
    int bucket_index = ((a[i] - min) * (a.size() - 1)) / (max - min);
    b[bucket_index].push_back(a[i]);
  }

  a.clear();
  for(int i = 0; i < b.size(); i++){
    sort(b[i].begin(), b[i].end());
    a.insert(a.end(), b[i].begin(), b[i].end());
  }
}

int main() {
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;
  vector<int> a(n);
  cout << "Enter elements of array: ";
  for (int &num : a) cin >> num;
  bucket_sort(a);
  for(auto n: a) cout << n << ' ';
  return 0;
}
