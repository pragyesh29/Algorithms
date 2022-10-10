#include<iostream>
using namespace std;

void subsequence(string s, string t, int idx){
    // Base case
    if(idx >= s.size()){
        cout << t << " ";
        return;
    }else{
        // For each letter we have two choice eighter to choose it or not
        // That's how we will be printing subsequences.
        // First we take the letter
        t += s[idx];
        subsequence(s, t, idx + 1);
        // Now the case, where we don't take this letter so we must remove it.
        t = t.substr(0, t.size() - 1);
        subsequence(s, t, idx + 1);
    }
}

int main(){
    string s = "Pragyesh";
    subsequence(s, "", 0);
    return 0;
}