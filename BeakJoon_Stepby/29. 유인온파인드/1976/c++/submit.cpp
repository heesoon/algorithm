#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> vParents;

int doFind(int a){
    if(vParents[a] == a) return a;
    return vParents[a] = doFind(vParents[a]);
}

void doUnion(int a, int b){
#if 0    
    int pa = doFind(a);
    int pb = doFind(b);

    if(pa > pb) vParents[pa] = pb;
    else if(pa < pb) vParents[pb] = pa;
#else
    int pa = doFind(a);
    int pb = doFind(b);

    if(pa == pb) return;
    vParents[pa] = pb;
#endif
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;

    for(int i = 0; i <= n; i++){
        vParents.push_back(i);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int bconnected;
            std::cin >> bconnected;
            if(bconnected == 1){
                doUnion(i, j);
            }
        }
    }

    int firstVistingCity;
    std::cin >> firstVistingCity;
    int parent = doFind(firstVistingCity);
    bool isConnect = true;
    for(int i = 1; i < m; i++){
        int vistingCity;
        std::cin >> vistingCity;
        if(parent != doFind(vistingCity)){
            isConnect = false;
        }
    }

    if(isConnect == false) std::cout << "NO\n";
    else std::cout << "YES\n";

    return 0;
}