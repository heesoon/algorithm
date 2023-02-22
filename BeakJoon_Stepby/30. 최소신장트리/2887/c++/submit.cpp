#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>
#include <cmath>

std::vector<int> vParents;

int doFind(int x){
    if(vParents[x] == x) return x;
    else return vParents[x] = doFind(vParents[x]);
}

bool doMerge(int a, int b){
    auto pa = doFind(a);
    auto pb = doFind(b);

    if(pa == pb) return false;
    else{
        vParents[pa] = pb;
        return true;
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int N, ans = 0;
    std::vector<std::tuple<int,int>> vX;
    std::vector<std::tuple<int,int>> vY;
    std::vector<std::tuple<int,int>> vZ;
    std::vector<std::tuple<int,int,int>> vPlanets;
    std::cin >> N;

    for(int i = 0; i < N; i++){
        vParents.push_back(i);
    }

    for(int i = 0; i < N; i++){
        int x, y, z;
        std::cin >> x >> y >> z;
        vX.push_back(std::make_tuple(x, i));
        vY.push_back(std::make_tuple(y, i));
        vZ.push_back(std::make_tuple(z, i));
    }

    std::sort(vX.begin(), vX.end());
    std::sort(vY.begin(), vY.end());
    std::sort(vZ.begin(), vZ.end());

    for(int i = 0; i < N-1; i++){
        auto xDiff = std::get<0>(vX[i+1]) - std::get<0>(vX[i]);
        auto yDiff = std::get<0>(vY[i+1]) - std::get<0>(vY[i]);
        auto zDiff = std::get<0>(vZ[i+1]) - std::get<0>(vZ[i]);

        vPlanets.push_back(std::make_tuple(xDiff, std::get<1>(vX[i+1]), std::get<1>(vX[i])));
        vPlanets.push_back(std::make_tuple(yDiff, std::get<1>(vY[i+1]), std::get<1>(vY[i])));
        vPlanets.push_back(std::make_tuple(zDiff, std::get<1>(vZ[i+1]), std::get<1>(vZ[i])));
    }

    std::sort(vPlanets.begin(), vPlanets.end());

    for(const auto &p : vPlanets){
        auto dist = std::get<0>(p);
        auto a = std::get<1>(p);
        auto b = std::get<2>(p);

        if(doMerge(a, b) == true) ans += dist;
    }

    std::cout << ans << "\n";
    return 0;
}