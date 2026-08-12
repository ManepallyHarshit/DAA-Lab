#include <stdio.h>

int main() {
  int n, key, flag = 0;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the values of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the value whose index you want to find in the array: ");
  scanf("%d", &key);
  int beg = 0, end = n - 1;
  int mid = 0;

  while (beg <= end) {
    mid = (beg + end) / 2;
    if (key == arr[mid]) {
      flag = 1;
      break;
    } else if (key < arr[mid]) {
      end = mid - 1;
    } else {
      beg = mid + 1;
    }
  }

  if (flag) {
    printf("The index of the element is %d.\n", mid);
  } else {
    printf("The element is not in the array.\n");
  }

  return 0;
}
