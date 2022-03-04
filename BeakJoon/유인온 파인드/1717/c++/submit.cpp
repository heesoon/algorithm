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
    int pa = doFind(a);
    int pb = doFind(b);

    if(pa > pb) vParents[pa] = pb;
    else if(pa < pb) vParents[pb] = pa;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;

    for(int i = 0; i <= n; i++){
        vParents.push_back(i);
    }

    for(int i = 0; i < m; i++){
        int op, a, b;
        std::cin >> op >> a >> b;

        if(op == 0){
            doUnion(a, b);
        }
        else{
            if(doFind(a) == doFind(b)) std::cout << "YES\n";
            else std::cout << "NO\n";
        }
    }
    return 0;
}