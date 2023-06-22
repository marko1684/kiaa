#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int root, vector<vector<int>>& graf, vector<pair<int, int>>& noviGraf){
    vector<bool> posecen(graf.size());
    posecen[root] = true;
    queue<int> q;
    q.push(root);
    int tmp = root;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        
        for(int v : graf[t]){
            if(!posecen[v]){
                posecen[v] = true;
                q.push(v);
                noviGraf.push_back(make_pair(t, v));
            }
        }
    }
}

int main(){

    int n;
    cin >> n;
    vector<vector<int>> graf(n);

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    
    int root;
    cin >> root;

    vector<bool> posecen(n);
    vector<pair<int,int>> noviGraf;

    bfs(root, graf, noviGraf);
    sort(noviGraf.begin(), noviGraf.end());

    for(auto x : noviGraf){
        cout << x.first << ' ' << x.second << '\n';
    }

    return 0;
}