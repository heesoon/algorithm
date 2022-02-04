#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    int a = 0, b = 0;
    for(int i = 2; i <= n; i++){
        if(i%2 == 0){
            a++;
        }

        if(i%5 == 0){
            b++;
        }
    }

    std::cout << std::min(a, b) << "\n";
    return 0;
}