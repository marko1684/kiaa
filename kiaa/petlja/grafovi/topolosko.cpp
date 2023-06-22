#include <iostream>
#include <vector>

using namespace std;

vector<int> topolosko(vector<vector<int>>& graf, vector<int>& indeg){
    int n = graf.size();
    vector<int> sortirano;

    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            sortirano.push_back(i);
        }
    }

    for(int i = 0; i < sortirano.size(); i++){
        int u = sortirano[i];
        for(int x : graf[u]){
            indeg[x]--;
            if(indeg[x] == 0){
                sortirano.push_back(x);
            }
        }
    }
    return sortirano;
}

int main(){

    int n;
    cin >> n;

    vector<vector<int>> graf(n);

    int m;
    cin >> m;

    vector<int> indeg(n);

    while(m--){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        indeg[b]++;
    }

    vector<int> topSort = topolosko(graf, indeg);

    if(topSort.size() < n){
        cout << "ciklus" << '\n';
    }
    else
        for(int x : topSort){
            cout << x << ' ';
        }
    cout << '\n';

}