#include <iostream>
#include <vector>
#include <string>

using namespace std;

string processString(string& s){
    string processed = "#";
    for(char c : s){
        processed += c;
        processed += "#";
    }
    return processed;
}


string longestPalindrome(string& s){

    string processed = processString(s);
    int n = processed.size();

    vector<int> palindromeLengths(n);
    int center = 0;
    int right = 0;

    for(int i = 1; i < n - 1; i++){
        int mirror = 2 * center - i;

        if(i < right)
            palindromeLengths[i] = min(right - i, palindromeLengths[mirror]);
        
        while(processed[i + (1 + palindromeLengths[i])] == processed[i - (1 + palindromeLengths[i])])
            palindromeLengths[i]++;

        if(i + palindromeLengths[i] > right){
            center = i;
            right = i + palindromeLengths[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;
    for(int i = 1; i < n - 1; i++){
        if(palindromeLengths[i] > maxLen){
            maxLen = palindromeLengths[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main(){

    string s;
    cin >> s;

    string longestPal = longestPalindrome(s);
    cout << longestPal << '\n';

    return 0;
}