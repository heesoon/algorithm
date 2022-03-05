#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

// 별 중요하지 않은 문제

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n, cnt = 0;
    std::cin >> n;
    std::vector<int> seq(n);
    std::stack<int> st;
    std::vector<char> ans;
    for(int i = 0; i < n; i++){
        std::cin >> seq[i];
    }

    for(int i = 1; i <= n; i++){
        st.push(i);
        ans.push_back('+');

        while(!st.empty() && st.top() == seq[cnt]){
            st.pop();
            ans.push_back('-');
            cnt++;
        }
    }

    if(!st.empty()) std::cout << "NO";
    else{
        for(int i = 0; i < ans.size(); i++){
            std::cout << ans[i] << "\n";
        }
    }
    return 0;
}