#include <stdio.h>

int main() {
    int arr[7] = {1, 2, 3, 3, 5,3,6};
    int n;
    printf("Enter number you want to delete: ");
    scanf("%d", &n);
    
    int newSize = 7; // New size of the array after deletion
    for (int i = 0; i < newSize; i++) {
        if (arr[i] == n) {
            for (int j = i; j < newSize ; j++) {
                arr[j] = arr[j + 1];
            }
            newSize--; // Reducing the size of the array
            i--; // Check the same index again since it contains a new element now
        }
    }

    // Print the modified array
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
