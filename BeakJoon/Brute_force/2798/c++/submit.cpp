#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

const int N = 101;
std::vector<int> cards;
//std::vector<bool> visited;
//int ans = std::numeric_limits<int>::max()/2;
int ans = 0;

void solve(int cnt, int idx, int sum, int m, int n){
    if(cnt == 3){
        if(sum <= m && sum > ans){
            ans = sum;
        }
        return;
    }

    for(int i = idx; i < n; i++){
        //if(visited[i] == false){
        //    visited[i] = true;
            solve(cnt+1, i+1, sum+cards[i], m, n);
        //    visited[i] = false;
        //}
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, m;
    cards.assign(N, 0);
//    visited.assign(N, false);
    std::cin >> n >> m;
    for(int i = 0; i < n; i++){
        std::cin >> cards[i];
    }

    solve(0, 0, 0, m, n);

    std::cout << ans << "\n";
    return 0;
}