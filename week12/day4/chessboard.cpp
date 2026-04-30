// problem: chessboard:

// solution:

#include <iostream>
#include <string>

std::string determineColor(const std::string &s)
{
    int ch = s[0] - '0';
    int num = std::stoi(s.substr(1, s.length()));

    if (ch % 2 == 0)
    {
        if (num % 2 == 0)
        {
            return "Black";
        }
        else
        {
            return "White";
        }
    }
    else
    {
        if (num % 2 == 0)
        {
            return "White";
        }
        else
        {
            return "Black";
        }
    }
}

int main()
{
    std::string s;
    std::cin >> s;
    std::string result = determineColor(s);
    std::cout << result << std::endl;
    return 0;
}

// First, I observed that on a chessboard, the columns are represented by letters (a to h).
// If I convert these letters into numbers (using ASCII or by subtracting '0'), I can treat them as numeric values and check whether they are odd or even.

// 8
// 7
// 6
// 5
// 4
// 3
// 2
// 1
//   a b c d e f g h
//   0 1 2 3 4 5 6 7

// So we can see that each column can be treated as a number.

// Now:

// If the converted character (column) is odd:

// If the row number is odd → Black
// If the row number is even → White

// If the converted character (column) is even:

// If the row number is odd → White
// If the row number is even → Black