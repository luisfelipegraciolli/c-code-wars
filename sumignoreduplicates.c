#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 100 // Adjust this based on your needs

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct HashSet {
    Node* table[HASH_SIZE];
} HashSet;

HashSet* createHashSet() {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    for (int i = 0; i < HASH_SIZE; i++) {
        set->table[i] = NULL;
    }
    return set;
}

int hash(int key) {
    return key % HASH_SIZE;
}

void insert(HashSet* set, int key) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = set->table[index];
    set->table[index] = newNode;
}

int contains(HashSet* set, int key) {
    int index = hash(key);
    Node* current = set->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int sum_no_duplicates(int* nums, int numsSize) {
    HashSet* seen = createHashSet();
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (!contains(seen, nums[i])) {
            sum += nums[i];
            insert(seen, nums[i]);
        }
    }

    // Clean up the hash set
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* current = seen->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(seen);

    return sum;
}

int main() {
    int nums[] = {3, 4, 3, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = sum_no_duplicates(nums, numsSize);
    printf("Sum of unique elements: %d\n", result);
    return 0;
}
