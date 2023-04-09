// Write a program to print all the subsequences of the given string
// i/p - "123"
// o/p - 1 2 3 12 13 23 123

#include<iostream>
using namespace std;

void subsequence(string original, string currentStr, int idx){
    // BASE CASE
    // if current index becomes equal to size of string
    if(idx >= original.size()){
        cout << currentStr << " ";
        return;
    }else{
        // For each letter we have two choice eighter to choose it or not
        // That's how we will be printing subsequences.

        // First we take the letter
        currentStr += original[idx];
        subsequence(original, currentStr, idx + 1);

        // Now the case, where we don't take this letter so we must first remove it.
        currentStr = currentStr.substr(0, currentStr.size() - 1);
        subsequence(original, currentStr, idx + 1);
    }
}

int main(){
    string s;
    cout << "Enter the string : ";
    cin >> s;
    subsequence(s, "", 0);
    return 0;
}