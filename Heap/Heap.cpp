#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        int larger = i;
        if (2 * i + 1 < size && arr[2 * i + 1] > arr[larger]) {
            larger = 2 * i + 1;
        }
        if (2 * i + 2 < size && arr[2 * i + 2] > arr[larger]) {
            larger = 2 * i + 2;
        }
        if (larger != i) swap(arr[larger], arr[i]);
    }
    swap(arr[0], arr[size - 1]);
    return;
}

void sort(int arr[], int size) {
    // Number of iterations
    for (int i = 0; i < size; ++i) {
        heapify(arr, size - i);
    }
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int arr[size];
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    sort(arr, size);
    //sort (arr,arr+size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
