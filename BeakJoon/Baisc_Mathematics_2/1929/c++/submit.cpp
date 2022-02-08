#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n+1);

    for(int i = 0; i <= n; i++){
        v[i] = i;
    }

    for(int i = 2 i <= n; i++){
        for(int j = i*2; j <= n; j += i)
    }

    return 0;
}