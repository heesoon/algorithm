#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int m, n, k, cnt;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
std::vector<std::vector<int>> ground;

bool inRange(int y, int x){
    if((y >=0 && y < m) && (x >=0 && x < n)){
        return true;
    }
    return false;
}

int solve(int y, int x){
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int ny = dy[i]+y;
        int nx = dx[i]+x;
        if(inRange(ny, nx) == true && ground[ny][nx] == 1){
            ground[ny][nx] = cnt;
            ret += solve(ny, nx)+1;
        }
    }
    
    return ret;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int tc;
    std::cin >> tc;
    for(int i = 0; i < tc; i++){
        std::cin >> m >> n >> k;
        ground.assign(m, std::vector<int>(n, 0));
        for(int j = 0; j < k; j++){
            int y, x;
            std::cin >> y >> x;
            ground[y][x] = 1;
        }

        cnt = 2;
        for(int y = 0; y < m; y++){
            for(int x = 0; x < n; x++){
                if(ground[y][x] == 1){
                    ground[y][x] = cnt;
                    int r = solve(y, x)+1;
                    cnt++;
                }
            }
        }

        std::cout << cnt-2 << "\n";
        ground.clear();
    }
    return 0;
}