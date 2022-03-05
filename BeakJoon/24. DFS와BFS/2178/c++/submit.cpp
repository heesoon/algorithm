#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>
#include <tuple>

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
std::vector<std::vector<int>> map;
std::vector<std::vector<bool>> visited(101, std::vector<bool>(101, false));

bool inRange(int y, int x){
    if((y >=0 && y < n) && (x >=0 && x < m)){
        return true;
    }
    return false;
}

int solve(int y, int x){
    int ans = std::numeric_limits<int>::max()/2;
    std::queue<std::tuple<int,int,int>> Q;
    Q.push(std::make_tuple(y, x, 1));

    while(!Q.empty()){
        int fy = std::get<0>(Q.front());
        int fx = std::get<1>(Q.front());
        int fd = std::get<2>(Q.front());
        Q.pop();
        for(int i = 0; i < 4; i++){
            int ny = dy[i]+fy;
            int nx = dx[i]+fx;
            int nd = fd+1;

            if(ny == n-1 && nx == m-1){
                ans = std::min(ans, nd);
                continue;
            }

            if(inRange(ny, nx) == true && map[ny][nx] == 1 && visited[ny][nx] == false){
                visited[ny][nx] = true;
                Q.push(std::make_tuple(ny, nx, nd));
            }
        }
    }

    return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n >> m;
    map.assign(n, std::vector<int>(m, 0));

    for(int y = 0; y < n; y++){
        std::string str;
        std::cin >> str;
        for(int x = 0; x < m; x++){
            map[y][x] = str[x] - '0';
        }
    }

    std::cout << solve(0, 0) << "\n";

    return 0;
}