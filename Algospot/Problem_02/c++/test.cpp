#include <iostream>
#include <vector>

std::vector<int> tc = {2, 4, 6};
std::vector<std::vector<int>> friends = {
    {0, 1},
    {0, 1, 1, 2, 2, 3, 3, 0, 0, 2, 1, 3},
    {0, 1, 0, 2, 1, 2, 1, 3, 1, 4, 2, 3, 2, 4, 3, 4, 3, 5, 4, 5}
};

int friend_map[10][10];
int chk[2];

void initialize(int tidx){
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            friend_map[y][x] = 0;
        }
    }

    //std::cout << friends[tidx].size() << std::endl;
    for(int i = 0; i < friends[tidx].size(); i += 2){
        int y = friends[tidx][i];
        int x = friends[tidx][i+1];

        //std::cout << i << std::endl;
        friend_map[y][x] = friend_map[x][y] = 1;
    }

    chk[0] = chk[1] = 0;
    //std::cout << "out " << std::endl;
}

int f(int roof, int idx, int num){
    int r = 0;
    std::cout << roof << ", " << idx << ", " << num << std::endl;
    if(roof == 1){
        int y = chk[0];
        int x = idx;

        if(friend_map[y][x] == 1){
            std::cout << "if : " << roof << ", " << y << ", " << x << std::endl;
            return 1;
        }
        else{
            std::cout << "else : " << roof << ", " << y << ", " << x << std::endl;
            return 0;
        }
    }

    for(int i = idx + roof; i < num + idx - 1; i++){
        chk[roof] = i;
        r += f(roof+1, i+1, num);
        chk[roof] = 0;
    }
    return r;
}

int main(){
    int cnt = 0;
    int tidx = 2;
    initialize(tidx);

    cnt += f(0, 0, tc[tidx]);

    std::cout << cnt << std::endl;
    return 0;
}