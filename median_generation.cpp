#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

// Function to sort a vector of numbers using bubble sort
vector<double> sort(const vector<double>& numbers) {
    vector<double> sortedNumbers = numbers;
    int n = sortedNumbers.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (sortedNumbers[j] > sortedNumbers[j + 1]) {
                swap(sortedNumbers[j], sortedNumbers[j + 1]);
            }
        }
    }
    return sortedNumbers;
}

// Function to sort and find the median of a vector of numbers
double sortAndFindMedian(vector<double> numbers) {
    numbers = sort(numbers);
    int n = numbers.size();
    if (n == 0) {
        throw runtime_error("Cannot find median of an empty list.");
    }
    if (n % 2 == 0) {
        return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    } else {
        return numbers[n / 2];
    }
}

// Function to run predefined test cases
void runPredefinedTestCases() {
    cout << "Running Predefined Test Cases:\n\n";

    vector<pair<string, vector<double>>> testCases = {
        {"Empty List", {}},
        {"Single Element", {42}},
        {"Two Elements", {7, 3}},
        {"Odd Number of Elements", {7, 1, 3, 9, 5}},
        {"Even Number of Elements", {10, 3, 5, 7}},
        {"Negative Numbers", {-3, -1, -7, -5}},
        {"Mixed Positive and Negative", {7, -3, 5, -1}},
        {"Already Sorted", {1, 2, 3, 4, 5}},
        {"Reverse Sorted", {9, 8, 7, 6, 5}},
        {"Large Dataset", vector<double>(1000)}
    };

    // Populate the large dataset
    for (int i = 0; i < 1000; ++i) {
        testCases.back().second[i] = 1000 - i;
    }

    for (const auto& testCase : testCases) {
        const string& caseName = testCase.first;
        const vector<double>& numbers = testCase.second;
        cout << "Case: " << caseName << "\nInput: ";
        for (double num : numbers) {
            cout << num << " ";
        }
        cout << endl;

        try {
            double result = sortAndFindMedian(numbers);
            cout << "Median: " << result << "\n\n";
        } catch (const exception& e) {
            cout << "Error: " << e.what() << "\n\n";
        }
    }
}

// Function to run custom input from the user
void runCustomInput() {
    cout << "Custom Input:\n";
    cout << "Enter a list of numbers separated by spaces: ";
    string inputLine;
    getline(cin, inputLine);

    stringstream ss(inputLine);
    vector<double> numbers;
    double num;

    while (ss >> num) {
        numbers.push_back(num);
    }

    try {
        double result = sortAndFindMedian(numbers);
        cout << "Median: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Main function to prompt user for choice and execute accordingly
int main() {
    cout << "Choose an option:\n";
    cout << "1. Run Predefined Test Cases\n";
    cout << "2. Provide Custom Input\n";

    int choice;
    cin >> choice;
    cin.ignore(); // To handle the newline character after integer input

    try {
        if (choice == 1) {
            runPredefinedTestCases();
        } else if (choice == 2) {
            runCustomInput();
        } else {
            cout << "Invalid choice! Please enter 1 or 2.\n";
        }
    } catch (const exception& e) {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}
