#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void selectionSort(int arr[], int size){
	int i = 0;
	int j = 0;
	
	for(i = 0; i < size - 1; i++){
		int min = i;
		for(j = i + 1; j < size; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		if(i != min){
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

int main(void){
	int arr[] = {1,4,16,7,8,100,90,50};
  	int size = sizeof(arr) / sizeof(arr[0]);
  	selectionSort(arr, size);
  	printf("Sorted array in ascending order:\n");
  	printArray(arr, size);
  	return 0;
}
