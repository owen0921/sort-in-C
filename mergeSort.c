#include <stdio.h>

// �X�֨�Ӥl�}�C
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    // �N��Ӥl�}�C�����������Ӷ��ǦX�֨��l�}�C��
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // �N�Ѿl�������q���l�}�C���X�֨��l�}�C��
    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    // �N�Ѿl�������q�k�l�}�C���X�֨��l�}�C��
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

// �X�ֱƧǨ��
void mergeSort(int arr[], int size) {
    if (size < 2) {
        return;  // �򥻱��p�G�}�C�u���@�Ӥ����ά���
    }

    int mid = size / 2;

    // �Ыإ��l�}�C
    int left[mid];
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    // �Ыإk�l�}�C
    int right[size - mid];
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // ���k�a�索�k�l�}�C�i��X�ֱƧ�
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // �X�֥��k�l�}�C
    merge(arr, left, mid, right, size - mid);
}

// ���յ{���X
int main() {
    int arr[] = {1,4,16,7,8,100,90,50};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("��l�}�C�G");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, size);

    printf("\n�Ƨǫ�}�C�G");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

