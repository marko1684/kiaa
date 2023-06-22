#include <iostream>
#include <vector>

using namespace std;

bool dfs(int a, int b, vector<bool>& posecen,vector<vector<int>>& graf){
    if(a == b){
        return true;
    }
    if(posecen[a])
        return false;

    posecen[a] = true;
    
    for(int x : graf[a]){
        if(dfs(x, b, posecen, graf))
            return true;
    }
    return false;
}

bool proveri(int a, int b, vector<vector<int>>& graf, int n){
    vector<bool> posecen(n);
    return dfs(a, b, posecen, graf);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> graf(n);
    int m;
    cin >> m;

    while(m--){
        int a, b;
        cin >> a >> b;
        graf[--a].push_back(--b);
    }

    cin >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        cout << (proveri(--a, --b, graf, n) ? "da" : "ne") << '\n';
    }

    return 0;
}