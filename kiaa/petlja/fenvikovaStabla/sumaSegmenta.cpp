#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void napraviStablo(vector<int>& arr, vector<int>& stablo){
    copy(arr.begin(), arr.end(), stablo.begin() + 1);

    for(int i = 1; i < stablo.size(); i++){
        if(i + (i & -i) < stablo.size()){
            stablo[i + (i & -i)] += stablo[i];
        }
    }
}

int upit(int i, vector<int>& stablo){
    int suma = 0;
    for(i++; i > 0; i -= i & -i)
        suma += stablo[i];
    return suma;
}

int upit(int l, int r, vector<int>& stablo){
    return upit(r, stablo) - upit(l - 1, stablo);
}

void postavi(int i, int x, vector<int>& stablo){
    int y = x - upit(i, i, stablo);
    for(i++; i < stablo.size(); i += i & -i)
        stablo[i] += y;
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

    vector<int> stablo(n + 1);
    napraviStablo(arr, stablo);


    int m;
    cin >> m;
    while(m--){
        char c; int a, b;
        cin >> c >> a >> b;
        if(c == 'z'){
            cout << upit(a, b, stablo) << '\n';
        }
        else{
            postavi(a, b, stablo);
        }
    }

    return 0;
}