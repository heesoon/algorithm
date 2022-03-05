#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<int> P(n, 0);
    
    for(int i = 0; i < n; i++){
        std::cin >> P[i];
    }

    std::sort(P.begin(), P.end());

    std::vector<int> time(n, 0);
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += P[i];
        time[i] = sum;
    }

    sum = 0;
    for(int i = 0; i < n; i++){
        sum += time[i];
    }

    std::cout << sum << "\n";

    return 0;
}