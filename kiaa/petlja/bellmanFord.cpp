#include <iostream>
#include <vector>
#include <limits>

using namespace std;

using edge = pair<int, int>; // sused tezina

vector<int> bellman_ford(int u, vector<vector<edge>>& graf){
    int n = graf.size();
    vector<int> d(n, numeric_limits<int>::max());   
    d[u] = 0;

    for(int i = 0; i < n - 1; i++){
        for (int v = 0; v < n; v++){
            if(d[v] < numeric_limits<int>::max()){
                for(edge e : graf[v]){
                    d[e.first] = min(d[e.first], d[v] + e.second);
                }
            }
        }
    }
    return d;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<edge> > graf(n);
	for(int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graf[a].push_back({b, c});
	}

	vector<int> D = bellman_ford(0, graf);
	for(int i = 0; i < n; i++)
		cout << D[i] << ' ';
	cout << '\n';
}