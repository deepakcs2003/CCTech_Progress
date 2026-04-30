#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    unordered_map<string, int> map;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        map[arr[i]]++;
    }

    int k;
    cin >> k;

    for (int i = 0; i < n; i++) {
        if (map[arr[i]] == 1) {
            k--;
        }
        if (k == 0) {
            cout << arr[i] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}


//approach
// First, I observed that we are given N strings, and some strings can be repeated.

// We need to find the kth unique string.
// Unique means → the string appears only one time.

// Now the problem is: how to know which string appears how many times?

// For that, I used a map (or frequency array):

// map[string] → stores how many times that string appears

// Example:

// 6
// d
// b
// c
// b
// c
// a

// So frequency will be:

// d → 1
// b → 2
// c → 2
// a → 1

// Now we need to find unique strings (frequency = 1)
// and also maintain the same order as input.

// So I traverse the array again:

// If a string has frequency == 1 → it is unique
// For every unique string, I decrease k

// Step-by-step:

// First unique string → k--
// Second unique string → k--
// When k == 0 → that is our answer

// Example:

// Unique strings in order: d, a
// k = 2
// d → k = 1
// a → k = 0 ✅ → answer = a

// If we finish the loop and k never becomes 0,
// that means there are less than k unique strings

// So return -1