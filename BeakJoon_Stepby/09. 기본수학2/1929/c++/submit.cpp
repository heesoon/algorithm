#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> m >> n;
    std::vector<int> v(n+1, 0);

    for(int i = 2; i <= n; i++){
        v[i] = i;
    }

    for(int i = 2; i <= std::sqrt(n); i++){
    //for(int i = 2; i <= n; i++){
        if(v[i] == 0) continue;

        for(int j = i*i; j <= n; j += i){
            v[j] = 0;
        }
    }

    for(int i = m; i <= n; i++){
        if(v[i] != 0){
            std::cout << v[i] << "\n";
        }
    }

    return 0;
}