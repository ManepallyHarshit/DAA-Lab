#include <stdio.h>

int hashFunction(int key) {
    if (key < 0)
        key = -key;
    return key % 7;
}

void insert(int key, int *hash) {
    int index = hashFunction(key);
    while (hash[index] != -1) {
        index = (index + 1) % 7;
    }
    hash[index] = key;
}

void searchUsingHash(int key, int *hash) {
    int index = hashFunction(key);
    int count = 0;
    while (hash[index] != -1 && count < 7) {
        if (hash[index] == key) {
            printf("%d is found\n", key);
            return;
        }
        index = (index + 1) % 7;
        count++;
    }
    printf("%d is not found\n", key);
}

void display(int *hash) {
    for (int i = 0; i < 7; i++) {
        printf("Index %d: %d\n", i, hash[i]);
    }
}

int main() {
    int hash[7];
    for (int i = 0; i < 7; i++) {
        hash[i] = -1;
    }

    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insert(arr[i], hash);
    }

    display(hash);

    int key;
    printf("Enter the key to find:\n");
    scanf("%d", &key);
    searchUsingHash(key, hash);

    return 0;
}