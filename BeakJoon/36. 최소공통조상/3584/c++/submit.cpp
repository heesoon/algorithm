#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int T;
    std::cin >> T;

    while(T--){
        int N;
        std::cin >> N;

        std::vector<int> vParents(N+1);
        std::vector<int> vVisted(N+1, false);

        for(int i = 0; i <= N; i++){
            vParents[i] = i;
        }

        for(int i = 0; i < N-1; i++){
            int a, b;
            std::cin >> a >> b;
            vParents[b] = a;
        }

        int u, v;
        std::cin >> u >> v;
        vVisted[u] = true;

        while(u != vParents[u]){
            u = vParents[u];
            vVisted[u] = true;
        }

        while(1){
            if(vVisted[v] == true){
                std::cout << v << "\n";
                break;
            }

            v = vParents[v];
        }

        vParents.clear();
        vVisted.clear();    
    }
    return 0;
}

// reference : https://cocoon1787.tistory.com/506