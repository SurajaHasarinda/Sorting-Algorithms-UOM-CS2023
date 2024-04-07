#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Merge function for merging two sorted subarrays
vector<int> merge(vector<int> A, int L1, int R1, int L2, int R2) {
    // Create an empty temporary vector to store the merged elements
    vector<int> temp;
    int index = 0;

    // Merge loop to compare and add elements from subarrays to the temporary vector
    while (L1 <= R1 && L2 <= R2) {
        if (A[L1] <= A[L2]) {
            temp.push_back(A[L1]);
            index++;
            L1++;
        } else {
            temp.push_back(A[L2]);
            index++;
            L2++;
        }
    }

    // Copy remaining elements from the first subarray (if any)
    while (L1 <= R1) {
        temp.push_back(A[L1]);
        index++;
        L1++;
    }

    // Copy remaining elements from the second subarray (if any)
    while (L2 <= R2) {
        temp.push_back(A[L2]);
        index++;
        L2++;
    }

    return temp; // Return the merged vector
}

// Iterative Merge Sort function
vector<int> mergeSort_iteration(vector<int> A) {
    int n = A.size(); // Get the size of the input vector

    // Define the subarray length (len) starting from 1
    int len = 1;

    // Outer loop continues until subarray length becomes larger than the vector size
    while (len < n) {
        int i = 0; // Index for the starting element of the current subarray

        // Inner loop iterates through the entire vector with the defined subarray length
        while (i < n) {
            // Define left and right indices for the first and second subarrays
            int L1 = i;
            int R1 = i + len - 1;
            int L2 = i + len;
            int R2 = i + 2 * len - 1;

            // Handle cases where subarrays go beyond the vector boundary
            if (L2 >= n) {
                break; // If L2 is out of bounds, no second subarray exists, so move to the next subarray
            }

            if (R2 >= n) {
                R2 = n - 1; // If R2 is out of bounds, adjust it to the last element of the vector
            }

            // Call the merge function to merge the two subarrays and store the result in a temporary vector
            vector<int> temp = merge(A, L1, R1, L2, R2);

            // Copy the merged subarray back to the original vector starting from the current subarray
            for (int j = 0; j < R2 - L1 + 1; j++) {
                A[i + j] = temp[j];
            }

            // Move the starting index for the next subarray by twice the subarray length
            i = i + 2 * len;
        }

        // Double the subarray length for the next iteration
        len = 2 * len;
    }

    // Return the sorted vector A
    return A;
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

    numbers = mergeSort_iteration(numbers); // Sort the vector using iterative Merge Sort

    // Print the sorted numbers
    for (int i : numbers) {
        cout << i << " ";
    }

    return 0;
}
