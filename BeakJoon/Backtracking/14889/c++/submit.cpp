#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

const int N = 21;
std::vector<std::vector<int>> S;
std::vector<bool> visited;

int solve(int idx, int cnt, int n){
    int ret = std::numeric_limits<int>::max()/2;

    if(cnt == n/2){
        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i] == true && visited[j] == true){
                    a += S[i][j];
                }

                if(visited[i] == false && visited[j] == false){
                    b += S[i][j];                   
                }
            }
        }
        return std::abs(a - b);
    }

    for(int i = idx; i < n; i++){
        if(visited[i] == false){
            visited[i] = true;
            ret = std::min(ret, solve(i+1, cnt+1, n));
            visited[i] = false;        
        }
    }

    return ret;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    S.assign(N, std::vector<int>(N, 0));
    visited.assign(N, false);

    std::cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> S[i][j];
        }
    }

    std::cout << solve(0, 0, n) << "\n";
    return 0;
}