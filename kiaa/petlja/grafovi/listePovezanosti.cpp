#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graf(n);

    while(m--){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    
    for(auto x : graf){
        for (int y : x){
            cout << y << ' ';
        }
        cout << '\n';
    }
}