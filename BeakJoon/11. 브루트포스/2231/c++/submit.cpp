#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

std::pair<int,int> getSum(int num){
    int cnt = 0, sum = 0;
    while(num){
        sum = sum + num%10;
        num /= 10;
        cnt++;
    }

    return std::make_pair(cnt, sum);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int ans = 0, n, range = 0;
    std::cin >> n;

    range = getSum(n).first * 9;

    for(int i = n-range; i < n; i++){
        if(i + getSum(i).second == n){
            ans = i;
            break;
        }
    }

    std::cout << ans << "\n";
    return 0;
}