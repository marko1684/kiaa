#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>

using namespace std;

using edge = pair<int,int>; // sused tezina

vector<edge> prim(int start, vector<vector<edge>>& graf){
    int n = graf.size();
    vector<edge> stablo(n, {-1, numeric_limits<int>::max()});
    vector<bool> obidjen(n);
    set<pair<int, int>> pq; // tezina, sused

    pq.insert({0, start});
    while(!pq.empty()){
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        obidjen[u] = true;

        for(edge e : graf[u]){
            int sused = e.first; int tezina = e.second;
            if(!obidjen[sused] && stablo[sused].second > tezina){
                pq.erase({stablo[sused].second, sused});
                stablo[sused] = {u, tezina};
                pq.insert({tezina, sused});
            }
        }
    }

    return stablo;
}

vector<edge> dajkstra(int start, vector<vector<edge>>& graf){
    int n = graf.size();

    set<pair<int,int>> pq;

    vector<edge> tezine(n, {-1, numeric_limits<int>::max()});
    tezine[start] = {-1, 0};
    
    pq.insert({0, start});

    while(!pq.empty()){
        int u = pq.begin() -> second;
        pq.erase(pq.begin());
        for(edge e : graf[u]){
            int sused = e.first; int tezina = e.second;
            if(tezine[sused].second > tezine[u].second + tezina){
                pq.erase({tezine[sused].second, sused});
                tezine[sused]={u, tezine[u].second + tezina};
                pq.insert({tezine[sused].second, sused});
            }
        }
    }
    return tezine;
}