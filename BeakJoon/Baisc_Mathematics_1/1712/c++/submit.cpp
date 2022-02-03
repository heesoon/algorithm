#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int A, B, C;
    std::cin >> A >> B >> C;

    if(B >= C){
        std::cout << -1 << "\n";
    }
    else{
        std::cout << A/(C-B)+1 << "\n";
    }

    return 0;
}