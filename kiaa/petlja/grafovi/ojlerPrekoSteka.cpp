#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>

using namespace std;

vector<int> ojler(vector<vector<int>>& graf){
    deque<int> ciklus;
    stack<int> s;

    s.push(0);

    while(!s.empty()){
        int u = s.top();

        if(graf[u].empty()){
            ciklus.push_front(u);
            s.pop();
            continue;
        }
        s.push(graf[u].back());
        graf[u].pop_back();
    }
    return vector<int>(ciklus.begin(), ciklus.end());
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graf(n);
    while(m--){
        int a , b;
        cin >> a >> b;
        graf[a].push_back(b);
    }

    vector<int> ciklus = ojler(graf);

    for(auto x : ciklus){
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}