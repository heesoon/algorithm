#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> vParents;

int getFindParent(int x){
    if(vParents[x] == x) return x;
    else return vParents[x] = getFindParent(vParents[x]);
}

void doMerge(int a, int b){
    auto pa = getFindParent(a);
    auto pb = getFindParent(b);

    if(pa != pb){
        if(pa > pb){
            std::swap(pa, pb);
        }

        vParents[pa] = pb;
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int ans = 0;
    int V, E;
    std::cin >> V >> E;

    std::vector<std::tuple<int,int,int>> eLists;

    for(int i = 0; i <= V; i++){
        vParents.push_back(i);
    }

    for(int i = 0; i < E; i++){
        int a, b, c;
        std::cin >> a >> b >> c;
        eLists.push_back(std::make_tuple(c, a, b));
    }

    std::sort(eLists.begin(), eLists.end());

    for(auto p : eLists){
        auto a = std::get<1>(p);
        auto b = std::get<2>(p);
        auto c = std::get<0>(p);

        if(getFindParent(a) != getFindParent(b)){
            doMerge(a, b);
            ans += c;
        }
    }

    std::cout << ans << "\n";

    return 0;
}