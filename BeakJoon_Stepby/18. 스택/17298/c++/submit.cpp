#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <limits>

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::stack<int> st;
    std::vector<int> v(n);
    std::vector<int> ans(n);
    
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        while(!st.empty() && v[st.top()] < v[i]){
            ans[st.top()] = v[i];
            st.pop();
        }

        st.push(i);
    }

    while(!st.empty()){
        int idx = st.top();
        st.pop();
        ans[idx] = -1;
    }

    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";
    return 0;
}

// https://suhwanc.tistory.com/58