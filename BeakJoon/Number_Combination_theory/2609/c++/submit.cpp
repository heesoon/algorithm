#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int a, b, c = 0;
    std::cin >> a >> b;

    int len = std::min(a, b);

    for(int i = len; i > 0; i--){
        if(a%i == 0 && b%i == 0){
            c = i;
            break;
        }
    }

    std::cout << c << "\n";
    std::cout << c*(a/c)*(b/c) << "\n";
    return 0;
}