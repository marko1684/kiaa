#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <cmath>

using namespace std;

struct Node{
    map<char, Node*> edge;
};

void dodaj(Node* root, string& s){
    for(char c : s){
        if(root->edge.find(c) == root->edge.end()){
            root->edge[c] = new Node();
        }
        root = root->edge[c];
    }
}

string maxBin(Node* root, string num){
    string tmp = "";
    int x;
    for(char c : num){
        if(c == '1'){
            if(root->edge.find('0') != root->edge.end()){
                tmp = tmp + "1";
                x = 0;
                root = root->edge['0'];
                continue;
            }
            else{
                tmp = tmp + "0";
                x = 1;
                root = root->edge['1'];
                continue;
            }
        }
        else if(c == '0'){
            if(root->edge.find('1') != root->edge.end()){
                tmp = tmp + "1";
                x = 1;
                root = root->edge['1'];
                continue;
            }
            else{
                tmp = tmp + "0";
                x = 0;
                root = root->edge['0'];
                continue;
            }
        }
    }
    return tmp;
}

int main(){
    int n;
    cin >> n;

    Node* root = new Node();
    string maxNum = "0";
    string maxFin = "0";
    unsigned long long x;
    cin >> x;
    string binary = bitset<60>(x).to_string();
    dodaj(root, binary);
    n--;
    while(n--){
        cin >> x;
        binary = bitset<60>(x).to_string();
        maxNum = maxBin(root, binary);
        if(maxNum > maxFin){
            maxFin = maxNum;
        }
        dodaj(root, binary);
    }


    cout << bitset<60>(maxFin).to_ullong() << '\n';
}