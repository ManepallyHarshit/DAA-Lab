#include <stdio.h>

int main(){
  int n, key, i;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[n];
  printf("EEnter the values of the array: ");
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  printf("EEnter the value whose index you want to find in the array: ");
  scanf("%d", &key);
  for(i = 0; i < n; i++){
    if(key == arr[i]){
      printf("THe index of the value in the array is %d", i);
      return 0;
    }
  }
  printf("THe elem is not in the array.");
  return 0;
}