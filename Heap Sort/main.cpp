#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int larger = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[larger]) {
        larger = left;
    }
    if (right < n && arr[right] > arr[larger]) {
        larger = right;
    }
    if (larger != i) {
        swap(arr[i], arr[larger]);
        heapify(arr, n, larger);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {4, 2, 3, 1, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, size);
    cout << "The sorted array is ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}