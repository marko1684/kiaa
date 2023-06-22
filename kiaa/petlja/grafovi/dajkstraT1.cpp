#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>
#include <set>

using namespace std;

using edge = pair<int, int>;

vector<int> dajkstra(int start, vector<vector<edge>>& graf, vector<int>& prethodnik){
    
    vector<int> d(graf.size(), numeric_limits<int>::max());
    d[start] = 0;
    prethodnik[start] = -1;
    set<edge> pq;
    pq.insert({0, start});

    while(!pq.empty()){
        int u = pq.begin() -> second;
        pq.erase(pq.begin());
        for(edge e : graf[u]){
            int sused = e.first; int duzina = e.second;
            if(duzina + d[u] < d[sused]){
                pq.erase({duzina, sused});
                prethodnik[sused] = u;
                d[sused] = d[u] + duzina;
                pq.insert({d[sused], sused});
            }
        }
    }
    return d;
}

vector<int> put(int b, vector<int>& prethodnik){
    vector<int> p;
    while(b != -1){
        p.push_back(b);
        b = prethodnik[b];
    }
    reverse(p.begin(), p.end());
    return p;
}

int main(){
    int n, m;
    cin >> n >> m;

    int a; int b; int w;
    vector<vector<edge>> graf(n);
    while(m--){
        cin >> a >> b >> w;
        graf[a].push_back({b, w});
    }

    int x, y;
    cin >> x >> y;
    vector<int> prethodnik(n);
    vector<int> duzina = dajkstra(x, graf, prethodnik);

    vector<int> putAB = put(y, prethodnik);

    cout << duzina[y] << '\n';
    for(int k : putAB){
        cout << k << ' ';
    }
    cout << '\n';

    return 0;
}