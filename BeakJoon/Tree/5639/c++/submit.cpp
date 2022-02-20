#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

std::vector<int> tree;
void solve(int start, int end){
    if(start > end) return;
    if(start == end){
        std::cout << tree[start] << "\n";
        return;
    }

    int idx = start+1;
    while(idx <= end){
        if(tree[idx] > tree[start]) break;
        idx++;
    }

    solve(start+1, idx-1);
    solve(idx, end);
    std::cout << tree[start] << "\n";
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int num;
    while(std::cin >> num){
        tree.push_back(num);
    }

    solve(0, tree.size()-1);
    return 0;
}