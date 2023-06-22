#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    
    for(int i = 1; i < n + 1; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int m;
    cin >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        cout << arr[b + 1] - arr[a] << '\n';
    }

    return 0;
}