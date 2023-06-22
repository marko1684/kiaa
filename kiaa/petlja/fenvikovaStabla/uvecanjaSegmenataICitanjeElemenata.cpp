#include <iostream>
#include <vector>
#include <string>

using namespace std;

int elementValue(int i, vector<int>& stablo){
    int suma = 0;
    for(i++; i > 0; i -= i & -i){
        suma += stablo[i];
    }
    return suma;
}

int rangeSum(int l, int r, vector<int>& stablo){
    return elementValue(r, stablo) - elementValue(l - 1, stablo);
}

void updateTree(int i, int newValue, vector<int>& stablo){
    //int valDiff = newValue - elementValue(i, stablo);
    for(i++; i < stablo.size(); i += i & -i){
        stablo[i] += newValue;
    } 
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> stablo(n + 1);

    int q;
    cin >> q;

    while(q--){
        char c;
        cin >> c;
        if(c == 'u'){
            int index1, index2, value;
            cin >> index1 >> index2 >> value;
            updateTree(index1, value, stablo);
            updateTree(index2 + 1, -value, stablo);
        }
        else{
            int index;
            cin >> index;
            cout << elementValue(index, stablo) << '\n';
        }
    }

    return 0;
}