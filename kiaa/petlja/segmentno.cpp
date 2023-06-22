#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



vector<int> napraviStablo(int n, vector<int>& arr){
    vector<int> stablo(2 * n);
    copy(arr.begin(), arr.end(), stablo.begin() + n);

    for(int i = n - 1; i > 0; i--){
        stablo[i] = stablo[2 * i] + stablo[2 * i + 1];
    }
}

int upit(int l, int d, vector<int>& stablo, int n){
    int suma = 0;

    for(l += n, d +=n; l <= d; l/=2, d/=2){
        if(l % 2 == 1){
            suma += stablo[l++];
        }
        if(d % 2 == 0){
            suma += stablo[d--];
        }
    }

    return suma;
}

int uvecaj(int i, int k, vector<int>& stablo, int n){
    stablo[i += n] += k;
    for(i/=2; i > 0; i/=2){
        stablo[i] = stablo[i * 2] + stablo[i * 2 + 1];
    }
}

int main(){

    return 0;
}