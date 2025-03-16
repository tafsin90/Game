#include <stdio.h>

int main() {
    int size, position;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size]={10,20,30,40,50,60};

    printf("Enter the position to delete: ");
    scanf("%d", &position);

    if (position < 1 || position > size) {
        printf("Invalid position!\n");
        return 0;
    }

    for (int i = position - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
