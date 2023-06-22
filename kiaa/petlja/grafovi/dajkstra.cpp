// 4
// 6
// 0 1 1.2
// 1 2 1.3
// 0 2 2.0
// 0 3 5.7
// 1 3 4.6
// 2 3 2.1
// // 0
// 3

#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <tuple>
#include <algorithm>
#include <iomanip>

using namespace std;

using edge = pair<int, double>;

void dijkstra(int u, vector<double>& _udaljenost, vector<int>& _prethodnik, vector<vector<edge>>& graf){
    int n = graf.size();

    vector<double> udaljenost(n, numeric_limits<double>::max());
    vector<int> prethodnik(n, -1);
    set<pair<int, double>> pq;
    pq.insert({udaljenost[u] = 0, u});
    prethodnik[u] = -1;

    while(!pq.empty()){
        double v = pq.begin()->second;
        pq.erase(pq.begin());

        for (auto e : graf[v]){
            double w, duzina; tie(w, duzina) = e;
            if(udaljenost[v] + duzina < udaljenost[w]){
                pq.erase({udaljenost[w], w});
                udaljenost[w] = udaljenost[v] + duzina;
                prethodnik[w] = v;
                pq.insert({udaljenost[w], w});
            }
        }
    }
    _udaljenost = udaljenost;
    _prethodnik = prethodnik;
}

vector<int> put(int v, vector<int>& prethodnik){
    vector<int> p;
    while(v != -1){
        p.push_back(v);
        v =prethodnik[v];
    }
    reverse(p.begin(), p.end());
    return p;
}

int main(){
    int n, m;
    cin >> n >> m;

    int a; int b; double w;
    vector<vector<edge>> graf(n);
    while(m--){
        cin >> a >> b >> w;
        graf[a].push_back({b, w});
    }

    int x, y;
    cin >> x >> y;
    vector<double> duzina;
    vector<int> prethodnik;
    dijkstra(x, duzina, prethodnik, graf);

    cout <<  setprecision(5) << fixed << duzina[y] << '\n';

    vector<int> putRec = put(y, prethodnik);
    for(int k : putRec){
        cout << k << ' ';
    }
    cout << '\n';


    return 0;
}