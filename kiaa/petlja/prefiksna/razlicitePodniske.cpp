#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node{
    bool end;
    map<char, Node*> edge;
};

int counter = 1;

void dodaj(Node* root, string& s){
    for(char c : s){
        if(root->edge.find(c) == root->edge.end()){
            root->edge[c] = new Node();
            counter++;
        }
        root = root->edge[c];
    }
    root->end = true;
}

void oslobodi(Node* root){
    for(auto it : root->edge){
        oslobodi(it.second);
    }
    delete(root);
}

int main(){

    string s;
    cin >> s;

    Node* root = new Node();

    for(int i = 0; i < s.length(); i++){
        string tmp = s.substr(i, s.length());
        dodaj(root, tmp);
    }

    cout << counter << '\n';

    return 0;
}