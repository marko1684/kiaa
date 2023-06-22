#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> zNiz(string& s){
    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;

    for(int i = 1; i < n; i++){
        if(i <= r){
            z[i] = min(z[i - l], r - i + 1);
        }
        while(i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;    
        if(r < i + z[i] - 1){
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;

}


vector<int> manacher(string& s){
    int n = s.size();
    int l = 0, r = 0;
    vector<int> p(n, 1);

    for(int i = 1; i < n; i++){
        if(i <= r){
            p[i] = min(p[l + r - i], r - i + 1);
        }
        while(i + p[i] < n && i - p[i] >= 0 && p[i + p[i]] == p[i - p[i]])
            p[i]++;
        if(r < i + p[i] - 1){
            r = i + (p[i] - 1);
            l = i - (p[i] - 1);
        }
    }

    return p;
}