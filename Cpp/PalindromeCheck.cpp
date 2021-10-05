//C++ program to check whether the given string is a palindrome

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A function to check if a string str is palindrome
void isPalindrome(string str)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int f = str.size() - 1;

    // Keep comparing characters while they are same
    while (f > l)
    {
        if (str[l++] != str[f--])
        {
            cout << "Entered string is not a Palindrome.";
            return;
        }
    }
    cout << "Entered string is a palindrome.";
}

// Driver program
int main()
{
    string str;
    cout << "Enter any string: ";
    cin >> str;
    isPalindrome(str);
    return 0;
}