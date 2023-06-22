#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void ojler(int u, deque<int>& ciklus, vector<vector<int>>& graf){
    while(!graf[u].empty()){
        int sused = graf[u].back();
        graf[u].pop_back();
        ojler(sused, ciklus, graf);
    }
    ciklus.push_front(u);
}