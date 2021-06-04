#include <iostream>

using namespace std;

const int ARRAY_SIZE = 10;

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    // i is the index of the smaller number
    int i = left - 1;

    // j keeps track of current number that we are examining
    for(int j = left; j <= right - 1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
        // all nums up to i are < pivot
        // all nums up to j are >= pivot
    }
    // make sure pivot is in between two groups
    swap(&arr[i + 1], &arr[right]);
    // return index of the pivot
    return (i + 1);
}

// arr[] is the array of numbers being sorted
// left is the starting index for array
// right is the ending index for array
void quickSort(int arr[], int left, int right) {
    // already in right place
    if(left >= right) {
        return;
    }

    // beginning partition index
    int p = partition(arr, left, right);

    // sort sections of array after partition
    // left / lower side of array
    quickSort(arr, left, p - 1);
    // right / upper side of array
    quickSort(arr, p + 1, right);

}

void bubbleSort(int arr[]) {
    // number of passes
    bool swapped = false;
    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        // comparison loop
        swapped = false;
        for(int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        // elements not swapped by comparison loop
        if(swapped == false) {
            break;
        }
    }
}

void selectionSort(int arr[]) {
    int minIndex = 0;
    // pass through array
    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        minIndex = i;
        // find minValue
        for(int j = i+1; j < ARRAY_SIZE; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // swap value at minIndex and i
        swap(&arr[i], &arr[minIndex]);
    }
}

void insertionSort(int arr[]) {
    for(int i = 1; i < ARRAY_SIZE; i++) {
        int j = i;
        // move elements greater to position ahead of current position
        while(j > 0 && arr[j] < arr[j-1]) {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
}

void displayArr(int (&nums)[ARRAY_SIZE]) {
    for(auto& i : nums) {
        cout << i << ' ';
    }
}

int main() {
    int nums[ARRAY_SIZE] = {5, 10, 46, -5, 0, 324, 98, 234, 17, 26};
    quickSort(nums, 0, ARRAY_SIZE - 1);
    displayArr(nums);

    return 0;
}