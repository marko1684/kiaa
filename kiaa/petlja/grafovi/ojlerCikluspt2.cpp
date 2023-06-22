#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

vector<int> ojler(vector<vector<int>>& graf){
    stack<int> stek;
    deque<int> ciklus;

    stek.push(0);

    while(!stek.empty()){
        int u = stek.top();
        if(graf[u].empty()){
            stek.pop();
            ciklus.push_front(u);
            continue;
        }
        stek.push(graf[u].back());
        graf[u].pop_back();
    }

    return vector<int>(ciklus.begin(), ciklus.end());
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<int> > graf(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graf[u].push_back(v);
	}

	vector<int> tour = ojler(graf);
	
	for(int u : tour)
		cout << u << ' ';
	cout << '\n';

	return 0;
}