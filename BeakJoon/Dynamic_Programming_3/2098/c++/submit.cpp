#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int n;
std::vector<std::vector<int>> W;
std::vector<std::vector<int>> DT;
int solve(int idx, int visited){
    if(visited == (1 << n) - 1){
        if(W[idx-1][0] != 0){
            return W[idx-1][0];
        }

        return std::numeric_limits<int>::max()/2;
    }
    
    int &ret = DT[idx][visited];
    if(ret != -1) return ret;

    ret = std::numeric_limits<int>::max()/2;
    for(int i = 0; i < n; i++){
        if(visited & (1 << i) || W[idx][i] == 0) continue;

        ret = std::min(ret, solve(idx+1, visited | (1 << i)) + W[idx][i]);
    }

    return ret;
}

int main(){
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    std::cin >> n;

    W.assign(n, std::vector<int>(n, 0));
    DT.assign(n, std::vector<int>(1 << n, -1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> W[i][j];
        }
    }

    std::cout << solve(0, 1) << "\n";

    return 0;
}

// https://mapocodingpark.blogspot.com/2020/03/BOJ-2098.html