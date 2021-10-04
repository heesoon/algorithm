#include <iostream>
#include <string>

const int N = 16;
char decompressed[N][N];

void fillColor(char color, int y, int x, int len){
    for(int dy = 0; dy < len; dy++){
        for(int dx = 0; dx < len; dx++){
            decompressed[y+dy][x+dx] = color;
        }
    }
}

void decompress(std::string &str, int y, int x, int len){
    char head = str.front();
    str = str.substr(1);
    if(head == 'w' || head == 'b'){
        fillColor(head, y, x, len);
        return;
    }
    else{
        int half = len/2;
        decompress(str, y, x, half);
        decompress(str, y, x+half, half);
        decompress(str, y+half, x, half);
        decompress(str, y+half, x+half, half);
    }
}

int main(){
    std::string str = "xxwwwbxwxwbbbwwxxxwwbbbwwwwbb";
    decompress(str, 0, 0, N);

    for(int y = 0; y < N; y++){
        for(int x = 0; x < N; x++){
            std::cout << decompressed[y][x] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}