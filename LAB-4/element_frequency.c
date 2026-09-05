#include <stdio.h>

#define SIZE 10

int hashFunction(int key) {
    if (key < 0) 
        key = -key;
    return key % SIZE;
}

void insertOrUpdate(int key, int *hash, int *freq) {
    int index = hashFunction(key);
    int pos = index, i = 0;
    while (hash[pos] != -1 && hash[pos] != key) {
        i++;
        if (i == SIZE) {
            printf("Hash table full, cannot insert %d\n", key);
            return;
        }
        pos = (index + i * i) % SIZE;
    }
    if (hash[pos] == -1) {
        hash[pos] = key;
        freq[pos] = 1;
    } else {
        freq[pos]++;
    }
}

void display(int *hash, int *freq) {
    for (int i = 0; i < SIZE; i++) {
        if (hash[i] != -1) {
            printf("Element %d occurs %d times\n", hash[i], freq[i]);
        }
    }
}

int main() {
    int hash[SIZE], freq[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hash[i] = -1;
        freq[i] = 0;
    }

    int n;
    printf("Enter number of elements:\n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insertOrUpdate(arr[i], hash, freq);
    }

    display(hash, freq);

    return 0;
}