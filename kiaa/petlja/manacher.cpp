#include <iostream>
#include <vector>  
#include <string>
#include <algorithm>

using namespace std;

vector<int> manacher(string& s){
    int n = s.size();
    vector<int> p(n, 1);
    int l = 0, r = 0;

    for(int i = 1; i < n; i++){
        if(i <= r){
            p[i] = min(p[l + r - i], r - i + 1);
        }
        while(i - p[i] >= 0 && i + p[i] < n && s[i - p[i]] == s[i + p[i]]){
            p[i]++;
        }
        if(r < i + p[i] - 1){
            r = i + (p[i] - 1);
            l = i - (p[i] - 1);
        }
    }
    return p;
}

int main(){
    string s;
	cin >> s;

	string t = "#";
	for(char c : s) {
		t += c;
		t += "#";
	}

	vector<int> p = manacher(t);

    cout << t << '\n';
    for(int x : p){
        cout << x << ' ';
    }
    cout << '\n';

	int i = max_element(begin(p), end(p)) - begin(p);
	cout << p[i] - 1 << '\n';

	int pocetak_t = i - p[i] + 1;
	int pocetak_s = pocetak_t / 2;
	cout << s.substr(pocetak_s, p[i] - 1) << '\n';

	return 0;
    return 0;
}