#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <limits>

using namespace std;

using edge = pair<int, int>; // sused, tezina

vector<edge> prim(vector<vector<edge>>& graf){
    int n = graf.size();
    vector<edge> stablo(n,{-1, numeric_limits<int>::max()}); // stablo koje vracamo
    vector<bool> dodat(n); // da li je vec cvor dodat u stablo
    set<pair<int, int>> red; // tezina, sused

    red.insert({0, 0});

    while(!red.empty()){
        int u = red.begin()->second;
        red.erase(red.begin());
        dodat[u] = true;

        for(edge e : graf[u]){
            int sused = e.first;
            int duzina = e.second;
            if(!dodat[sused] && duzina < stablo[sused].second){
                red.erase({stablo[sused].second, sused});
                stablo[sused] = {u, duzina};
                red.insert({stablo[sused].second, sused});
            }
        }
    }
    return stablo;
} 


int main(){
    int n, m;
    cin >> n;
    vector<vector<edge>> graf(n);
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graf[a].push_back({b, w});
        graf[b].push_back({a, w});
    }

    vector<edge> stablo = prim(graf);

    int mst = 0;

    for(int i = 0; i < n; i++){
        cout << i << ' ' << stablo[i].first << ' ' << stablo[i].second << '\n';
        if(stablo[i].first != -1){
            mst += stablo[i].second;
        }
    }

    cout << mst << '\n';
    return 0;
}