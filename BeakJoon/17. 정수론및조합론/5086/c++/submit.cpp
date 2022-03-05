#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    while(1){
        int a, b;
        std::cin >> a >> b;

        if(a == 0 && b == 0){
            break;
        }

        if(b%a == 0){
            std::cout << "factor" << "\n";
        }
        else if(a%b == 0){
            std::cout << "multiple" << "\n";
        }
        else{
            std::cout << "neither" << "\n";
        }
    }
    return 0;
}