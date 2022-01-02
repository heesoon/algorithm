#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> DT;

int solve(int n){
    for(int i = 2; i <= n; i++){
        DT[i] = (DT[i-2] + DT[i-1]) % 15746;
    }

    return DT[n;
}

int main(){
    int n;
    std::cin >> n;

    DT.assign(n+1, 0);
    DT[0] = 1;
    DT[1] = 1;
    std::cout << solve(n) << "\n";

    return 0;
}