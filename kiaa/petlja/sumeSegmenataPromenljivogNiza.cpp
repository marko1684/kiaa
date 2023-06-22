    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <cmath>

    using namespace std;

    void kreirajDrvo(vector<int>& arr, int& n, vector<int>& stablo){
        copy(arr.begin(), arr.end(), stablo.begin() + n);

        for(int k = n - 1; k > 0; k--){
            stablo[k] = stablo[k * 2] + stablo[k * 2 + 1];
        }
    }

    void dodaj(int i, int x, vector<int>& stablo, int n){
        stablo[i += n] = x;
        for(i /= 2; i > 0; i /= 2){
            stablo[i] = stablo[2 * i] + stablo[2 * i + 1];
        }
    }

    int upit(int l, int r, vector<int>& stablo, int n){
        int sum = 0;
        for(l+=n, r+=n; l <= r; l /= 2, r /= 2){
            if(l % 2 == 1) sum += stablo[l];
            l++;
            if(r % 2 == 0) sum += stablo[r];
            r--;
        }
        return sum;
    }

    int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        vector<int> stablo(2 * n);

        kreirajDrvo(arr, n, stablo);

        int m; cin >> m;
        while(m--){
            char c;
            int a, b;
            cin >> c >> a >> b;
            if(c == 'z'){
                cout << upit(a, b, stablo, n) << '\n';
            }
            else{   
                dodaj(a, b, stablo, n);
            }
        }

        return 0;
    }