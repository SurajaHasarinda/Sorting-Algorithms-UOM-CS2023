#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

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

    // Implement Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int min_index = i; // Assume the first element (i) is the minimum initially
        for (int j = i + 1; j < n; j++) {
            // Find the index (j) of the minimum element among the unsorted elements
            if (numbers[min_index] > numbers[j]) {
                min_index = j;
            }
        }
        // Swap the minimum element with the first element of the unsorted subarray
        if (min_index != i) { // Only swap if a smaller element is found
            swap(numbers[i], numbers[min_index]);
        }
    }

    // Print the sorted numbers
    for (int i : numbers) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
