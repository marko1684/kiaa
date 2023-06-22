#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void bfs(int root, vector<bool>& posecen, vector<vector<int>>& graf, vector<int>& kompoenente, int counter){
    queue<int> q;
    posecen[root] = true;
    q.push(root);
    kompoenente[root] = counter;

    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(auto x : graf[t]){
            if(!posecen[x]){
                posecen[x] = true;
                q.push(x);
                kompoenente[x] = counter;
            }
        }
    }
    
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graf(n);

    while(m--){
        int x, y;
        cin >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
    int counter = 1;
    vector<int> komponente(n);
    vector<bool> posecen(n);

    for(int i = 0; i < n; i++){
        if(!posecen[i]){
            bfs(i, posecen, graf, komponente, counter);
            counter++;
        }
    }

    for(auto x : komponente){
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
