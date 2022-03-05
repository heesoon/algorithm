#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int gcd(int a, int b){
    // a > b 전제가 성립해야 한다.
    // https://coding-factory.tistory.com/599
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::vector<int> v;
    std::vector<int> ans;
    std::cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    int max_gcd = v[1]-v[0];
    for(int i = 2; i < n; i++){
        // 세수 이상의 gcd 계산법 : https://ywpp.tistory.com/171
        max_gcd = gcd(max_gcd, v[i]-v[i-1]);
    }

    for(int i = 2; i*i <= max_gcd; i++){
        if(max_gcd%i == 0){
            ans.push_back(i);
            ans.push_back(max_gcd/i);
        }
    }
    ans.push_back(max_gcd);
    std::sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << " ";
    }
    return 0;
}