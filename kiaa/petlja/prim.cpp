#include <vector>
#include <set>
#include <iostream>
#include <limits>

using namespace std;

using edge = pair<int, int>; // tezina, sused

vector<edge> prim(int start, vector<vector<edge>>& graf){
    int n = graf.size();
    vector<edge> stablo(n,{-1, numeric_limits<int>::max()});
    vector<bool> posecen(n);
    
    set<pair<int, int>> pq;
    pq.insert({0, start});

    while(!pq.empty()){
        int v = pq.begin()->second;
        pq.erase(pq.begin());

        posecen[v] = true;
            for(edge e: graf[v]){
                int sused = e.first; int tezina = e.second;
                if(!posecen[sused] && tezina < stablo[sused].second){
                    pq.erase({stablo[sused].second, sused});
                    stablo[sused] = {v, tezina};
                    pq.insert({tezina, sused});
                }
        }
    }
    return stablo;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<edge>> graf(n);

    int m;
    cin >> m;
    int a, b;
    double w;
    while(m--){
        cin >> a >> b >> w;
        graf[a].push_back({b, (int)w});
        graf[b].push_back({a, (int)w});
    }

    vector<edge> stablo = prim(0, graf);

    int suma = 0;

    for(int i = 0; i < stablo.size(); i++){
        if(stablo[i].first != -1)
            suma += stablo[i].second;
    }

    cout << suma << '\n';
    return 0;
}