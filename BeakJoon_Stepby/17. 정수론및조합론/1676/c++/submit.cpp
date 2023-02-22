#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;

    int five = 0, two = 0;
    for(int i = 2; i <= n; i++){
        int temp = i;
        while(!(temp%5)){
            five++;
            temp /= 5;
        }

        temp = i;
        while(!(temp%2)){
            two++;
            temp /= 2;
        }
    }

    std::cout << std::min(five, two) << "\n";
    return 0;
}