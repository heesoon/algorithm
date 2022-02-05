#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

long long solve(long long a, long long b, long long c){
    long long ans = 0;
    if(b == 1){
        return a%c;
    }
    else{
        long long t = solve(a, b/2, c);
        if(b%2 == 0){
            ans = (t*t)%c;
        }
        else{
            ans = ((t*t)%c*a)%c;
        }
    }

    return ans;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    long long a, b, c;
    std::cin >> a >> b >> c;

    std::cout << solve(a, b, c) << "\n";
    return 0;
}