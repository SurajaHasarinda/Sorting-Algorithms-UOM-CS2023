#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Partition function for Quick Sort
int partition(vector<int>& arr, int lb, int ub) {
    // Choose the first element (`arr[lb]`) as the pivot
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    // Partitioning loop
    while (start < end) {
        // Move `start` index forward while elements are less than or equal to the pivot
        while (arr[start] <= pivot && start < end) {
            start++;
        }
        // Move `end` index backward while elements are greater than the pivot
        while (arr[end] > pivot) {
            end--;
        }

        // If `start` and `end` haven't crossed, swap elements at those indices
        if (start < end) {
            swap(arr[start], arr[end]);
        }
    }

    // Swap the pivot element with the element at the `end` index (now the correct partition position)
    swap(arr[lb], arr[end]);

    // Return the final position of the pivot element
    return end;
}

// Quick Sort function for recursive partitioning
void quickSort(vector<int>& arr, int lb, int ub) {
    if (lb >= ub) {
        // Base case: Subarray with one or zero elements is already sorted
        return;
    }

    // Partition the subarray and get the final position of the pivot element
    int p = partition(arr, lb, ub);

    // Recursively sort the subarrays before and after the partition
    quickSort(arr, lb, p - 1); // Sort the left subarray
    quickSort(arr, p + 1, ub); // Sort the right subarray
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

    // Call quickSort to sort the entire vector
    quickSort(numbers, 0, n - 1);

    // Print the sorted numbers
    for (int i : numbers) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
