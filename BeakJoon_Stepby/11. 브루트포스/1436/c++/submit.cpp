#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, count = 0;
    std::cin >> n;

    for(int i = 1; i <= std::numeric_limits<int>::max(); i++){
        std::string numString = std::to_string(i);
        if(numString.find("666") != std::string::npos){
            count++;
            if(count == n){
                std::cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}