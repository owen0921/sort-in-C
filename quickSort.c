#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#define MAX 7
#define SWAP(x,y) {int t; t = x; x = y; y = t;} 

void quickSort(int[], int, int); 

int main(void) { 
    
    int arr[MAX] = {5,13,31,46,25,18,13,52};    
	int i = 0;
    quickSort(arr, 0, MAX-1); 

    printf("\n排序後："); 
    for(i = 0; i < MAX; i++) 
        printf("%d ", arr[i]); 
    
    printf("\n"); 

    return 0; 
} 

void quickSort(int arr[], int left, int right) { 
    if(left < right) { 
        int pivot = arr[left]; 
        int i = left - 1; 
        int j = right + 1; 

        while(1) { 
            while(arr[++i] < pivot) ;  // 向右找 
            while(arr[--j] > pivot) ;  // 向左找 
            if(i >= j) 
                break; 
            SWAP(arr[i], arr[j]); 
        } 

        quickSort(arr, left, i-1);   // 對左邊進行遞迴 
        quickSort(arr, j+1, right);  // 對右邊進行遞迴 
    } 
} 

