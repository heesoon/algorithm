#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<int> v(n);

    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }

    for(int i = 1; i < n; i++){
        int max_gcd = gcd(v[0], v[i]);
        std::cout << v[0]/max_gcd << "/" << v[i]/max_gcd << "\n";
    }

    return 0;
}