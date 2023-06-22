#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using point = pair<int, int>;

int cross(point a, point b){
    return a.first * b.second - a.second * b.first;
}

point vec(point a, point b){
    return {b.first - a.first, b.second - a.second};
}

int orient(point a, point b, point c){
    return cross(vec(a, b), vec(a, c));
}

vector<point> makeSimple(vector<point>& points){
    vector<point> pol = points;
    swap(pol[0], *min_element(pol.begin(), pol.end()));
    sort(pol.begin() + 1, pol.end(), [&](point a, point b){
        return orient(pol[0], a, b) > 0;
    });

    return pol;
}

vector<int> grahamHull(vector<point>& p){

    swap(p[0], *min_element(p.begin(), p.end()));

    sort(p.begin() + 1, p.end(), [&](point a, point b){
        return orient(p[0], a, b) > 0;
    });

    vector<int> hull = {0};

    for(int i = 1; i < p.size(); i++){
        while(hull.size() > 1 && orient(p[hull[hull.size() - 2]],
                                        p[hull[hull.size() - 1]],
                                        p[i]) < 0)
                hull.pop_back();
        hull.push_back(i); 
    }

    return hull;
}



vector<int> grahamHullRedo(vector<point>& p){

    vector<int> hull = {0};
    swap(p[0], *min_element(p.begin(), p.end()));
    sort(p.begin() + 1, p.end(),[&](point a, point b){
        return orient(p[0], a, b) > 0;
    });

    for(int i = 1; i < p.size(); i++){
        while(hull.size() > 1 && orient(p[hull[hull.size() - 2]], p[hull[hull.size() - 1]], p[i]) < 0)
            hull.pop_back();
        hull.push_back(i);
    }

    return hull;
}