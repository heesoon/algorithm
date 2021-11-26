#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m, n;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

bool isInMap(int y, int x){
    if((y >= 0 && y < m) && (x >= 0 && x < n)){
        return true;
    }

    return false;
}

void print(const std::vector<std::vector<int>> &map){
    for(const auto &y : map){
        for(const auto &x : y){
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
}

int solution(int y, int x, int cnt, std::vector<std::vector<int>> &map) {
    int c = 1;
    std::queue<std::vector<int>> Q;
    Q.push({y, x});
    map[y][x] = cnt;

    while(!Q.empty()){
        int y = Q.front()[0];
        int x = Q.front()[1];
        Q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(isInMap(ny, nx) && map[ny][nx] == 0){
                map[ny][nx] = cnt;
                c++;
                Q.push({ny, nx});
            }
        }
    }

    return c;
}

int main(){
    int cnt = 2, k;
    std::vector<int> rst;
    std::cin >> m >> n >> k;
    std::vector<std::vector<int>> map(m, std::vector<int>(n, 0));
    for(int i = 0; i < k; i++){
        int lx, ly, rx, ry;
        std::cin>> lx >> ly >> rx >> ry;

        for(int y = ly; y < ry; y++){
            for(int x = lx; x < rx; x++){
                map[y][x] = 1;
            }
        }
    }

    //print(map);

    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++ ){
            int depth = 0;
            if(map[y][x] == 0){
                depth = solution(y, x, cnt++, map);
                rst.push_back(depth);
            }
        }
    }

    std::sort(rst.begin(), rst.end(), std::less<int>());

    std::cout << cnt -2 << std::endl;
    for(const auto &d : rst){
        std::cout << d << " ";
    }
    std::cout << std::endl;

    return 0;
}