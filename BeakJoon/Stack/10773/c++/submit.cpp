#include <iostream>
#include <algorithm>
#include <utility>
#include <limits>
#include <stack>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int k, n;
    std::cin >> k;
    std::stack<int> st;
    for(int i = 0; i < k; i++){
        std::cin >> n;
        if(n == 0){
            st.pop();
        }
        else{
            st.push(n);
        }
    }

    int sum = 0;
    while(!st.empty()){
        int t = st.top();
        st.pop();
        sum += t;
    }

    std::cout << sum << "\n";
    return 0;
}