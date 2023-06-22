#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int nSvetova;
    cin >> nSvetova;

    while(nSvetova--){
        int n, m;
        cin >> n >> m;
        vector<int> sortirani;
        vector<int> indeg(n);
        vector<vector<int>> graf(n);
        while(m--){
            int x, y;
            cin >> x >> y;
            graf[x].push_back(y);
            indeg[y]++;
        }

        for(int i = 0; i < n; i++){
            if(indeg[i] == 0){
                sortirani.push_back(i);
            }
        }

        for(int i = 0; i < sortirani.size(); i++){
            int u = sortirani[i];
            for(int n : graf[u]){
                indeg[n]--;
                if(indeg[n] == 0){
                    sortirani.push_back(n);
                }
            }
        }
        if(sortirani.size() != n){
            cout << "da" << '\n';
        }
        else{
            cout << "ne" << '\n';
        }
    }

    return 0;
}