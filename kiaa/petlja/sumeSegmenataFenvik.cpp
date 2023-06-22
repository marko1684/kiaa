#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void kreirajStablo(vector<int>& arr, int& n){
    for(int i = 1; i < n; i++){
        if(i + (i & -i) < n){
            arr[i + (i & -i)] += arr[i];
        }
    }
}

int upit(int i, vector<int>& stablo){
    int sum = 0;
    i++;
    for(i; i > 0; i -= i & -i){
        sum += stablo[i];
    }
    return sum;
}

int upit(int a, int b, vector<int>& stablo){
    return upit(b, stablo) - upit(a - 1, stablo);
}

void uvecaj(int i, int x, vector<int>& stablo){
    i++;
    for(i; i < stablo.size(); i += (i & -i)){
        stablo[i] += x;
    }
}

void postavi(int i, int x, vector<int>& stablo){
    uvecaj(i, (x - upit(i, i, stablo)), stablo);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    n++;
    vector<int> arr(n);
    for(int i = 1; i < n; i++){
        cin >> arr[i];
    }

    kreirajStablo(arr, n);

    int m;
    cin >> m;
    while(m--){
        char c;
        int a, b;
        cin >> c >> a >> b;
        if(c == 'z'){
            cout << upit(a, b, arr) << '\n';
        }
        else{
            postavi(a, b, arr);
        }
    }
    return 0;
}