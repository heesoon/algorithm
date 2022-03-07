#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
std::vector<std::vector<int>> vtMap;
std::vector<std::vector<int>> vMap;
std::vector<int> vParents;
std::vector<std::tuple<int,int,int>> vDist;

bool isRange(int y, int x){
    if((y >= 0 && y < N) && (x >= 0 && x < M)) return true;
    else return false;
}

void numberingMap(int y, int x, int c){
    for(int i = 0; i < 4; i++){
        int ny = dy[i]+y;
        int nx = dx[i]+x;

        if(isRange(ny, nx) == true && vtMap[ny][nx] == 1){
            vtMap[ny][nx] = c;
            vMap[ny][nx] = vtMap[ny][nx]-1;
            numberingMap(ny, nx, c);
        }
    }
}

void printMap(){
    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            std::cout << vMap[y][x] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void calcDist(int idx, int y, int x){
    for(int i = 0; i < 4; i++){
        int dist = 0;
        int ny = y;
        int nx = x;

        while(1){
            ny += dy[i];
            nx += dx[i];

            if(isRange(ny, nx) == false || vMap[ny][nx] == idx) break;

            if(vMap[ny][nx] != 0){
                vDist.push_back(std::make_tuple(dist, idx, vMap[ny][nx]));
                break;
            }
            dist++;
        }
    }
}

int doFind(int x){
    if(vParents[x] == x) return x;
    else return vParents[x] = doFind(vParents[x]);
}

bool doUnion(int a, int b){
    auto pa = doFind(a);
    auto pb = doFind(b);

    if(pa == pb) return false;
    else{
        vParents[pa] = pb;
        return true;
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int cnt = 2, ans = 0;
    std::cin >> N >> M;

    vMap.assign(N, std::vector<int>(M, 0));
    vtMap.assign(N, std::vector<int>(M, 0));

    for(int i = 0; i <= N; i++){
        vParents.push_back(i);
    }

    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            std::cin >> vtMap[y][x];
        }
    }

    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            if(vtMap[y][x] == 1){
                vtMap[y][x] = cnt;
                vMap[y][x] = vtMap[y][x]-1;
                numberingMap(y, x, cnt);
                cnt++;
            }
        }
    }
    vtMap.clear();
    //printMap();

    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            if(vMap[y][x] != 0) calcDist(vMap[y][x], y, x);
        }
    }
    std::sort(vDist.begin(), vDist.end());

    for(const auto &p : vDist){
        auto dist = std::get<0>(p);
        auto a = std::get<1>(p);
        auto b = std::get<2>(p);

        if(dist < 2) continue;

        if(doUnion(a, b) == true){
            ans += dist;
        }
    }

    // check all connections
    auto root = doFind(1);
    for(auto i = 2; i < cnt-1; i++){
        if(root != doFind(i)){
            ans = -1;
        }
    }

    std::cout << ans << "\n";

    return 0;
}