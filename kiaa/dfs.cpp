#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& graf, vector<bool>& cvorovi, int curr){
    cvorovi[curr] = true;
    for(auto x: graf[curr]){
        if(!cvorovi[x])
            dfs(graf, cvorovi, x);
    }
}



int main(){

    // n -> broj cvorova, m -> broj grana
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graf(n);

    while(m--){
        int x, y;
        cin >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }

    // for(auto x : graf){
    //     for(auto y : x){
    //         cout << y << ' ';
    //     }
    //     cout << '\n';
    // }

    vector<bool> cvorovi(n);

   dfs(graf, cvorovi, 3);

    for(int i = 0; i < cvorovi.size();i++){
        if(cvorovi[i]){
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}