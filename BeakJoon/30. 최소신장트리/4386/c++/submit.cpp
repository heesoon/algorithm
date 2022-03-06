#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <cmath>

std::vector<int> vParents;
std::vector<std::tuple<double,double>> vCoords;
std::vector<std::tuple<double,int,int>> vStars;

int doFind(int x){
    if(vParents[x] == x) return x;
    else return vParents[x] = doFind(vParents[x]);
}

void doMerge(int a, int b){
    auto pa = doFind(a);
    auto pb = doFind(b);

    if(pa != pb){
        if(pa > pb){
            std::swap(pa, pb);
        }
        vParents[pa] = pb;
    }
}

double getDistance(double y1, double x1, double y2, double x2){
    double xSqure = std::pow(x2-x1, 2);
    double ySqure = std::pow(y2-y1, 2);

    return std::sqrt(xSqure+ySqure);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    double ans = 0;
    std::cin >> n;

    for(int i = 0; i <= n; i++){
        vParents.push_back(i);
    }

    vCoords.push_back(std::make_tuple(0.0, 0.0));
    for(int i = 0; i < n; i++){
        double x, y;
        std::cin >> x >> y;
        vCoords.push_back(std::make_tuple(x, y));
    }

    for(int i = 1; i <= n-1; i++){
        for(int j = i+1; j <= n; j++){
            auto y1 = std::get<1>(vCoords[i]);
            auto y2 = std::get<1>(vCoords[j]);
            auto x1 = std::get<0>(vCoords[i]);
            auto x2 = std::get<0>(vCoords[j]);
            auto dist = getDistance(y1, x1, y2, x2);
            vStars.push_back(std::make_tuple(dist, i, j));
        }
    }

    std::sort(vStars.begin(), vStars.end());

    for(auto p : vStars){
        auto a = std::get<1>(p);
        auto b = std::get<2>(p);
        auto dist = std::get<0>(p);

        if(doFind(a) != doFind(b)){
            doMerge(a, b);
            ans += dist;
        }
    }

    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << ans << "\n";
    return 0;
}