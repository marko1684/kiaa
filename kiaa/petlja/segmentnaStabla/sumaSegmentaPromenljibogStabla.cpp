#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void napraviStablo(vector<int>& arr, vector<int>& stablo, int n){
    copy(arr.begin(), arr.end(), stablo.begin() + n);

    for(int i = n - 1; i > 0; i--){
        stablo[i] = stablo[2 * i] + stablo[2 * i + 1];
    }
}

int upit(int l, int r, vector<int>& stablo, int n){
    int suma = 0;
    for(l += n, r+=n; l <= r; l/=2, r/=2){
        if(l % 2 == 1){
            suma += stablo[l++];
        }
        if(r % 2 == 0){
            suma += stablo[r--];
        }
    }
    return suma;
}

void postavi(int i, int x, vector<int>& stablo, int n){
    stablo[i += n] = x;
    for(i /= 2; i > 0; i /= 2){
        stablo[i] = stablo[2 * i] + stablo[2 * i + 1];
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> stablo(2 * n);
    napraviStablo(arr, stablo, n);



    int m;
    cin >> m;
    while(m--){
        char c; int a, b;
        cin >> c >> a >> b;
        if(c == 'z'){
            cout << upit(a, b, stablo, n) << '\n';
        }
        else{
            postavi(a, b, stablo, n);
        }
    }

    return 0;
}