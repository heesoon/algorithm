#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int A, B, V;
    std::cin >> A >> B >> V;

    int day = (V-B-1)/(A-B)+1;

    std::cout << day << "\n";

    return 0;
}