#include <iostream>

using namespace std;
void merge(int a[], int p, int q, int r){
  int i = p, j = q + 1, b[r - p + 1], k = 0;

  while(i <= q && j <= r){
    if(a[i] <= a[j]){
      b[k++] = a[i++];
    } else {
      b[k++] = a[j++];
    }
  }

  while(i <= q){
    b[k++] = a[i++];
  }

  while(j <= r){
    b[k++] = a[j++];
  }

  for (int idx = p, t = 0; idx <= r; idx++, t++) {
    a[idx] = b[t];
  }
}

void merge_sort(int a[], int low, int high){
  if(low < high){
    int mid = (low + high) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}

int main(){
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;
  int a[n];
  cout << "Enter elements of array: ";
  for(int &n: a) cin >> n;
  merge_sort(a, 0, n - 1);
  cout << "The sorted array: ";
  for(auto n: a) cout << n << ' ';
  return 0;
}