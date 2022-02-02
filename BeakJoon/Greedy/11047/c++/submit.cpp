#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int n, k;
std::vector<int> value;

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n >> k;
    value.assign(n, 0);

    for(int i = 0; i < n; i++){
        std::cin >> value[i];
    }

    int i = n-1, cnt = 0;
    while(k > 0){
        while(k - value[i] >= 0){
            k -= value[i];
            cnt++;
        }
        i--;
    }

    std::cout << cnt << "\n";

    return 0;
}