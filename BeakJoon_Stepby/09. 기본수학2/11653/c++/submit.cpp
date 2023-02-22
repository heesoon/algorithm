#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

//    for(int i = 2; i <= n; i++){
    for(int i = 2; i <= sqrt(n); i++){
        while(n%i == 0){
            std::cout << i << "\n";
            n /= i;
        }
    }

    if(n != 1){
        std::cout << n << "\n";
    }
    return 0;
}