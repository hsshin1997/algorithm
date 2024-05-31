#include <iostream>
using namespace std;

// utility function
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;
}

void merge(int *arr, const int start, const int mid, const int end) {
    // length of left and right array
    const int left = mid - start + 1;
    const int right = end - mid; 
    
    // copy values in original array to temp array 
    auto *left_array = new int[left], *right_array = new int[right];
    
    for (auto i = 0; i < left; i++){
        left_array[i] = arr[start + i];
    }
    for (auto j = 0; j < right; j++){
        right_array[j] = arr[mid + 1 + j];
    }

    // merge two array in ascending order
    int i = 0, j = 0, k = start;
    while (i < left && j < right) {
        if (left_array[i] <= right_array[j]) {
            arr[k] = left_array[i];
            i++;
        } else {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    // copy remaining elements
    while (i < left) {
        arr[k] = left_array[i];
        i++;
        k++;
    }
    while (j < right) {
        arr[k] = right_array[j];
        j++;
        k++;
    }

    // free left and right array
    delete[] left_array;
    delete[] right_array;
}

void merge_sort(int *arr, const int start, const int end) {
    // check for termination
    if (start >= end) {
        return;
    }

    // find middle index
    int mid = start + (end - start)/2;
    // sort left
    merge_sort(arr, start, mid);

    // sort right
    merge_sort(arr, mid + 1, end);

    // merge array in order
    merge(arr, start, mid, end); 
}


int main() {
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(int);

    cout << "Size of array: " << size << endl;
    cout << "Original array: ";
    print_array(arr, size);

    merge_sort(arr, 0, size - 1);
    cout << "Sorted array: ";
    print_array(arr, size);
}