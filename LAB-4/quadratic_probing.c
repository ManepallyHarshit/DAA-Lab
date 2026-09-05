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

void searchUsingHash(int key, int *hash) {
    int index = hashFunction(key);
    int pos = index, i = 0;
    while (hash[pos] != -1 && i < SIZE) {
        if (hash[pos] == key) {
            printf("%d is found\n", key);
            return;
        }
        i++;
        pos = (index + i * i) % SIZE;
    }
    printf("%d is not found\n", key);
}

void display(int *hash) {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, hash[i]);
    }
}

int main() {
    int hash[SIZE];
    for (int i = 0; i < SIZE; i++) {
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