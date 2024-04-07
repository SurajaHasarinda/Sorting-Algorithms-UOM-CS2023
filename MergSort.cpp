#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Merge function for merging two sorted subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    // Size of the left subarray
    int n1 = mid - left + 1;
    // Size of the right subarray
    int n2 = right - mid;

    // Create temporary arrays to hold left and right subarrays
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    // Copy elements from the original array to temporary subarrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left; // Indices for leftArr, rightArr, and original array
    while (i < n1 && j < n2) {
        // Compare elements and copy the smaller element to the original array
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++; // Move to the next position in the original array
    }

    // Copy remaining elements from leftArr (if any)
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements from rightArr (if any)
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Merge Sort function for recursively dividing and sorting
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point of the subarray
        int mid = left + (right - left) / 2;

        // Recursively sort the left and right subarrays
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted subarrays
        merge(arr, left, mid, right);
    }
}

int main() {
    string inputLine;
    cout << "Enter a line of integers separated by spaces: ";
    getline(cin, inputLine);

    vector<int> numbers;
    int num;

    stringstream ss(inputLine);
    while (ss >> num) {
        numbers.push_back(num);
    }
    int n = numbers.size();

    // Call mergeSort to sort the entire array
    mergeSort(numbers, 0, n - 1);

    // Print the sorted numbers
    for (int i : numbers) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
