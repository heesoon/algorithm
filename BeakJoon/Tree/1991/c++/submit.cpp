#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

int n;
std::vector<std::pair<char,char>> Tree;

void preOrder(char node){
    if(node == '.') return;
    std::cout << node;
    preOrder(Tree[node - 'A'].first);
    preOrder(Tree[node - 'A'].second);
}

void inOrder(char node){
    if(node == '.') return;
    inOrder(Tree[node - 'A'].first);
    std::cout << node;
    inOrder(Tree[node - 'A'].second);
}

void postOrder(char node){
    if(node == '.') return;
    postOrder(Tree[node - 'A'].first);
    postOrder(Tree[node - 'A'].second);
    std::cout << node;
}

int main(){
    std::cin.tie(nullptr); std::cout.tie(nullptr); std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    Tree = std::vector<std::pair<char,char>>(n);

    for(int i = 0; i < n; i++){
        char parent, left, right;
        std::cin >> parent >> left >> right;
        Tree[parent - 'A'].first = left;
        Tree[parent - 'A'].second = right;
    }

    preOrder('A');
    std::cout << "\n";
    inOrder('A');
    std::cout << "\n";
    postOrder('A');
    
    return 0;
}