#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> zNiz(string s){ 
    int n = s.size();
    vector<int> z(n);
}

int main(){ 

    string trazena, uzorak;
    cin >> trazena >> uzorak;

    string s = trazena + "#" + uzorak;
    vector<int> z = zNiz(s);

    for(int i = trazena.size() + 1; i < s.size(); i++){
        if(z[i] == trazena.size()){
            cout << i - (trazena.size() + 1) << '\n';
        }
    }

    return 0;
}
