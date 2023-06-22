#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void napraviStablo(vector<int>& stablo, int k){
    int n = stablo.size();

    for(int i = k - 1; i > 0; i--){
        stablo[i] = stablo[2 * i] + stablo[2 * i + 1];
    }
}

void update(int i, int k, vector<int>& stablo, int n){
    i += n;
    for(i; i > 0; i/=2){
        stablo[i] += k;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    n = pow(2, ceil(log2(n)));

    vector<int> stablo(2 * n);
    copy(arr.begin(), arr.end(), stablo.begin() + n);
    napraviStablo(stablo, n);



    return 0;
}