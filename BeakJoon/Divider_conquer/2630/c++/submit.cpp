#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::pair<int,int> ans = {0, 0};
std::vector<std::vector<int>> map;

bool isSame(int y, int x, int len){
    for(int i = y; i < y+len; i++){
        for(int j = x; j < x+len; j++){
            if(map[y][x] != map[i][j]){
                return false;
            }
        }
    }

    return true;
}

void solve(int y, int x, int len){
    if(isSame(y, x, len) == true){
        if(map[y][x] == 0){
            ans.first += 1;
        }
        else{
            ans.second += 1;
        }

        return;
    }

    solve(y, x, len/2);
    solve(y, x+len/2, len/2);
    solve(y+len/2, x, len/2);
    solve(y+len/2, x+len/2, len/2);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    map.assign(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> map[i][j];
        }
    }

    solve(0, 0, n);

    std::cout << ans.first << "\n";
    std::cout << ans.second << "\n";
    return 0;
}