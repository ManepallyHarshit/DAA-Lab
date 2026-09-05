#include <iostream>

using namespace std;
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      swap(arr[++i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return (i + 1);
}

void quick_sort(int a[], int low, int high){
  if(low < high){
    int p = partition(a, low, high);
    quick_sort(a, low, p - 1);
    quick_sort(a, p + 1, high);
  }
}

int main(){
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;
  int a[n];
  cout << "Enter elements of array: ";
  for(int &n: a) cin >> n;
  quick_sort(a, 0, n - 1);
  cout << "The sorted array: ";
  for(auto n: a) cout << n << ' ';
  return 0;
}