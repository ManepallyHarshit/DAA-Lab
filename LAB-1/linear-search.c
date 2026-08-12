#include <stdio.h>

int main() {
  int n, key, i;

  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter the values of the array: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Enter the value whose index you want to find in the array: ");
  scanf("%d", &key);
  for (i = 0; i < n; i++) {
    if (key == arr[i]) {
      printf("The index of the value in the array is %d.\n", i);
      return 0;
    }
  }

  printf("The element is not in the array.\n");
  return 0;
}
