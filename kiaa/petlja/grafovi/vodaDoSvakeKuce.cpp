#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

using edge = pair<int, int>; // sused, tezina

int prim(vector<vector<edge>>& graf){
    int n = graf.size();
    vector<edge> stablo(n, {-1, numeric_limits<int>::max()}); // sused, tezina
    vector<bool> dodat(n);

    set<pair <int, int>> pq; // tezina, sused

    pq.insert({0, 0});
    while(!pq.empty()){
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        dodat[u] = true;
        for(edge e : graf[u]){
            int sused = e.first;
            int tezina = e.second;
            if(!dodat[sused] && tezina < stablo[sused].second){
                pq.erase({stablo[sused].second, sused});
                stablo[sused] = {u, tezina};
                pq.insert({stablo[sused].second, sused});
            }
        }
    }
    int sum = 0;
    for(int i = 0; i < stablo.size(); i++){
        if(stablo[i].first != -1){
            sum += stablo[i].second;
        }
    }
    return sum;
}

int main(){
    int n;
    cin >> n;

    vector<vector<edge>> graf(n + 1);

    vector<edge> ceneBunara(n);

    for(int i = 0; i < n; i++){
        int c; cin >> c;
        graf[n].push_back({i, c});
        graf[i].push_back({n, c});
    }
    int a, b, w;
    while(cin >> a){
        cin >> b >> w;
        a--; b--;
        graf[a].push_back({b, w});
        graf[b].push_back({a, w});
    }
    // int minimum = numeric_limits<int>::max();
    // int k = n;
    // for(int i = 0; i < n; i++){
    //     vector<vector<edge>> tmpGraf = graf;
    //     for(int j = i; j < n; j++){
    //         tmpGraf.push_back({{j, ceneBunara[j]}});
    //     }
    //     int tmpMin = prim(tmpGraf);
    //     if(tmpMin < minimum){
    //         minimum = tmpMin;
    //     }
    // }

    cout << prim(graf) << '\n';

    return 0;
}

