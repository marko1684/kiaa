#include <iostream>
#include <vector>

using namespace std;

bool dfs(int u, int c, vector<int>& col, vector< vector<int> >& g) {
	col[u] = c;
	for(int v : g[u])
		if(col[v] == c)
			return false;
		else if(col[v] == 0)
			if(!dfs(v, 3-c, col, g))
				return false;
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector< vector<int> > g(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int> col(n);
	bool bipartitan = dfs(0, 1, col, g);

	if(!bipartitan)
		cout << "Nije bipartitan\n";
	else {
		for(int c : col)
			cout << c << ' ';
		cout << '\n';
	}

	return 0;
}