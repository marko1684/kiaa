#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graf(n);
    vector<int> indeg(n);

    while(m--){
        int x, y;
        cin >> x >> y;
        graf[x].push_back(y);
        indeg[y]++;
    }

    for(auto it : indeg){
        cout << it << ' ';
    }
    cout << '\n';

    vector<int> sortirani;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            sortirani.push_back(i);
        }
    }

    for(int i = 0; i < sortirani.size(); i++){
        int u = sortirani[i];
        for(int v : graf[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                sortirani.push_back(v);
            }
        }
    }
    
    for(auto x : sortirani){
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}