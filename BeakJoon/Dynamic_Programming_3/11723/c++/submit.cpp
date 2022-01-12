#include <iostream>
#include <algorithm>
#include <bitset>
#include <limits>

const int N = 21;

int main(){
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int m;
    int n;
    std::string cmd;
    std::bitset<N> S;

    std::cin >> m;

    for(int i = 0; i < m; i++){
        std::cin >> cmd;

        if(cmd == "add"){
            std::cin >> n;
            S.set(n);
        }
        else if(cmd == "remove"){
            std::cin >> n;
            S.reset(n);
        }
        else if(cmd == "check"){
            std::cin >> n;
            std::cout << S.test(n) << "\n";
        }
        else if(cmd == "toggle"){
            std::cin >> n;
            S.flip(n);
        }
        else if(cmd == "all"){
            S.set();
        }
        else if(cmd == "empty"){
            S.reset();
        }
    }

    return 0;
}