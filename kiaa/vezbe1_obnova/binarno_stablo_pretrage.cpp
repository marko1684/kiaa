#include <iostream>
#include <queue>

using namespace std;

struct Cvor{
    Cvor(int v) : vr(v) { }

    int vr;
    Cvor* l = nullptr;
    Cvor* d = nullptr;
};

// dodaj (koren, vr)
Cvor* dodaj(Cvor* koren, int vr){
    if(koren == nullptr)
        return new Cvor(vr);
    
    if(vr < koren->vr){
        koren->l = dodaj(koren->l, vr);
    }
    else{
        koren->d = dodaj(koren->d, vr);
    }
    return koren;
}

void oslobodi(Cvor* koren){
    if(koren == nullptr){
        return;
    }
    oslobodi(koren->l);
    oslobodi(koren->d);
    delete koren;
}

void ispiti(Cvor* koren){
    bool ulevo = true;
    deque<Cvor*> q;

    q.push_front(koren);

    int velicinaNivoa = 1;

    while(!q.empty()){
        Cvor* t;
        if(ulevo){
            t = q.front();
            q.pop_front();
            if(t->l){
                q.push_back(t->l);
            }
            if(t->d){
                q.push_back(t->d);
            }
        }
        else{
            t = q.back();
            q.pop_back();
            if(t->d){
                q.push_front(t->d);
            }
            if(t->l){
                q.push_front(t->l);
            }
        }
        cout << t->vr << ' ';
        velicinaNivoa--;
    if(velicinaNivoa == 0){
        ulevo = !ulevo;
        velicinaNivoa = q.size();
        cout << '\n';
    }
    }
    
}

int main(){

    int n;
    cin >> n;

    Cvor* koren = nullptr;

    while(n--){
        int x;
        cin >> x;
        koren = dodaj(koren, x);

    }

    ispiti(koren);

    
    oslobodi(koren);
    return 0;
}