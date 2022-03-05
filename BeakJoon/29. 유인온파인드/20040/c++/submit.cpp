#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> vParents;

int doFind(int x){
    if(vParents[x] == x) return x;
    else return vParents[x] = doFind(vParents[x]); 
}

void doUnion(int a, int b){
    int pa = doFind(a);
    int pb = doFind(b);

    if(pa < pb){
        vParents[pb] = pa;
    }
    else{
        vParents[pa] = pb;
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, m, ans = 0;
    std::cin >> n >> m;

    vParents.assign(n, 0);
    for(int i = 0; i < n; i++){
        vParents[i] = i;
    }

    for(int i = 1; i <= m; i++){
        int a, b;
        std::cin >> a >> b;
        if(doFind(a) == doFind(b)){
            ans = i;
            break;
        }

        doUnion(a, b);
    }

    std::cout << ans << "\n";
    return 0;
}