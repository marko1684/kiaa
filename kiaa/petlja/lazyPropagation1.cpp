#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

struct cvor{
    int vrednost;
    int uvecanje;
};

int velicina(int n){
    return pow(2, ceil(log2(n)));
}

vector<cvor> napraviStablo(vector<int>& arr, int n){

    vector<cvor> stablo(2 * n);
    for(int i = 0; i < arr.size(); i++){
        stablo[i + n].vrednost = arr[i];
    }

    for(int i = n - 1; i > 0; i--){
        stablo[i].vrednost = stablo[i * 2].vrednost + stablo[i * 2 + 1].vrednost;
    }

    return stablo;
}

void propagiraj(int i, int tl, int td, vector<cvor>& stablo){
    stablo[i].vrednost += stablo[i].uvecanje * (td - tl + 1);
    if(tl < td){
        stablo[2 * i].uvecanje += stablo[i].uvecanje;
        stablo[2 * i + 1].uvecanje += stablo[i].uvecanje;
    }
    stablo[i].uvecanje = 0;
}

void uvecaj(int idx, int uvecanje, int tl, int td, int l, int d, vector<cvor>& stablo){

}