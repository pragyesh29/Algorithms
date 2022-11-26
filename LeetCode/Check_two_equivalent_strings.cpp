#include<iostream>
#include<vector>
using namespace std;

bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2){
    int word_1_count = 0, word_2_count = 0, char_1_word = 0, char_2_word = 0;
    while(true){
        // if corresponding characters in each string are not equal return false.
        if(word1[word_1_count][char_1_word] != word2[word_2_count][char_2_word]) return false;
        // increment the current counter of both arrays of string
        char_1_word++; char_2_word++;
        // if counter of first array of string goes out of bounds then go to next word
        if(char_1_word >= word1.size()){
            char_1_word = 0;
            word_1_count++;
        }
        // if counter of second array of string goes out of bounds then go to next word
        if(char_2_word >= word2.size()){
            char_2_word = 0;
            word_2_count++;
        }
        // if both ,counter are equal to corresponding array's size i.e. last element of aaray then it means both are representing same string
        if((word_1_count == word1.size()) and (word_2_count == word2.size())) return true;
        if((word_1_count == word1.size()) or (word_2_count == word2.size())) return false; 
    }
}

int main(){
    vector<string> word1{"abc", "d", "defg"};
    vector<string> word2{"abcdef"};
    if(arrayStringsAreEqual(word1, word2)) cout << "true";
    else cout << "false";
    return 0;
}