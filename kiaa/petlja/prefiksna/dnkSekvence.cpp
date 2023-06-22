#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Cvor{
    bool endOfWord;
    map<char, Cvor*> edge;
};

void dodaj(string& s, Cvor* root){
    for(char c : s){
        if(root->edge.find(c) == root->edge.end()){
            root->edge[c] = new Cvor();
        }
        root = root->edge[c];
    }
    root->endOfWord = true;
}

bool nadji(string& s, Cvor* root){
    for(char c : s){
        if(root->edge.find(c) == root->edge.end()){
            return false;
        }
        root = root->edge[c];
    }
    return root->endOfWord;
}

void obrisi(string& s, Cvor* root){
    for(char c : s){
        if(root->edge.find(c) == root->edge.end()){
            return;
        }
        root = root -> edge[c];
    }
    root -> endOfWord = false;
}

int main(){

    int n;
    cin >> n;
    Cvor* root = new Cvor();

    while(n--){
        string upit, s;
        cin >> upit >> s;
        if(upit == "ubaci"){
            dodaj(s, root);
        }
        else if(upit == "izbaci"){
            obrisi(s, root);
        }
        else{
            if(nadji(s, root)){
                cout << "da" << '\n';
            }
            else{
                cout << "ne" << '\n';
            }
        }
    }

    return 0;
}