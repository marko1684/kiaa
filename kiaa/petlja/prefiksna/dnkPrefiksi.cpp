#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Node{
    bool endOfSequence;
    map<char, Node*> edge;
    int hasChar = 0;
};

void dodaj(string& s, Node* root){
    for(char c : s){
        if(root->edge.find(c) == root->edge.end()){
            root->edge[c] = new Node;
        }
        root = root->edge[c];
        root->hasChar++;
        //cout << root->hasChar << " sta " << "\n";
    }
    root->endOfSequence = true;
    cout << root->hasChar - 1<< '\n';
}

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    Node* root = new Node();

    string s;
    while(cin >> s){
        dodaj(s, root);
    }
    return 0;
}