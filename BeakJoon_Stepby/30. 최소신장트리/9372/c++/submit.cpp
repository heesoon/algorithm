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
        int N, M;
        std::cin >> N >> M;

        for(int i = 0; i < M; i++){
            int a, b;
            std::cin >> a >> b;
        }

        std::cout << N-1 << "\n";
    }

    return 0;
}