#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

struct edge{
    int node;
    int weight;
};

int minVisinaDfs(int a, int h, vector<vector<edge>>& graf){
    int minVisina = h;
    for(auto e : graf[a]){
        int v = minVisinaDfs(e.node, h + e.weight, graf);
            if(v < minVisina){
                minVisina = v;
            }
    }
    return minVisina;
}


int main(){
    
    int trenutnaNadmorska;
    cin >> trenutnaNadmorska;

    int n;
    cin >> n;

    vector<vector<edge>> graf(n);

    for(int i = 1; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edge *tmp = new edge();
        tmp -> weight = w;
        tmp -> node = b;
        graf[a].push_back(*tmp);
    }
    cout << minVisinaDfs(0, trenutnaNadmorska, graf) << '\n';
    return 0;
}