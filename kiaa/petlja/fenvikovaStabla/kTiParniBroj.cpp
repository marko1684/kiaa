#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int upit(int i, vector<int>& stablo){
    int suma = 0;
    for(i++; i > 0; i -= i & -i){
        suma += stablo[i];
    }
    return suma;
}

int sumaSegmenta(int l, int r, vector<int>& stablo){
    return upit(r, stablo) - upit(l - 1, stablo);
}

void uvecaj(int i, int x, vector<int>& stablo){
    for(i++; i < stablo.size(); i+= i & -i){
        stablo[i] += x;
    }
}

void dodaj(int i, int x, vector<int>& stablo){
    int y = x - upit(i, stablo);
    uvecaj(i, y, stablo);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> stablo(n + 1);

    //stablo ce da cuva 1 gde je parni broj, odnosno sabirace 
    // jedinice tako da ako je br 3 upisan, u stablu se nalazi
    // 3. po redu paran broj
    dodaj(0, 1, stablo);
    int m;
    cin >> m;
    while(m--){
        char c;
        cin >> c;
        if(c == 'u'){
            int a, b;
            cin >> a >> b;
            int tmp = arr[a - 1];
            arr[a - 1] = b;
            if(tmp % 2 != 0 && arr[a - 1] % 2 == 0){
                uvecaj(a, 1, stablo);
            }
            if(tmp % 2 == 0 && arr[a - 1] % 2 != 0){
                uvecaj(a, -1, stablo);
            }
        }
        else{
            int k;
            cin >> k;
            auto it = lower_bound(stablo.begin(), stablo.end(), k);
            if(it == stablo.end()){
                cout << '-' << '\n';
            }else{
                cout << arr[it - stablo.begin()] << '\n';
            }
        }
        for(auto x : stablo){
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}