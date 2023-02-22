#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::pair<long long, long long> getCount(long long n){
    long long five = 0, two = 0;
    for(long long i = 2; i <= n; i*=2){
        two += n/i;
    }

    for(long long i = 5; i <= n; i*=5){
        five += n/i;
    }

    return std::make_pair(five, two);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    long long n, m, five = 0, two = 0;
    std::cin >> n >> m;

    auto nNum = getCount(n);
    auto mNum = getCount(m);
    auto dNum = getCount(n-m);

    five = nNum.first - mNum.first - dNum.first;
    two = nNum.second - mNum.second - dNum.second;

    std::cout << std::min(five, two) << "\n";
    return 0;
}