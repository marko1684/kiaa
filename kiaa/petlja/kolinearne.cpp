#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using tacka = pair<int, int>;
using vektor = pair<int, int>;

int main(){
    tacka t1, t2;
    int a, b;
    cin >> a >> b;
    t1 = {a, b};
    cin >> a >> b;
    t2 = {a, b};

    vektor vektor1 = {t2.first - t1.first, t2.second - t1.second};

    int n;
    cin >> n;
    vector<tacka> arr(n);
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        arr[i].first = a;
        arr[i].second = b;
    }

    int counter = 0;

    // a c
    // b d

    for(int i = 0; i < n; i++){
        vektor vektor2 = {arr[i].first - t1.first, arr[i].second - t1.second};
        if(vektor1.first * vektor2.second - vektor1.second * vektor2.first == 0){
            counter++;
        }
    }
    cout << counter << '\n';



    return 0;
}