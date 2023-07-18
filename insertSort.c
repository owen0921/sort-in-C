// Insertion sort in C
#include <stdio.h>

// Function to print an array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertionSort(int arr[], int size) {
	int i = 0;
	int j = 0;
  	for (i = 1; i < size; i++) {
    int key = arr[i];
    int j = i - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

int main(void) {
  int arr[] = {1,4,16,7,8,100,90,50};
  int size = sizeof(arr) / sizeof(arr[0]);
  insertionSort(arr, size);
  printf("Sorted array in ascending order:\n");
  printArray(arr, size);
  return 0;
}
