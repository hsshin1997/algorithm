#include <iostream>
using namespace std;

void merge(int *arr, const int start, const int mid, const int end) {
    // left array index
    int i = start;
    // right array index
    int j = mid;

    // temp variable to swap
    int temp;

    while (i < mid && j < end) {
        if (arr[i] < arr[j]) {
            i++;
        } else if (arr[i] > arr[j]) {
            temp = arr[i];
            arr[i] = arr[j]; 
            arr[j] = temp;

        }
    }

}

void merge_sort(int *arr, const int start, const int end) {
    // check for termination
    if (start >= end)
        return;

    // find middle index
    int mid = start + (end - start)/2;

    // sort left
    merge_sort(arr, start, mid-1);

    // sort right
    merge_sort(arr, mid, end);

    // merge array in order
    merge(arr, start, mid, end); 
}

int main() {
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(int);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    } 
    cout << endl;
    cout << "Sorted array: " << endl;
}