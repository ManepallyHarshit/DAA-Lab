#include <stdio.h>

#define SIZE 7

int hashFunction(int key) {
    if (key < 0)
        key = -key;
    return key % SIZE;
}

void insert(int key, int *hash) {
    int index = hashFunction(key);
    int pos = index, i = 0;
    while (hash[pos] != -1) {
        i++;
        if (i == SIZE) {
            printf("Hash table is full, cannot insert %d\n", key);
            return;
        }
        pos = (index + i * i) % SIZE;
    }
    hash[pos] = key;
}

int searchUsingHash(int key, int *hash) {
    int index = hashFunction(key);
    int pos = index, i = 0;
    while (hash[pos] != -1 && i < SIZE) {
        if (hash[pos] == key) {
            return pos;
        }
        i++;
        pos = (index + i * i) % SIZE;
    }
    return -1;
}

int main() {
    int hash[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hash[i] = -1;
    }

    int n, target;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the target sum:\n");
    scanf("%d", &target);

    int arr[n];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        int diff = target - arr[i];
        int x = searchUsingHash(diff, hash);
        if (x != -1) {
            printf("Pair exists: (%d, %d) with sum %d\n", arr[i], diff, target);
        } else {
            insert(arr[i], hash);
        }
    }

    return 0;
}