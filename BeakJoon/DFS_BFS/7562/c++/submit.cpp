#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <limits>

int l;
std::pair<int,int> S;
std::pair<int,int> T;

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool inRange(int y, int x){
    if((y >= 0 && y < l) && (x >= 0 && x < l)){
        return true;
    }
    return false;
}

int solve(){
    int ans = std::numeric_limits<int>::max()/2;
    std::queue<std::tuple<int,int,int>> Q;
    std::vector<std::vector<bool>> visited(l, std::vector<bool>(l, false));
    Q.push(std::make_tuple(S.second, S.first, 0));

    while(!Q.empty()){
        int fy = std::get<0>(Q.front());
        int fx = std::get<1>(Q.front());
        int fd = std::get<2>(Q.front());
        Q.pop();

        for(int i = 0; i < 8; i++){
            int ny = dy[i]+fy;
            int nx = dx[i]+fx;
            int nd = fd+1;

            if(inRange(ny, nx) == true){
                if(ny == T.second && nx == T.first){
                    ans = std::min(ans, nd);
                    continue;
                }
                
                if(visited[ny][nx] == false){
                    visited[ny][nx] = true;
                    Q.push(std::make_tuple(ny, nx, nd));
                }
            }
        }
    }

    return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int tc;
    std::cin >> tc;
    for(int i = 0; i < tc; i++){
        int x, y;
        std::cin >> x >> y;
        S.first = x, S.second = y;
        std::cin >> x >> y;
        T.first = x, T.second = y;

        if(S == T) std::cout << "0\n";
        else std::cout << solve() << "\n";
    }
    return 0;
}