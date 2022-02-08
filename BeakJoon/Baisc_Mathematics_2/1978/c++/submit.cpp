#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

bool solve(int n){
    if(n <= 1){
        return false;
    }

    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, cnt = 0;
    std::cin >> n;
    std::vector<int> v(n);

    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        if(solve(v[i]) == true){
            cnt++;
        }
    }

    std::cout << cnt << "\n";
    return 0;
}