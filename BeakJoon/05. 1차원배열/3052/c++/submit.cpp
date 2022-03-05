#include <iostream>
#include <algorithm>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int ans = 0;
    std::vector<bool> vDivResult(43, false);

    for(int i = 1; i <= 10; i++){
        int x;
        std::cin >> x;
        vDivResult[x%42] = true;
    }

    for(auto r : vDivResult){
        if(r == true){
            ans++;
        }
    }

    std::cout << ans << "\n";

    return 0;
}