#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector<int> manacher(string& s){
    int n = s.size();
    int l = 0, r = 0;
    vector<int> p(n, 1);

    for(int i = 1; i < n; i++){
        if(i <= r){
            p[i] = min(r - i + 1, p[l + r - i]);
        }
        while(i - p[i] >= 0 && i + p[i] < n && s[i + p[i]] == s[i - p[i]]){
            p[i]++;
        }
        if(r < p[i] + i - 1){
            l = i - (p[i] - 1);
            r = i + (p[i] - 1);
        }
    }
    return p;
}

int main() {
	string s;
	cin >> s;

	string t = "#";
	for(char c : s) {
		t += c;
		t += "#";
	}

	vector<int> p = manacher(t);

	int i = max_element(begin(p), end(p)) - begin(p);
	cout << p[i] - 1 << '\n';

	int pocetak_t = i - p[i] + 1;
	int pocetak_s = pocetak_t / 2;
	cout << s.substr(pocetak_s, p[i] - 1) << '\n';

	return 0;
}