#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;

using edge = pair<double, double>;

vector<edge> prim(vector<vector<edge>>& graf){
    double n = graf.size();

    vector<edge> grana(n,{-1, numeric_limits<double>::max()});
    vector<double> dodat(n, false);
    set<pair<double, double>> pq;

    pq.insert({0, 0});

    while(!pq.empty()){
        double v = pq.begin()->second;
        pq.erase(pq.begin());
        dodat[v] = true;

        for(auto e : graf[v]){
            double w = e.first, duzina = e.second;
            if(!dodat[w] && duzina < grana[w].second){
                pq.erase({grana[w].second, w});
                grana[w] = {v, duzina};
                pq.insert({grana[w].second, w});
            }
        }        
    }
    return grana;
}

int main() {
	double n, m;
	cin >> n >> m;
    
	vector< vector<edge> > graf(n);
	for(double i = 0; i < m; i++) {
		double u, v;
        double w;
		cin >> u >> v >> w;
		graf[u].push_back({v, w});
	    graf[v].push_back({u, w});
	}

	vector<edge> stablo = prim(graf);

	double mst = 0;
	for(double u = 0; u < n; u++) {
		//cout << u << ' ' << stablo[u].first << '\n';
		if(stablo[u].first != -1)
			mst += stablo[u].second;
	}

	cout << setprecision(1)<< fixed << mst << '\n';

	return 0;
}