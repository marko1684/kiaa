#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node{
    bool endOfWord;
    map<char, Node*> edge;
};

void dodaj(string& s, Node* root, bool& ispravno){
    for(char c : s){
        if(root->edge.find(c) == root->edge.end()){
            root->edge[c] = new Node();
        }
        else{
            if(c == s.back()){
                ispravno = false;
                return;
            }
        }
        if(root->endOfWord == true){
            ispravno = false;
            return;
        }

        root = root->edge[c];
    }
    root->endOfWord = true;
}

void oslobodi(Node* root){
    for(auto podstablo : root->edge)
		oslobodi(podstablo.second);
	delete root;
}


int main(){

    bool ispravno = true;

    Node* root = new Node();

    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(ispravno)
            dodaj(s, root, ispravno);
    }
    if(ispravno)
        cout << "da\n";
    else   
        cout << "ne\n";
    oslobodi(root);

    return 0;
}