#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<long long> distances(n, 0);
    std::vector<long long> prices(n, 0);

    for(int i = 0; i < n-1; i++){
        std::cin >> distances[i];
    }

    for(int i = 0; i < n; i++){
        std::cin >> prices[i];
    }

    long long price = std::numeric_limits<int>::max()/2;
    long long cost = 0;
    for(int i = 0; i < n-1; i++){
        price = std::min(price, prices[i]);
        cost += (price * distances[i]); 
    }

    std::cout << cost << "\n";

    return 0;
}