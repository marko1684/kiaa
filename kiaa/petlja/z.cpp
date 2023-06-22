#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> zNiz(string& s){
    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;

    for(int i = 1; i < n; i++){
        if(i <= r){
            z[i] = min(z[i - l], r - i + 1);
        }
        while(z[i] + i < n && s[z[i] + i] == s[z[i]]){
            z[i]++;
        }
        if(r < z[i] + i - 1){
            r = z[i] + i - 1;
            l = i;
        }
    }

    return z;
}

int main(){

    

    return 0;
}