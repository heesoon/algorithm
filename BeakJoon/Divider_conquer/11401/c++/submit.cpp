#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

const long long DIV = 1'000'000'007;

long long factorial(long long n){
    long long ans = 1;
    for(long long i = 1; i <= n; i++){
        ans *= i;
        ans %= DIV;
    }

    return ans;
}

long long cpower(long long base, long long power){
    if(power == 1){
        return base%DIV;
    }
    else{
        long long t = cpower(base, power/2);
        if(power%2 == 0){
            return (t*t)%DIV;
        }
        else{
            return ((t*t)%DIV*base)%DIV;
        }
    }
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    long long n, k;
    std::cin >> n >> k;
    long long numerator = factorial(n);
    long long denominator = (factorial(k)*factorial(n-k))%DIV;
    denominator = cpower(denominator, DIV - 2);

    std::cout << (numerator*denominator)%DIV << "\n";
    return 0;
}