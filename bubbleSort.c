#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int size) {
  	for(int i = 0; i < size; i++) {
    	printf("%d ", arr[i]);
  	}
  	printf("\n");
}

void bubbleSort(int arr[], int size){
	int i = 0;
	int j = 0;
	
	for(i = 0; i < size - 1; i++){
		for(j = 0; j < size - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void){
	int arr[] = {1,4,16,7,8,100,90,50};
  	int size = sizeof(arr) / sizeof(arr[0]);
  	bubbleSort(arr, size);
  	printf("Sorted array in ascending order:\n");
  	printArray(arr, size);
  	return 0;
}
