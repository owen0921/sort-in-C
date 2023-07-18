#include <stdio.h>

// 合併兩個子陣列
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    // 將兩個子陣列中的元素按照順序合併到原始陣列中
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // 將剩餘的元素從左子陣列中合併到原始陣列中
    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    // 將剩餘的元素從右子陣列中合併到原始陣列中
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

// 合併排序函數
void mergeSort(int arr[], int size) {
    if (size < 2) {
        return;  // 基本情況：陣列只有一個元素或為空
    }

    int mid = size / 2;

    // 創建左子陣列
    int left[mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    // 創建右子陣列
    int right[size - mid];
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // 遞歸地對左右子陣列進行合併排序
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // 合併左右子陣列
    merge(arr, left, mid, right, size - mid);
}

// 測試程式碼
int main() {
    int arr[] = {1,4,16,7,8,100,90,50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("原始陣列：");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, size);

    printf("\n排序後陣列：");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

