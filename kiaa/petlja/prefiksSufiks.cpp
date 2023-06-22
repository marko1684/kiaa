#include <iostream>
#include <vector>
#include <string>

using namespace std; 

vector<int> zNiz(string& s){
    int n = s.size();
}

int main(){
    string s1;
    string s2;
    cin >> s1 >> s2; 
    string s = s2 + "#" + s1;
    vector<int> z = zNiz(s);

    int i;
    for(i = s2.size(); i < z.size(); i++){
        if(z[i] == s2.size()){
            break;
        }
    }
    if(i < z.size()){
        cout << i - s2.size() - 1 << '\n';
    }
    else{
        cout << -1 << '\n';
    }
    

    return 0;
}

 