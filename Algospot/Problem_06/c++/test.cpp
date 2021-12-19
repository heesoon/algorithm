#include <iostream>
#include <vector>

std::vector<char> comp;

int figure[16][16] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}            
};

bool isSame(int (*map)[16], int ys, int xs, int len)
{
    bool bSame = true;
    int data = map[ys][xs];
    for(int y = ys; y < ys+len; y++){
        for(int x = xs; x < xs+len; x++){
            if(data != map[y][x]){
                return false;
            }
        }
    }

    return bSame;
}

void compress(int (*map)[16], int y, int x, int len){
    if(isSame(map, y, x, len) == true){
        if(map[y][x] == 0)
            comp.push_back('w');
        else
            comp.push_back('b');

        return;
    }
    comp.push_back('x');
    compress(map, y, x, len/2);
    compress(map, y, x+len/2, len/2);
    compress(map, y+len/2, x, len/2);
    compress(map, y+len/2, x+len/2, len/2);
}

int main(){
    int cnt = 1;
    compress(figure, 0, 0, 16);
    for(auto &d : comp){
        std::cout << d;
        if(cnt % 5 == 0)
            std::cout << " ";
        cnt++;
    }
    std::cout << std::endl;
    return 0;
}