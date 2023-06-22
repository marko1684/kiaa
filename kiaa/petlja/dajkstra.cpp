#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

using edge = pair<int, int>; // *sused* *weight*

void dajkstra(int root, vector<vector<edge>>& graf, vector<edge>& _tezine){

    int n = graf.size();
    set<pair<int, int>> pq; // tezina, sused
    pq.insert({0, root}); // zbog sortiranja *tezine*, *sused*

    vector<edge> tezine(n, {-1, numeric_limits<int>::max()});
    tezine[root].second = 0;

    while(!pq.empty()){
        int u = pq.begin()->second;
        pq.erase(pq.begin());
        for(edge e : graf[u]){
            int sused = e.first; int tezina = e.second;
            if(tezine[u].second + tezina < tezine[sused].second){
                pq.erase({tezine[sused].second, sused});
                tezine[sused].second = tezine[u].second + tezina;
                tezine[sused].first = u;
                pq.insert({tezine[sused].second, sused});
            }
        }
    }   
    _tezine = tezine;
}

vector<int> putanja(vector<edge>& tezine, int b){
    vector<int> put;
    while(b != -1){
        put.push_back(b);
        b = tezine[b].first;
    }
    return put;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<edge>> graf(n);

    int m;
    cin >> m;
    while(m--){
        int a, b;
        int w;
        cin >> a >> b >> w;
        graf[a].push_back({b, w});
    }

    int x, y;
    cin >> x >> y;
    vector<edge> tezine(n);
    dajkstra(x, graf, tezine);

    cout << setprecision(5) << fixed << tezine[y].second << '\n';

    vector<int> put = putanja(tezine, y);
    
    for(int i = 0 ; i < n; i++){
        cout << i << ' ' << tezine[i].first << ' ' << tezine[i].second << '\n';
    }

    for(auto it = put.rbegin(); it != put.rend(); it++){
        cout << *it << ' ';
    }

    cout << '\n';

    return 0;
}
