#include <bits/stdc++.h>
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

// Iterative Quick Sort function
void quickSort_Iterative(vector<int>& arr, int lb, int ub) {
    // Stack to store subarray start and end indices for processing
    int stack[ub - lb + 1]; // Size of the stack can be optimized to `log(n)` in worst case

    // Stack top index (initially -1)
    int top = -1;

    // Push the entire subarray onto the stack
    stack[++top] = lb;
    stack[++top] = ub;

    // Loop continues until the stack becomes empty (all subarrays processed)
    while (top >= 0) {
        // Pop the subarray right and left bounds from the stack
        ub = stack[top--];
        lb = stack[top--];

        // Partition the subarray and get the pivot's final position
        int p = partition(arr, lb, ub);

        // Check if there's a right subarray (elements greater than pivot)
        if (p + 1 < ub) {
            // Push the right subarray (p+1, ub) onto the stack
            stack[++top] = p + 1;
            stack[++top] = ub;
        }

        // Check if there's a left subarray (elements less than pivot)
        if (p - 1 > lb) {
            // Push the left subarray (lb, p-1) onto the stack
            stack[++top] = lb;
            stack[++top] = p - 1;
        }
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
    // Sort the vector using iterative Quick Sort
    quickSort_Iterative(numbers, 0, n - 1);

    // Print the sorted numbers
    for (int i : numbers) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
