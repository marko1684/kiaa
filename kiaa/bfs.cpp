#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graf, vector<bool>& cvorovi, int curr){
    // obilazak
    queue<int> q;
    cvorovi[curr] = true;
    q.push(curr);
    while(!q.empty()){
        int tmp = q.front();
        cout << tmp << ' ';
        for(auto node : graf[tmp]){
            if(!cvorovi[node]){
                cvorovi[node] = true;
                q.push(node);
            }
        }
        q.pop();
    }
    cout << '\n';
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

   bfs(graf, cvorovi, 0);

    for(int i = 0; i < cvorovi.size();i++){
        if(cvorovi[i]){
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}