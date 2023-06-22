#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> ojler(vector<vector<int>>& graf){
    stack<int> stek;
    deque<int> ciklus;

    stek.push(0);

    while(!stek.empty()){
        int u = stek.top();
        if(graf[u].empty()){
            ciklus.push_front(u);
            stek.pop();
            continue;
        }
        stek.push(graf[u].back());
        graf[u].pop_back();
    }

    return vector<int>(ciklus.begin(), ciklus.end());
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graf(n);

    while(m--){
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
    }

    vector<int> ciklus = ojler(graf);

    for(auto a : ciklus){
        cout << a << ' ';
    }
    cout << '\n';

    return 0;  
}