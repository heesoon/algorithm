#include <iostream>
#include <vector>

using namespace std;

bool isSame(int y, int x, int l, int v, const std::vector<std::vector<int>> &map){
    bool bSame = true;

    for(int i = y; i < y+l; i++){
        for(int j = x; j < x+l; j++){
            if(v != map[i][j]){
                return false;
            }
        }
    }

    return bSame;
}

int solution(int y, int x, int l, int v, const std::vector<std::vector<int>> &map) {
    if(l == 1){
        return map[y][x] == v;
    }

    if(isSame(y, x, l, v, map)){
        return 1;
    }

    return solution(y, x, l/2, v, map) + solution(y, x+l/2, l/2, v, map) + solution(y+l/2, x, l/2, v, map) + solution(y+l/2, x+l/2, l/2, v, map);  
}

void tc1(){
    int l = 8;
    std::vector<std::vector<int>> map{
        {1, 1, 0, 0, 0, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 1, 1, 1, 1, 1}
    };

    if(solution(0, 0, l, 0, map) == 9 && solution(0, 0, l, 1, map) == 7){
        std::cout << "Success" << std::endl;
    }
    else{
        std::cout << "Fail" << std::endl;
    }
}

int main(){
    tc1();
    return 0;
}