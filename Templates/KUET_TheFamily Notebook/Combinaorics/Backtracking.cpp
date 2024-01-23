#include <iostream>
#include <string>

using namespace std;

// Function to swap characters at positions i and j in a string
void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

// Function to generate all permutations of a string using backtracking
void generatePermutations(string &str, int start, int end) {
    if (start == end) {
        // If start index reaches the end, a permutation is found
        cout << str << endl;
        return;
    }

    // Iterate over each character in the remaining portion of the string
    for (int i = start; i <= end; i++) {
        // Swap the current character with the first character in the remaining portion
        swap(str[start], str[i]);

        // Recursively generate permutations for the remaining portion
        generatePermutations(str, start + 1, end);

        // Undo the swap to backtrack and explore other possibilities
        swap(str[start], str[i]);
    }
}

int main() {
    string input;
    
    // Get the input string
    cout << "Enter a string: ";
    cin >> input;

    int n = input.length();

    // Generate and print all permutations of the input string
    cout << "All permutations:" << endl;
    generatePermutations(input, 0, n - 1);

    return 0;
}
