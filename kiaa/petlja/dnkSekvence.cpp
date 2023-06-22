#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node{
    bool end;
    map<char, Node*> edge;
};

void ubaci(Node* root, string& s){
    for(char c : s){
        if(root->edge.find(c) == root->edge.end()){
            root->edge[c] = new Node();
        }
        root = root->edge[c];
    }
    root->end = true;
}

void izbaci(Node* root, string& s){
    for(char c : s){
        if(root->edge.find(c) == root->edge.end()){
            return;
        }
        root = root->edge[c];
    }
    if(root->end){
        root->end = false;
    }
}

bool trazi(Node* root, string& s){
    for(char c : s){
        if(root->edge.find(c) == root->edge.end()){
            return false;
        }
        root = root->edge[c];
    }
    if(root->end){
        return true;
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Node* root = new Node();

    while(n--){
        string upit, s;
        cin >> upit >> s;
        if(upit == "ubaci"){
            ubaci(root, s);
        }
        else if(upit == "izbaci"){
            izbaci(root, s);
        }
        else{
            cout << (trazi(root, s) ? "da" : "ne") << '\n';
        }
    }

    return 0;
}