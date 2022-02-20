#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int n;
std::vector<int> inOrder;
std::vector<int> indexOrder;
std::vector<int> postOrder;

void solve(int inStart, int inEnd, int postStart, int postEnd){
    if(inStart > inEnd || postStart > postEnd) return;
    int root = postOrder[postEnd];
    int rootIdx = indexOrder[root];
    int leftSize = rootIdx-inStart;

    std::cout << root << " ";

    solve(inStart, rootIdx-1, postStart, postStart+leftSize-1);
    solve(rootIdx+1, inEnd, postStart+leftSize, postEnd-1);
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n;

    inOrder.assign(n+1, 0);
    postOrder.assign(n+1, 0);
    indexOrder.assign(n+1, 0);

    for(int i = 1; i <= n; i++){
        std::cin >> inOrder[i];
        indexOrder[inOrder[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        std::cin >> postOrder[i];
    }

    solve(1, n, 1, n);
    return 0;
}