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

    // Implement a bubble sort algorithm to sort the numbers in ascending order
    for (int i = 0; i < n - 1; i++) {
        // Outer loop for the number of passes
        for (int j = 0; j < n - 1 - i; j++) {
            // Inner loop for comparing adjacent elements
            // Swap elements if the current element is greater than the next
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // Print the sorted numbers
    cout << "Sorted numbers: ";
    for (int i : numbers) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
