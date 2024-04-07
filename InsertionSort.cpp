#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    // Declare a string to store the user input line
    string inputLine;

    cout << "Enter a line of integers separated by spaces: ";

    // Get the entire line of input from the user
    getline(cin, inputLine);

    // Create a vector to store the extracted integers
    vector<int> numbers;

    // Declare an integer variable to hold the current number
    int num;

    // Create a stringstream object to parse the input line
    stringstream ss(inputLine);

    // Extract integers from the stringstream one by one
    // and add them to the numbers vector
    while (ss >> num) {
        numbers.push_back(num);
    }

    // Get the size of the numbers vector
    int n = numbers.size();

    // Implement insertion sort algorithm
    for (int i = 1; i < n; i++) {
        // Consider the current element (`numbers[i]`) as the key
        int current = numbers[i];
        // Initialize the index for the sorted part (`j`) to the element before the current
        int j = i - 1;

        // Shift elements of the sorted part greater than the current element one position back
        // until a position is found where the current element is greater than or equal to the element at the previous index
        while (j >= 0 && numbers[j] > current) {
            numbers[j + 1] = numbers[j];
            j--;
        }

        // Insert the current element at the correct position (one position after the last element greater than it)
        numbers[j + 1] = current;
    }

    // Print the sorted numbers
    cout << "Sorted numbers: ";
    for (int i : numbers) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
